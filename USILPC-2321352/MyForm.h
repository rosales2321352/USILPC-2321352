#pragma once
#include "Text.h"
#include <msclr/marshal_cppstd.h>
using namespace msclr::interop;

namespace USILPC2321352 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TextBox^ tbxOcr;
	protected:

	private: System::Windows::Forms::PictureBox^ bimage;
	private: System::Windows::Forms::Button^ btnObtenOCR;


	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Button^ btnBuscarImagen;
	private: System::Windows::Forms::TextBox^ tbxRutaImagen;


	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tbxOcr = (gcnew System::Windows::Forms::TextBox());
			this->bimage = (gcnew System::Windows::Forms::PictureBox());
			this->btnObtenOCR = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->btnBuscarImagen = (gcnew System::Windows::Forms::Button());
			this->tbxRutaImagen = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bimage))->BeginInit();
			this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->AutoScroll = true;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->tbxOcr, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->bimage, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->btnObtenOCR, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 36);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.458599F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 95.5414F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1010, 628);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tbxOcr
			// 
			this->tbxOcr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbxOcr->Location = System::Drawing::Point(508, 31);
			this->tbxOcr->Multiline = true;
			this->tbxOcr->Name = L"tbxOcr";
			this->tbxOcr->Size = System::Drawing::Size(499, 594);
			this->tbxOcr->TabIndex = 0;
			// 
			// bimage
			// 
			this->bimage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->bimage->Location = System::Drawing::Point(3, 31);
			this->bimage->Name = L"bimage";
			this->bimage->Size = System::Drawing::Size(499, 594);
			this->bimage->TabIndex = 1;
			this->bimage->TabStop = false;
			// 
			// btnObtenOCR
			// 
			this->btnObtenOCR->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnObtenOCR->Location = System::Drawing::Point(508, 3);
			this->btnObtenOCR->Name = L"btnObtenOCR";
			this->btnObtenOCR->Size = System::Drawing::Size(499, 22);
			this->btnObtenOCR->TabIndex = 2;
			this->btnObtenOCR->Text = L"Obtener OCR";
			this->btnObtenOCR->UseVisualStyleBackColor = true;
			this->btnObtenOCR->Click += gcnew System::EventHandler(this, &MyForm::btnObtenOCR_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->flowLayoutPanel1->Controls->Add(this->btnBuscarImagen);
			this->flowLayoutPanel1->Controls->Add(this->tbxRutaImagen);
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(505, 28);
			this->flowLayoutPanel1->TabIndex = 3;
			// 
			// btnBuscarImagen
			// 
			this->btnBuscarImagen->Location = System::Drawing::Point(3, 3);
			this->btnBuscarImagen->Name = L"btnBuscarImagen";
			this->btnBuscarImagen->Size = System::Drawing::Size(75, 23);
			this->btnBuscarImagen->TabIndex = 0;
			this->btnBuscarImagen->Text = L"Buscar";
			this->btnBuscarImagen->UseVisualStyleBackColor = true;
			this->btnBuscarImagen->Click += gcnew System::EventHandler(this, &MyForm::btnBuscarImagen_Click);
			// 
			// tbxRutaImagen
			// 
			this->tbxRutaImagen->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbxRutaImagen->Location = System::Drawing::Point(81, 5);
			this->tbxRutaImagen->Margin = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->tbxRutaImagen->Name = L"tbxRutaImagen";
			this->tbxRutaImagen->ReadOnly = true;
			this->tbxRutaImagen->Size = System::Drawing::Size(421, 20);
			this->tbxRutaImagen->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(15, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1004, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"OBTENER OCR DE UNA IMAGEN";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1034, 676);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tableLayoutPanel1);
			this->MaximumSize = System::Drawing::Size(1050, 715);
			this->MinimumSize = System::Drawing::Size(1050, 715);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bimage))->EndInit();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnBuscarImagen_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
		openFileDialog->Filter = "Archivos de imagen|*.jpg;*.png;*.jpeg";
		openFileDialog->Title = "Selecciona una imagen";

		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ imagePath = openFileDialog->FileName;
			tbxRutaImagen->Text = imagePath;

			bimage->Image = Image::FromFile(imagePath);
			bimage->SizeMode = PictureBoxSizeMode::StretchImage;
		}
	}
	private: System::Void btnObtenOCR_Click(System::Object^ sender, System::EventArgs^ e) {
		string texto = GetOCR();
		tbxOcr->Text = marshal_as<System::String^>(texto);
	}
};
}
