#pragma once

#include<iostream>
#include<string>
#include<vector>


using namespace std;
using namespace System;

class TranslatorClass
{
private:
	bool isFile{ false };
	bool* isProcessing, * processResult;
	string* processMessage;

	string sourceFileOrFolderName, licensePath, sourceLang, destinationLang;
	string aStrSourceLanguages[7]{ "Chinese (simplified)", "English", "German", "Italian", "Russian", "Estonian", "Turkish" };
	string workingDirectoryName{ "temp" }, credentialFileName{ "crt.txt" };
	string pythonFileName{ "" };

	bool readAndResolveAllFiles(void);
	bool createCredentialFile(void);
	bool createCommentFile(string tempfileName, string sourceFileName);
	bool createNewTranslatedFile(string temFileName, string sourceFileName);
	bool createNewDirectory(void);
	bool runPython(void);
	void runningThreadFunction(void);


public:
	TranslatorClass(bool* isProc = nullptr, bool* result = nullptr, string* message = nullptr, string sp = "", string lp = "", string sl = "", string dl = "", bool isf = false) :
		sourceFileOrFolderName(sp), licensePath(lp), sourceLang(sl), destinationLang(dl), isFile(isf)
	{
		isProcessing	= isProc;
		processResult	= result;
		processMessage  = message;

		if (isProcessing != nullptr)   *isProcessing = true;
		if (processMessage != nullptr) *processMessage = "Starting file translate...";
		if (processResult != nullptr)  *processResult = false;
	}

	static void MarshalString(System::String^ s, std::string& os);
	static void MarshalString(System::String^ s, std::wstring& os);
	bool getSupportedLanguages(vector<string>& languagesList);
	bool run();

	~TranslatorClass()
	{

	}
};

