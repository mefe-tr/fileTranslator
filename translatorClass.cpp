#include "translatorClass.h"
#include<iostream>
#include<string>
#include<thread>
#include<filesystem>
#include<fstream>
#include<sstream>

#ifdef _DEBUG
#undef _DEBUG
#include<Python.h>
#define _DEBUG
#else
#include<Python.h>
#endif


bool TranslatorClass::getSupportedLanguages(vector<string>& languagesList) {
	try
	{
		Py_Initialize();

		PyObject* pName, * pModule, * pFunc, * pArgs, * pValue;

		PyObject* sysPath = PySys_GetObject((char*)"path");
		PyList_Append(sysPath, PyUnicode_FromString("."));
		sysPath = PySys_GetObject((char*)"path");

		pName = PyUnicode_FromString((char*)"pyTranslator"); //File name
		pModule = PyImport_Import(pName);
		Py_XDECREF(pName);

		pFunc = PyObject_GetAttrString(pModule, (char*)"getSupportedLanguages"); //Function Name
		Py_XDECREF(pModule);

		pArgs = PyTuple_Pack(1, PyUnicode_FromString((char*)""));
		pValue = PyObject_CallObject(pFunc, pArgs);
		Py_XDECREF(pArgs);

		string result = _PyUnicode_AsString(pValue);
		Py_XDECREF(pValue);

		size_t pos = 0;
		while ((pos = result.find(',')) != string::npos) {
			languagesList.push_back(result.substr(0, pos));
			result.erase(0, pos + 1);
		}

		//Close the python instance
		Py_Finalize();

		return true;
	}
	catch (const std::exception&)
	{
		for each (string lang in aStrSourceLanguages)
		{
			languagesList.push_back(lang);
		}
		return false;
	}
}
bool TranslatorClass::runPython(void) {

	try
	{
		Py_Initialize();

		PyObject* pName, * pModule, * pFunc, * pArgs, * pValue, * pFileName;

		PyObject* sysPath = PySys_GetObject((char*)"path");
		PyList_Append(sysPath, PyUnicode_FromString("."));
		sysPath = PySys_GetObject((char*)"path");

		pName = PyUnicode_FromString((char*)"pyTranslator"); //File name
		pModule = PyImport_Import(pName);
		Py_XDECREF(pName);

		pFunc = PyObject_GetAttrString(pModule, (char*)"translateDeepTranslator_text"); //Function Name
		Py_XDECREF(pModule);

		pFileName = PyUnicode_DecodeLatin1(pythonFileName.c_str(), strlen(pythonFileName.c_str()), "");
		pArgs = PyTuple_Pack(3, pFileName, PyUnicode_FromString(sourceLang.c_str()), PyUnicode_FromString(destinationLang.c_str()));
		pValue = PyObject_CallObject(pFunc, pArgs);
		Py_XDECREF(pArgs);

		string result = _PyUnicode_AsString(pValue);
		Py_XDECREF(pValue);

		//Close the python instance
		Py_Finalize();

		bool returnValue = ( result.compare("OK") >= 0 || std::strstr(result.c_str(), "OK") != 0) ? true : false;
		return returnValue;
	}
	catch (const std::exception&)
	{
		return false;
	}
}
bool TranslatorClass::createCommentFile(string fileName)
{
	try
	{
		string tempFileName = workingDirectoryName + "\\" + fileName + ".txt";
		pythonFileName = tempFileName;

		fstream readFile, writeFile;
		readFile.open(sourceFileName.c_str(), ios::in);
		writeFile.open(tempFileName.c_str(), ios::out);

		if (!(writeFile.is_open() && readFile.is_open()))
		{
			if (writeFile.is_open()) writeFile.close();
			if (readFile.is_open()) readFile.close();

			return false;
		}

		string tp;
		unsigned long lineCount{ 0 };

		while (getline(readFile, tp)) {

			lineCount++;
			auto pos = tp.find("//");
			if (pos != std::string::npos) //is there any comment
			{
				writeFile << lineCount << "," << tp.substr(pos) << endl;
			}
		}


		//Close all opened files
		if (writeFile.is_open()) writeFile.close();
		if (readFile.is_open()) readFile.close();

		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}

}
bool TranslatorClass::createCredentialFile(void)
{
	try
	{
		string fileName = workingDirectoryName + "\\" + credentialFileName;
		fstream writeFile(fileName.c_str(), ios::out);

		if (!writeFile.is_open()) return false;

		writeFile << licensePath << endl;

		writeFile.close();

		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}
bool TranslatorClass::createNewTranslatedFile(string temFileName) {
	try
	{
		string translatedFileName = workingDirectoryName + "\\_" + temFileName + ".txt";
		string copySourceFileName = filesystem::path(sourceFileName.c_str()).parent_path().string() + "\\old_" + filesystem::path(sourceFileName.c_str()).filename().string();
		string tempFileName = filesystem::path(sourceFileName.c_str()).parent_path().string() + "\\temp_" + filesystem::path(sourceFileName.c_str()).filename().string();


		fstream readTranslatedCommentFile, sourceFile, tempWriteFile;
		readTranslatedCommentFile.open(translatedFileName.c_str(), ios::in);
		sourceFile.open(sourceFileName.c_str(), ios::in);
		tempWriteFile.open(tempFileName.c_str(), ios::out);


		if (!(sourceFile.is_open() && readTranslatedCommentFile.is_open() && tempWriteFile.is_open()))
		{
			if (sourceFile.is_open()) sourceFile.close();
			if (readTranslatedCommentFile.is_open()) readTranslatedCommentFile.close();
			if (tempWriteFile.is_open()) tempWriteFile.close();

			return false;
		}

		auto split = [](string s, char delim) { // Manuel text splitter
			std::stringstream sstream(s);
			std::string item;
			std::vector<std::string> itemList;

			while (std::getline(sstream, item, delim))
			{
				itemList.push_back(item);
			}

			return itemList;
		};

		string sourceFileData, readFileData;
		bool isAvailableComment = false, isReadTranslatedComment = true;;
		unsigned long lineCount{ 0 };
		std::vector<std::string> splitText;
		unsigned long translatedLineCount = 0;

		while (getline(sourceFile, sourceFileData)) { // read source file data line by line

			if (isReadTranslatedComment) // is it ready to read new translated comment line
			{
				isReadTranslatedComment = false; // lock reading translated comment as every source code read
				isAvailableComment = false; // reset available flag

				if (getline(readTranslatedCommentFile, readFileData)) { // read translated file data

					splitText = split(readFileData, ','); // split translated comment as line count and comment
					translatedLineCount = stoul(splitText[0]); // get lineCount from translated file
					isAvailableComment = true; // if there is a translated comment, set available active flag

				}
			}

			if (isAvailableComment) // is there any new translated comment line?
			{
				lineCount++;
				auto pos = sourceFileData.find("//");
				if (pos != std::string::npos) //is there any comment
				{
					if (translatedLineCount == lineCount)
					{
						string pureString = sourceFileData.erase(pos);
						string newLine = pureString + splitText[1];
						tempWriteFile << newLine << endl;

						isReadTranslatedComment = true;
					}
				}
				else
				{
					tempWriteFile << sourceFileData << endl;
				}
			}
			else
			{
				lineCount++;
				tempWriteFile << sourceFileData << endl;
			}
		}

		if (sourceFile.is_open()) sourceFile.close();
		if (readTranslatedCommentFile.is_open()) readTranslatedCommentFile.close();
		if (tempWriteFile.is_open()) tempWriteFile.close();

		if (filesystem::exists(copySourceFileName)) filesystem::remove(copySourceFileName.c_str()); //Firstly, is being deleted existed old file
		filesystem::copy_file(sourceFileName.c_str(), copySourceFileName.c_str()); //Second, is being created new old file

		filesystem::remove(sourceFileName.c_str()); // remove source file
		filesystem::rename(tempFileName.c_str(), sourceFileName.c_str()); //renamed tempFile

		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}
bool TranslatorClass::readAndResolveAllFiles(void)
{
	try
	{
		bool returnResult{ false };
		if (isFile) //if it is a file, the code will be executed for only one file
		{
			*processStep = 1;

			if (!filesystem::exists(sourceFileName))
			{
				return false;
			}

			if (!createCommentFile("1")) return false;
			if (!runPython()) return false;
			if (!createNewTranslatedFile("1")) return false;

			return true;
		}
		else // Folder
		{
			return true;
		}
	}
	catch (const std::exception&)
	{
		return false;
	}
}
bool TranslatorClass::createNewDirectory(void)
{
	try
	{
		if (filesystem::is_directory(workingDirectoryName))
			filesystem::remove_all(workingDirectoryName);

		filesystem::create_directory(workingDirectoryName);

		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}

	return filesystem::is_directory(workingDirectoryName);
}

void TranslatorClass::runningThreadFunction(void) {
	try
	{
		if (!createNewDirectory())
		{
			*processResult = false;
			*isProcessing = false;
			return;
		}
		bool returnValue = readAndResolveAllFiles();
		filesystem::remove_all(workingDirectoryName);

		*processResult = returnValue;
		*isProcessing = false;
	}
	catch (const std::exception&)
	{
		try
		{
			if (filesystem::is_directory(workingDirectoryName))
				filesystem::remove_all(workingDirectoryName);
		}
		catch (const std::exception&)
		{

		}

		*processResult = false;
		*isProcessing  = false;
	}
}


bool TranslatorClass::run()
{
	try
	{
		*isProcessing = true;
		*processStep = 0;
		*processResult = false;

		std::thread th( &TranslatorClass::runningThreadFunction, this );
		th.join();

		return true;
	}
	catch (const std::exception&)
	{
		if(isProcessing != nullptr)*isProcessing = false;
		if (processResult != nullptr)*processResult = false;

		return false;
	}
}

void TranslatorClass::MarshalString(String^ s, std::string& os) {
	using namespace System::Runtime::InteropServices;
	const char* chars =
		(const char*)(void*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}
void TranslatorClass::MarshalString(System::String^ s, std::wstring& os) {
	using namespace System::Runtime::InteropServices;
	const wchar_t* chars =
		(const wchar_t*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}