#pragma once
#include "Game.h"
#include "PreguntasM.h"
namespace JuegoTF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmMenu
	/// </summary>
	public ref class frmMenu : public System::Windows::Forms::Form
	{
	public:
		frmMenu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnIniciar;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnPreguntas;







	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMenu::typeid));
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnPreguntas = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnIniciar
			// 
			this->btnIniciar->BackColor = System::Drawing::Color::Transparent;
			this->btnIniciar->Font = (gcnew System::Drawing::Font(L"Pixeboy", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnIniciar->ForeColor = System::Drawing::Color::White;
			this->btnIniciar->Location = System::Drawing::Point(52, 595);
			this->btnIniciar->Margin = System::Windows::Forms::Padding(4);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(215, 75);
			this->btnIniciar->TabIndex = 0;
			this->btnIniciar->Text = L"Iniciar";
			this->btnIniciar->UseVisualStyleBackColor = false;
			this->btnIniciar->Click += gcnew System::EventHandler(this, &frmMenu::btnIniciar_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Pixeboy", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(87, 105);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(720, 66);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Math Warriors";
			// 
			// btnPreguntas
			// 
			this->btnPreguntas->BackColor = System::Drawing::Color::Transparent;
			this->btnPreguntas->Font = (gcnew System::Drawing::Font(L"Pixeboy", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPreguntas->ForeColor = System::Drawing::Color::White;
			this->btnPreguntas->Location = System::Drawing::Point(674, 591);
			this->btnPreguntas->Name = L"btnPreguntas";
			this->btnPreguntas->Size = System::Drawing::Size(179, 83);
			this->btnPreguntas->TabIndex = 8;
			this->btnPreguntas->Text = L"Vida extra";
			this->btnPreguntas->UseVisualStyleBackColor = false;
			this->btnPreguntas->Click += gcnew System::EventHandler(this, &frmMenu::btnPreguntas_Click);
			// 
			// frmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(907, 798);
			this->Controls->Add(this->btnPreguntas);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnIniciar);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"frmMenu";
			this->Text = L"frmMenu";
			this->Load += gcnew System::EventHandler(this, &frmMenu::frmMenu_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void btnIniciar_Click(System::Object^ sender, System::EventArgs^ e) {
	Game^ frm = gcnew Game();

	this->Visible = false;
	frm->ShowDialog();
	this->Visible = true;
}
private: System::Void btnPreguntas_Click(System::Object^ sender, System::EventArgs^ e) {
	PreguntasM^ frame = gcnew PreguntasM();

	this->Visible = false;
	frame->ShowDialog();
	this->Visible = true;

}
private: System::Void frmMenu_Load(System::Object^ sender, System::EventArgs^ e) {

}
};
}
