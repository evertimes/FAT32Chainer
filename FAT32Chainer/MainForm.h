#pragma once
#include <Windows.h>
#include <HtmlHelp.h>
#include <WinUser.h>
#include <string>
#include <iostream>
#include <filesystem>
#include <msclr\marshal_cppstd.h>
#include <thread>
#include "threadsFunctions.h"
#include <fstream>



namespace FAT32Chainer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —‚Ó‰Í‡ ‰Îˇ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			
		}

	protected:
		/// <summary>
		
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ Ù‡ÈÎToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ COpenFile;
	private: System::Windows::Forms::ToolStripMenuItem^ CCloseFile;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^ CExit;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::HelpProvider^ helpProvider1;
	private: System::Windows::Forms::ToolStripMenuItem^ CSaveFile;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;

	private:
		/// <summary>
		String^ openedFile;
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->Ù‡ÈÎToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->COpenFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CSaveFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CCloseFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->CExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->helpProvider1 = (gcnew System::Windows::Forms::HelpProvider());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->dataGridView1);
			this->groupBox1->Location = System::Drawing::Point(12, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(361, 314);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Cluster number chain";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(9, 19);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(345, 20);
			this->textBox3->TabIndex = 1;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(9, 45);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(346, 262);
			this->dataGridView1->TabIndex = 0;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Previous cluster number";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Current cluster number";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Next cluster number";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->Ù‡ÈÎToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(379, 24);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// Ù‡ÈÎToolStripMenuItem
			// 
			this->Ù‡ÈÎToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->COpenFile,
					this->CSaveFile, this->CCloseFile, this->toolStripSeparator1, this->CExit
			});
			this->Ù‡ÈÎToolStripMenuItem->Name = L"Ù‡ÈÎToolStripMenuItem";
			this->Ù‡ÈÎToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->Ù‡ÈÎToolStripMenuItem->Text = L"‘‡ÈÎ";
			// 
			// COpenFile
			// 
			this->COpenFile->Name = L"COpenFile";
			this->COpenFile->Size = System::Drawing::Size(223, 22);
			this->COpenFile->Text = L"ŒÚÍ˚Ú¸";
			this->COpenFile->Click += gcnew System::EventHandler(this, &MainForm::COpenFile_Click);
			// 
			// CSaveFile
			// 
			this->CSaveFile->AutoToolTip = true;
			this->CSaveFile->Enabled = false;
			this->CSaveFile->Name = L"CSaveFile";
			this->CSaveFile->Size = System::Drawing::Size(223, 22);
			this->CSaveFile->Text = L"—Óı‡ÌËÚ¸ ˆÂÔÓ˜ÍÛ ‚ Ù‡ÈÎ";
			this->CSaveFile->Click += gcnew System::EventHandler(this, &MainForm::CSaveClick);
			// 
			// CCloseFile
			// 
			this->CCloseFile->Enabled = false;
			this->CCloseFile->Name = L"CCloseFile";
			this->CCloseFile->Size = System::Drawing::Size(223, 22);
			this->CCloseFile->Text = L"«‡Í˚Ú¸";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(220, 6);
			// 
			// CExit
			// 
			this->CExit->Name = L"CExit";
			this->CExit->Size = System::Drawing::Size(223, 22);
			this->CExit->Text = L"¬˚ıÓ‰";
			this->CExit->Click += gcnew System::EventHandler(this, &MainForm::CExit_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(379, 349);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"FAT32 Chainer";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->KeyPreview = true;
	}
	
	 //œÓÎÛ˜ÂÌËÂ ÌÓÏÂ‡ ÔÂ‚Ó„Ó ÍÎ‡ÒÚÂ‡
	long long getFirstClusterNum(const wchar_t* path) {
		   std::wstring path2 = path;
		   std::wstring prefix = L"\\\\.\\";
		   path2 = prefix.append(path2.substr(0, 2));
		   HANDLE h = CreateFile(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		   byte* buf = (byte*)malloc(512);
		   unsigned char name[8];
		   BY_HANDLE_FILE_INFORMATION descriptor;
		   GetFileInformationByHandle(h, &descriptor);
		   DWORD lowIndex = descriptor.nFileIndexLow;
		   CloseHandle(h);

		   DWORD dwRead;
		   HANDLE hDisk = CreateFile(path2.c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, 0, OPEN_EXISTING, FILE_ATTRIBUTE_READONLY, 0);
		   if (hDisk == INVALID_HANDLE_VALUE) 
		   {
			   CloseHandle(hDisk);
			   return -1;
		   }
		   int sectorNum = lowIndex / 512;
		   int sectorOffset = lowIndex % 512;
		   SetFilePointer(hDisk, sectorNum * 512, 0, FILE_BEGIN); 
		   long long* clusterNum = (long long*) malloc(sizeof(long long));
		   (*clusterNum) = 0;
		   unsigned char numclust[4];
		   ReadFile(hDisk, buf, 512, &dwRead, 0);  
		   memcpy(numclust + 2, buf + sectorOffset + 20, 2);
		   memcpy(numclust, buf + sectorOffset + 26, 2);
		   memcpy(clusterNum, numclust, 4);
		   return *clusterNum;
	   }

	   BOOL DirectoryExists(LPCTSTR szPath) 
	   {
		   DWORD dwAttrib = GetFileAttributes(szPath);

		   return (dwAttrib != INVALID_FILE_ATTRIBUTES && ((dwAttrib & FILE_ATTRIBUTE_DIRECTORY) || (dwAttrib & FILE_ATTRIBUTE_ARCHIVE)));
	   }
	   void printClusterChain() { 
		   dataGridView1->Rows->Clear();
		   long clusterChain[512];
		   std::vector<long> chain;
		   String^ path = openedFile;
		   std::string stdPath = msclr::interop::marshal_as<std::string>(path);
		   std::wstring wpath = msclr::interop::marshal_as<std::wstring>(path);
		   if (!DirectoryExists(wpath.c_str())) {
			   MessageBox::Show("File not exists", "Error");
			   return;
		   }
		   long number = getFirstClusterNum(wpath.c_str());
		   if (number == -1) {
			   MessageBox::Show("Failed to open disk, check administrator privilegies", "Error");
			   return;
		   }
		   std::thread t2(getClusterChain, number,&chain,wpath.substr(0,2));
		   t2.join();
		   int i = 1;
		   while (chain[i] != 0x0fffffff) {
			   dataGridView1->Rows->Add(chain[i - 1].ToString("X"), chain[i].ToString("X"), chain[i + 1].ToString("X"));
			   i++;
		   }
		   dataGridView1->Rows->Add(chain[i - 1].ToString("X"), chain[i].ToString("X"), "End of chain");
	   }
private: System::Void COpenFile_Click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		openedFile = openFileDialog1->FileName;
		textBox3->Text = openedFile;
		std::string stdPath = msclr::interop::marshal_as<std::string>(openedFile->ToString());
		char fsName[10] = "";
		stdPath = stdPath.substr(0, 2);
		stdPath = stdPath.append("\\");
		GetVolumeInformationA(stdPath.c_str(), 0, 0, 0, 0, 0, fsName, sizeof(fsName));
		if (strcmp(fsName,"FAT32")!=0) {
			MessageBox::Show("That disk is not FAT32", "Error");
		}
		else {
			printClusterChain();
			CCloseFile->Enabled = true;
			CSaveFile->Enabled = true;
		}
	}
	
}
private: System::Void CChain_Click(System::Object^ sender, System::EventArgs^ e) {
	printClusterChain();
	CSaveFile->Enabled = true;
}

private: System::Void CExit_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}

private: System::Void CSaveClick(System::Object^ sender, System::EventArgs^ e) {
	std::string stdPath = msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName);
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		std::ofstream file(stdPath);
		file << "Prev." << '\t' << "Current" << '\t' << "Next" << '\n';
		for (int i = 0; i < dataGridView1->Rows->Count - 1; i++) {
			std::string prev = msclr::interop::marshal_as<std::string>(dataGridView1->Rows[i]->Cells[0]->Value->ToString());
			std::string cur = msclr::interop::marshal_as<std::string>(dataGridView1->Rows[i]->Cells[1]->Value->ToString());
			std::string next = msclr::interop::marshal_as<std::string>(dataGridView1->Rows[i]->Cells[2]->Value->ToString());
			file << prev << '\t' << cur << '\t' << next << '\n';
		}
	}
}
};
}
