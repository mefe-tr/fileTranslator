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
	int* processStep;

	string sourceFileName, licensePath, sourceLang, destinationLang;
	string aStrSourceLanguages[7]{ "Chinese (simplified)", "English", "German", "Italian", "Russian", "Estonian", "Turkish" };
	string workingDirectoryName{ "temp" }, credentialFileName{ "crt.txt" };
	string pythonFileName{ "" };

	bool readAndResolveAllFiles(void);
	bool createCredentialFile(void);
	bool createCommentFile(string tempFileName);
	bool createNewTranslatedFile(string temFileName);
	bool createNewDirectory(void);
	bool runPython(void);
	void runningThreadFunction(void);


public:
	TranslatorClass(bool* isProc = nullptr, bool* result = nullptr, int* step = nullptr, string sp = "", string lp = "", string sl = "", string dl = "", bool isf = false) :
		sourceFileName(sp), licensePath(lp), sourceLang(sl), destinationLang(dl), isFile(isf)
	{
		isProcessing	= isProc;
		processResult	 = result;
		processStep		= step;

		if (isProcessing != nullptr) *isProcessing = true;
		if (processStep != nullptr) *processStep = 0;
		if (processResult != nullptr) *processResult = false;
	}

	static void MarshalString(System::String^ s, std::string& os);
	static void MarshalString(System::String^ s, std::wstring& os);
	bool getSupportedLanguages(vector<string>& languagesList);
	bool run();

	~TranslatorClass()
	{

	}
};

