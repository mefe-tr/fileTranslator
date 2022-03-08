#pragma once
//#include<Windows.h>
//#include<WinInet.h>

#include <exception>
#include <string>
#include <stdio.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <array>
#include "translatorClass.h"

//#pragma comment(lib,"Wininet.lib")

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ tb_path;
	private: System::Windows::Forms::Label^ lb_path;


	private: System::Windows::Forms::Label^ lb_pathBrowser;
	private: System::Windows::Forms::ComboBox^ cb_oLanguage;

	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ cb_tLanguage;
	private: System::Windows::Forms::RadioButton^ rb_file;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::RadioButton^ rb_folder;
	private: System::Windows::Forms::PictureBox^ pb_close;
	private: System::Windows::Forms::PictureBox^ pb_start;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog;

	private: //Users
		System::String^ strFolderPath{ "" };
		System::String^ strFilePath{ "" };
		System::String^ strLicensePath{ "" };
		System::String^ strRadioChecked{ "File" };
		bool* isProcessing = new bool{ false };
		bool* processResult = new bool{ false };
		string* processMessage	= new string{ "" };
		string* prevMessage		= new string{ "starting..." };

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::TextBox^ tb_licensePath;
	private: System::Windows::Forms::Label^ lb_licensePathBrowser;



	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckBox^ cb_LicenseActive;
	private: System::Windows::Forms::Label^ lb_Info;

	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::PictureBox^ pb_info;
	private: System::ComponentModel::IContainer^ components;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lb_Info = (gcnew System::Windows::Forms::Label());
			this->cb_LicenseActive = (gcnew System::Windows::Forms::CheckBox());
			this->pb_start = (gcnew System::Windows::Forms::PictureBox());
			this->pb_info = (gcnew System::Windows::Forms::PictureBox());
			this->pb_close = (gcnew System::Windows::Forms::PictureBox());
			this->rb_folder = (gcnew System::Windows::Forms::RadioButton());
			this->rb_file = (gcnew System::Windows::Forms::RadioButton());
			this->cb_tLanguage = (gcnew System::Windows::Forms::ComboBox());
			this->cb_oLanguage = (gcnew System::Windows::Forms::ComboBox());
			this->tb_licensePath = (gcnew System::Windows::Forms::TextBox());
			this->tb_path = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lb_licensePathBrowser = (gcnew System::Windows::Forms::Label());
			this->lb_pathBrowser = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lb_path = (gcnew System::Windows::Forms::Label());
			this->folderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_start))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_info))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_close))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::FloralWhite;
			this->groupBox1->Controls->Add(this->lb_Info);
			this->groupBox1->Controls->Add(this->cb_LicenseActive);
			this->groupBox1->Controls->Add(this->pb_start);
			this->groupBox1->Controls->Add(this->pb_info);
			this->groupBox1->Controls->Add(this->pb_close);
			this->groupBox1->Controls->Add(this->rb_folder);
			this->groupBox1->Controls->Add(this->rb_file);
			this->groupBox1->Controls->Add(this->cb_tLanguage);
			this->groupBox1->Controls->Add(this->cb_oLanguage);
			this->groupBox1->Controls->Add(this->tb_licensePath);
			this->groupBox1->Controls->Add(this->tb_path);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->lb_licensePathBrowser);
			this->groupBox1->Controls->Add(this->lb_pathBrowser);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->lb_path);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(704, 225);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// lb_Info
			// 
			this->lb_Info->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lb_Info->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->lb_Info->Location = System::Drawing::Point(122, 181);
			this->lb_Info->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->lb_Info->Name = L"lb_Info";
			this->lb_Info->Padding = System::Windows::Forms::Padding(3);
			this->lb_Info->Size = System::Drawing::Size(514, 21);
			this->lb_Info->TabIndex = 8;
			this->lb_Info->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// cb_LicenseActive
			// 
			this->cb_LicenseActive->AutoSize = true;
			this->cb_LicenseActive->Enabled = false;
			this->cb_LicenseActive->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->cb_LicenseActive->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->cb_LicenseActive->Location = System::Drawing::Point(544, 122);
			this->cb_LicenseActive->Name = L"cb_LicenseActive";
			this->cb_LicenseActive->Size = System::Drawing::Size(128, 20);
			this->cb_LicenseActive->TabIndex = 7;
			this->cb_LicenseActive->Text = L"License Active";
			this->cb_LicenseActive->UseVisualStyleBackColor = true;
			// 
			// pb_start
			// 
			this->pb_start->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pb_start->Location = System::Drawing::Point(644, 165);
			this->pb_start->Name = L"pb_start";
			this->pb_start->Size = System::Drawing::Size(48, 48);
			this->pb_start->TabIndex = 6;
			this->pb_start->TabStop = false;
			this->pb_start->Click += gcnew System::EventHandler(this, &Form1::pb_start_Click);
			// 
			// pb_info
			// 
			this->pb_info->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pb_info->Location = System::Drawing::Point(66, 165);
			this->pb_info->Name = L"pb_info";
			this->pb_info->Size = System::Drawing::Size(48, 48);
			this->pb_info->TabIndex = 5;
			this->pb_info->TabStop = false;
			this->pb_info->Click += gcnew System::EventHandler(this, &Form1::pb_info_Click);
			// 
			// pb_close
			// 
			this->pb_close->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pb_close->Location = System::Drawing::Point(12, 165);
			this->pb_close->Name = L"pb_close";
			this->pb_close->Size = System::Drawing::Size(48, 48);
			this->pb_close->TabIndex = 5;
			this->pb_close->TabStop = false;
			this->pb_close->Click += gcnew System::EventHandler(this, &Form1::pb_close_Click);
			// 
			// rb_folder
			// 
			this->rb_folder->AutoSize = true;
			this->rb_folder->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->rb_folder->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->rb_folder->Location = System::Drawing::Point(214, 122);
			this->rb_folder->Name = L"rb_folder";
			this->rb_folder->Size = System::Drawing::Size(71, 20);
			this->rb_folder->TabIndex = 5;
			this->rb_folder->Text = L"Folder";
			this->rb_folder->UseVisualStyleBackColor = true;
			// 
			// rb_file
			// 
			this->rb_file->AutoSize = true;
			this->rb_file->Checked = true;
			this->rb_file->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->rb_file->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->rb_file->Location = System::Drawing::Point(157, 122);
			this->rb_file->Name = L"rb_file";
			this->rb_file->Size = System::Drawing::Size(51, 20);
			this->rb_file->TabIndex = 4;
			this->rb_file->TabStop = true;
			this->rb_file->Text = L"File";
			this->rb_file->UseVisualStyleBackColor = true;
			this->rb_file->CheckedChanged += gcnew System::EventHandler(this, &Form1::rb_file_CheckedChanged);
			// 
			// cb_tLanguage
			// 
			this->cb_tLanguage->BackColor = System::Drawing::Color::Black;
			this->cb_tLanguage->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cb_tLanguage->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->cb_tLanguage->ForeColor = System::Drawing::Color::NavajoWhite;
			this->cb_tLanguage->FormattingEnabled = true;
			this->cb_tLanguage->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"English", L"German", L"Italian", L"Russian",
					L"Spanish", L"Turkish"
			});
			this->cb_tLanguage->Location = System::Drawing::Point(497, 83);
			this->cb_tLanguage->Name = L"cb_tLanguage";
			this->cb_tLanguage->Size = System::Drawing::Size(175, 26);
			this->cb_tLanguage->TabIndex = 3;
			// 
			// cb_oLanguage
			// 
			this->cb_oLanguage->BackColor = System::Drawing::Color::Black;
			this->cb_oLanguage->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cb_oLanguage->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->cb_oLanguage->ForeColor = System::Drawing::Color::NavajoWhite;
			this->cb_oLanguage->FormattingEnabled = true;
			this->cb_oLanguage->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Chinese", L"English", L"German", L"Italian",
					L"Russian", L"Spanish", L"Turkish"
			});
			this->cb_oLanguage->Location = System::Drawing::Point(157, 85);
			this->cb_oLanguage->Name = L"cb_oLanguage";
			this->cb_oLanguage->Size = System::Drawing::Size(175, 26);
			this->cb_oLanguage->TabIndex = 2;
			// 
			// tb_licensePath
			// 
			this->tb_licensePath->BackColor = System::Drawing::Color::WhiteSmoke;
			this->tb_licensePath->CausesValidation = false;
			this->tb_licensePath->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->tb_licensePath->ForeColor = System::Drawing::Color::DimGray;
			this->tb_licensePath->Location = System::Drawing::Point(157, 21);
			this->tb_licensePath->Name = L"tb_licensePath";
			this->tb_licensePath->ReadOnly = true;
			this->tb_licensePath->Size = System::Drawing::Size(515, 25);
			this->tb_licensePath->TabIndex = 0;
			this->tb_licensePath->Text = L"Not Necessary To Fill";
			// 
			// tb_path
			// 
			this->tb_path->BackColor = System::Drawing::Color::WhiteSmoke;
			this->tb_path->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->tb_path->ForeColor = System::Drawing::Color::DimGray;
			this->tb_path->Location = System::Drawing::Point(157, 52);
			this->tb_path->Name = L"tb_path";
			this->tb_path->Size = System::Drawing::Size(515, 25);
			this->tb_path->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label3->ForeColor = System::Drawing::Color::Maroon;
			this->label3->Location = System::Drawing::Point(348, 88);
			this->label3->Margin = System::Windows::Forms::Padding(3, 10, 3, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(143, 16);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Translate Laguage :";
			// 
			// lb_licensePathBrowser
			// 
			this->lb_licensePathBrowser->AutoSize = true;
			this->lb_licensePathBrowser->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lb_licensePathBrowser->Enabled = false;
			this->lb_licensePathBrowser->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lb_licensePathBrowser->ForeColor = System::Drawing::Color::Maroon;
			this->lb_licensePathBrowser->Location = System::Drawing::Point(680, 26);
			this->lb_licensePathBrowser->Margin = System::Windows::Forms::Padding(5);
			this->lb_licensePathBrowser->Name = L"lb_licensePathBrowser";
			this->lb_licensePathBrowser->Size = System::Drawing::Size(19, 16);
			this->lb_licensePathBrowser->TabIndex = 1;
			this->lb_licensePathBrowser->Text = L"...";
			this->lb_licensePathBrowser->Click += gcnew System::EventHandler(this, &Form1::lb_licensePathBrowser_Click);
			// 
			// lb_pathBrowser
			// 
			this->lb_pathBrowser->AutoSize = true;
			this->lb_pathBrowser->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lb_pathBrowser->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lb_pathBrowser->ForeColor = System::Drawing::Color::Maroon;
			this->lb_pathBrowser->Location = System::Drawing::Point(680, 57);
			this->lb_pathBrowser->Margin = System::Windows::Forms::Padding(5);
			this->lb_pathBrowser->Name = L"lb_pathBrowser";
			this->lb_pathBrowser->Size = System::Drawing::Size(19, 16);
			this->lb_pathBrowser->TabIndex = 1;
			this->lb_pathBrowser->Text = L"...";
			this->lb_pathBrowser->Click += gcnew System::EventHandler(this, &Form1::lb_pathBrowser_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label4->ForeColor = System::Drawing::Color::Maroon;
			this->label4->Location = System::Drawing::Point(17, 122);
			this->label4->Margin = System::Windows::Forms::Padding(3, 10, 3, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(120, 16);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Translation Type";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->ForeColor = System::Drawing::Color::Maroon;
			this->label2->Location = System::Drawing::Point(17, 88);
			this->label2->Margin = System::Windows::Forms::Padding(3, 10, 3, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 16);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Original Laguage";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label5->ForeColor = System::Drawing::Color::Maroon;
			this->label5->Location = System::Drawing::Point(17, 26);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(97, 16);
			this->label5->TabIndex = 0;
			this->label5->Text = L"License Path";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label6->ForeColor = System::Drawing::Color::Maroon;
			this->label6->Location = System::Drawing::Point(140, 26);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(11, 16);
			this->label6->TabIndex = 0;
			this->label6->Text = L":";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label9->ForeColor = System::Drawing::Color::Maroon;
			this->label9->Location = System::Drawing::Point(139, 122);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(11, 16);
			this->label9->TabIndex = 0;
			this->label9->Text = L":";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label8->ForeColor = System::Drawing::Color::Maroon;
			this->label8->Location = System::Drawing::Point(139, 88);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(11, 16);
			this->label8->TabIndex = 0;
			this->label8->Text = L":";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label7->ForeColor = System::Drawing::Color::Maroon;
			this->label7->Location = System::Drawing::Point(139, 90);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(11, 16);
			this->label7->TabIndex = 0;
			this->label7->Text = L":";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->ForeColor = System::Drawing::Color::Maroon;
			this->label1->Location = System::Drawing::Point(139, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(11, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L":";
			// 
			// lb_path
			// 
			this->lb_path->AutoSize = true;
			this->lb_path->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lb_path->ForeColor = System::Drawing::Color::Maroon;
			this->lb_path->Location = System::Drawing::Point(17, 57);
			this->lb_path->Name = L"lb_path";
			this->lb_path->Size = System::Drawing::Size(72, 16);
			this->lb_path->TabIndex = 0;
			this->lb_path->Text = L"File Path ";
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog1";
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Form1::backgroundWorker1_RunWorkerCompleted);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(704, 225);
			this->ControlBox = false;
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"File Translator";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_start))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_info))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_close))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void splitContainer1_Panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pb_close_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {

		try
		{
			this->pb_close->Image = System::Drawing::Image::FromFile("close.png");
			this->pb_start->Image = System::Drawing::Image::FromFile("startProcess.png");
			this->pb_info->Image = System::Drawing::Image::FromFile("info.png");
			this->tb_path->Text = "";

			vector<string> languagesList;
			TranslatorClass translator;
			translator.getSupportedLanguages(languagesList);

			if (languagesList.size() > 0)
			{
				this->cb_oLanguage->Items->Clear();
				this->cb_tLanguage->Items->Clear();

				for each (string lang in languagesList)
				{
					this->cb_oLanguage->Items->Add(gcnew System::String(lang.c_str()));
					this->cb_tLanguage->Items->Add(gcnew System::String(lang.c_str()));
				}
			}

			this->cb_oLanguage->SelectedIndex = 0;
			this->cb_tLanguage->SelectedIndex = 0;

			this->groupBox1->Select();
		}
		catch (const std::exception&)
		{

		}

	}
	private: System::Void lb_pathBrowser_Click(System::Object^ sender, System::EventArgs^ e) {

		try
		{
			if (this->rb_folder->Checked)
			{
				try
				{
					folderBrowserDialog->SelectedPath = (strFolderPath->Trim() == System::String::Empty) ? System::Environment::GetFolderPath(System::Environment::SpecialFolder::MyDocuments) : strFolderPath->Trim();
				}
				catch (const std::exception&)
				{
					folderBrowserDialog->SelectedPath = System::Environment::GetFolderPath(System::Environment::SpecialFolder::MyDocuments);
				}


				if (folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					strFolderPath = folderBrowserDialog->SelectedPath->Trim();
					this->tb_path->Text = strFolderPath;
				}
			}
			else
			{
				openFileDialog->FileName = "";
				openFileDialog->Filter = "All Files (*.*)|*.*";
				openFileDialog->FilterIndex = 1;
				try
				{
					openFileDialog->InitialDirectory = (strFilePath->Trim() != System::String::Empty) ? strFilePath->Trim() : System::Environment::GetFolderPath(System::Environment::SpecialFolder::MyDocuments);
				}
				catch (const std::exception&)
				{
					openFileDialog->InitialDirectory = System::Environment::GetFolderPath(System::Environment::SpecialFolder::MyDocuments);
				}

				if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					strFilePath = openFileDialog->FileName->Trim();
					this->tb_path->Text = strFilePath;
				}
			}
		}
		catch (const std::exception&)
		{
			strFilePath = "";
			this->tb_path->Text = "";
		}
	}
	private: System::Void lb_licensePathBrowser_Click(System::Object^ sender, System::EventArgs^ e) {

		try
		{
			openFileDialog->FileName = "";
			openFileDialog->Filter = "JSON Files (*.json)|*.json";
			openFileDialog->FilterIndex = 1;
			try
			{
				openFileDialog->InitialDirectory = (strLicensePath->Trim() != System::String::Empty) ? strLicensePath->Trim() : System::Environment::GetFolderPath(System::Environment::SpecialFolder::MyDocuments);
			}
			catch (const std::exception&)
			{
				openFileDialog->InitialDirectory = System::Environment::GetFolderPath(System::Environment::SpecialFolder::MyDocuments);
			}

			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				strLicensePath = openFileDialog->FileName->Trim();
				this->tb_licensePath->Text = strLicensePath;
			}
		}
		catch (const std::exception&)
		{
			strLicensePath = "";
			this->tb_licensePath->Text = "";
		}
	}
	private: System::Void rb_file_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->tb_path->Text = "";
		if (rb_file->Checked)
		{
			lb_path->Text = "File Path";
			strRadioChecked = "File";
		}
		else
		{
			lb_path->Text = "Folder Path";
			strRadioChecked = "Folder";
		}
	}
	private: bool checkInternetConnection(void) {
		try
		{

			std::string checkSite = "https://www.google.com/";
			//return InternetCheckConnectionA(checkSite.c_str(), FLAG_ICC_FORCE_CONNECTION, 0);
			return true;
		}
		catch (const std::exception&)
		{
			return false;
		}
	}
	private: bool checkCrediantials(std::string& path, std::string& license) {
		try
		{
			if (this->cb_LicenseActive->Checked)
			{
				if (this->tb_licensePath->Text == System::String::Empty)
				{
					System::Windows::Forms::MessageBox::Show(
						"License Path Cannot Be Blank!\n\nFor more detail, please go : https://console.cloud.google.com/flows/enableapi?apiid=translate.googleapis.com ",
						"ERROR",
						System::Windows::Forms::MessageBoxButtons::OK,
						System::Windows::Forms::MessageBoxIcon::Error);


					return false;
				}
				else
				{
					strLicensePath = this->tb_licensePath->Text->Trim();
					TranslatorClass::MarshalString(strLicensePath, license);

					if (!(filesystem::exists(license)))
					{
						System::Windows::Forms::MessageBox::Show(
							"License file is not found! Please select a proper filename",
							"ERROR",
							System::Windows::Forms::MessageBoxButtons::OK,
							System::Windows::Forms::MessageBoxIcon::Error);
						return false;
					}
				}
			}
			if (this->tb_path->Text == System::String::Empty)
			{
				System::Windows::Forms::MessageBox::Show(
					strRadioChecked + "path cannot be blank!",
					"ERROR",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);

				return false;
			}
			else
			{
				if (rb_file->Checked)
				{
					strFilePath = this->tb_path->Text->Trim();
					TranslatorClass::MarshalString(strFilePath, path);

					if (!(filesystem::exists(path)))
					{
						System::Windows::Forms::MessageBox::Show(
							"File is not found! Please select a proper filename",
							"ERROR",
							System::Windows::Forms::MessageBoxButtons::OK,
							System::Windows::Forms::MessageBoxIcon::Error);
						return false;
					}
				}
				else
				{
					strFolderPath = this->tb_path->Text->Trim();

					TranslatorClass::MarshalString(strFolderPath, path);
					if (!filesystem::is_directory(path))
					{
						System::Windows::Forms::MessageBox::Show(
							"Folder path is not exist! Please select a proper folder path",
							"ERROR",
							System::Windows::Forms::MessageBoxButtons::OK,
							System::Windows::Forms::MessageBoxIcon::Error);
						return false;
					}
				}

			}

			if (!checkInternetConnection())
			{
				System::Windows::Forms::MessageBox::Show(
					"No internet connection. Please check internet connections.",
					"ERROR",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
				return false;
			}

			return true;
		}
		catch (const std::exception& ex)
		{
			System::Windows::Forms::MessageBox::Show(
				gcnew System::String(ex.what()),
				"ERROR",
				System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Error);

			return false;
		}
	}
	private: System::Void pb_start_Click(System::Object^ sender, System::EventArgs^ e) {

		std::string fileName, license{ "" }, sourceLang{ "ch-CN" }, destinationLang{ "en-US" };

		if (checkCrediantials(fileName, license))
		{
			TranslatorClass::MarshalString(cb_oLanguage->SelectedItem->ToString(), sourceLang);
			TranslatorClass::MarshalString(cb_tLanguage->SelectedItem->ToString(), destinationLang);

			if (!this->cb_LicenseActive->Checked) license = "";

			*isProcessing = false; *processResult = false;
			*processMessage = "Starting file translate...";
			*prevMessage    = "starting...";
			this->lb_Info->Text = "Starting file translate...";
			this->lb_Info->Update();

			TranslatorClass translate(isProcessing, processResult, processMessage, fileName, license, sourceLang, destinationLang, rb_file->Checked);

			backgroundWorker1->RunWorkerAsync();

			bool returnValue = translate.run();
		}
		else
		{
			this->lb_Info->Text = "";
		}
	}

	private: delegate void UpdateInfoLabelUpdateDelegate(System::String^ message);
	private: void updateInfoLabel(System::String^ message)
	{
		this->lb_Info->Text = message;
		this->lb_Info->Update();
		System::Threading::Thread::Sleep(500);
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {

		try
		{
			while (1)
			{
				if (*isProcessing)
				{
					if ( (*processMessage).compare((* prevMessage).c_str()) < 0)
					{
						*prevMessage = *processMessage;

						UpdateInfoLabelUpdateDelegate^ action = gcnew UpdateInfoLabelUpdateDelegate(this, &Form1::updateInfoLabel);
						this->BeginInvoke(action, gcnew String((*processMessage).c_str()));
					}
				}
				else 
				{ //Finish background worker
					break;
				}
			}
		}
		catch (const std::exception&)
		{
			
		}

	}
private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {

	try
	{

		if (*processResult) //is finish successfully?
		{
			this->lb_Info->Text = gcnew String((*processMessage).c_str());
		}
		else
		{
			this->lb_Info->Text = gcnew String((*processMessage).c_str());
		}

		this->lb_Info->Update();

	}
	catch (const std::exception&)
	{
			
	}
}
private: System::Void pb_info_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::MessageBox::Show(
		"This project is designed by Mefe in March 2022\nYou can use the project to translate comments that is in C/C++ and header files.\n"+
		"The project only supports comment lines starting with '//'.\nThe project is an open source project that's why everybody can redesign it for yourself.",
		"INFO",
		System::Windows::Forms::MessageBoxButtons::OK,
		System::Windows::Forms::MessageBoxIcon::Information);
}
};
}