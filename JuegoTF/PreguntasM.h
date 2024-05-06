#pragma once
#include <cstdlib>

namespace JuegoTF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de PreguntasM
	/// </summary>
	public ref class PreguntasM : public System::Windows::Forms::Form
	{
	public:
		PreguntasM(void)
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
		~PreguntasM()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblNum1;
	private: System::Windows::Forms::Label^ lblSigno;
	private: System::Windows::Forms::Label^ lblNum2;
	private: System::Windows::Forms::TextBox^ txtRespuesta;

	protected:




	private: System::Windows::Forms::Label^ lblEqual2;
	private: System::Windows::Forms::Button^ btnRespuesta;


	private: System::Windows::Forms::Button^ btnGenerarNumero;




	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblNum1 = (gcnew System::Windows::Forms::Label());
			this->lblSigno = (gcnew System::Windows::Forms::Label());
			this->lblNum2 = (gcnew System::Windows::Forms::Label());
			this->txtRespuesta = (gcnew System::Windows::Forms::TextBox());
			this->lblEqual2 = (gcnew System::Windows::Forms::Label());
			this->btnRespuesta = (gcnew System::Windows::Forms::Button());
			this->btnGenerarNumero = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Location = System::Drawing::Point(21, 9);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(239, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Resuelva esta operación para continuar jugando";
			// 
			// lblNum1
			// 
			this->lblNum1->AutoSize = true;
			this->lblNum1->Location = System::Drawing::Point(18, 80);
			this->lblNum1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblNum1->Name = L"lblNum1";
			this->lblNum1->Size = System::Drawing::Size(0, 13);
			this->lblNum1->TabIndex = 1;
			// 
			// lblSigno
			// 
			this->lblSigno->AutoSize = true;
			this->lblSigno->Location = System::Drawing::Point(64, 80);
			this->lblSigno->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblSigno->Name = L"lblSigno";
			this->lblSigno->Size = System::Drawing::Size(0, 13);
			this->lblSigno->TabIndex = 2;
			// 
			// lblNum2
			// 
			this->lblNum2->AutoSize = true;
			this->lblNum2->Location = System::Drawing::Point(112, 80);
			this->lblNum2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblNum2->Name = L"lblNum2";
			this->lblNum2->Size = System::Drawing::Size(0, 13);
			this->lblNum2->TabIndex = 3;
			// 
			// txtRespuesta
			// 
			this->txtRespuesta->Location = System::Drawing::Point(196, 78);
			this->txtRespuesta->Margin = System::Windows::Forms::Padding(2);
			this->txtRespuesta->Name = L"txtRespuesta";
			this->txtRespuesta->Size = System::Drawing::Size(85, 20);
			this->txtRespuesta->TabIndex = 4;
			this->txtRespuesta->TextChanged += gcnew System::EventHandler(this, &PreguntasM::textBox1_TextChanged);
			// 
			// lblEqual2
			// 
			this->lblEqual2->AutoSize = true;
			this->lblEqual2->Location = System::Drawing::Point(170, 80);
			this->lblEqual2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblEqual2->Name = L"lblEqual2";
			this->lblEqual2->Size = System::Drawing::Size(13, 13);
			this->lblEqual2->TabIndex = 5;
			this->lblEqual2->Text = L"=";
			this->lblEqual2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->lblEqual2->Click += gcnew System::EventHandler(this, &PreguntasM::label5_Click);
			// 
			// btnRespuesta
			// 
			this->btnRespuesta->Location = System::Drawing::Point(183, 131);
			this->btnRespuesta->Margin = System::Windows::Forms::Padding(2);
			this->btnRespuesta->Name = L"btnRespuesta";
			this->btnRespuesta->Size = System::Drawing::Size(93, 45);
			this->btnRespuesta->TabIndex = 6;
			this->btnRespuesta->Text = L"Enviar Respuesta";
			this->btnRespuesta->UseVisualStyleBackColor = true;
			this->btnRespuesta->Click += gcnew System::EventHandler(this, &PreguntasM::btnRespuesta_Click);
			// 
			// btnGenerarNumero
			// 
			this->btnGenerarNumero->Location = System::Drawing::Point(12, 134);
			this->btnGenerarNumero->Name = L"btnGenerarNumero";
			this->btnGenerarNumero->Size = System::Drawing::Size(87, 39);
			this->btnGenerarNumero->TabIndex = 7;
			this->btnGenerarNumero->Text = L"Numero Aleatorio";
			this->btnGenerarNumero->UseVisualStyleBackColor = true;
			this->btnGenerarNumero->Click += gcnew System::EventHandler(this, &PreguntasM::btnGenerarNumero_Click);
			// 
			// PreguntasM
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(287, 187);
			this->Controls->Add(this->btnGenerarNumero);
			this->Controls->Add(this->btnRespuesta);
			this->Controls->Add(this->lblEqual2);
			this->Controls->Add(this->txtRespuesta);
			this->Controls->Add(this->lblNum2);
			this->Controls->Add(this->lblSigno);
			this->Controls->Add(this->lblNum1);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"PreguntasM";
			this->Text = L"PreguntasM";
			this->Load += gcnew System::EventHandler(this, &PreguntasM::PreguntasM_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		bool RespuestaCorrecta()
		{
			// Obtener la respuesta ingresada por el usuario
			String^ respuestaUsuario = txtRespuesta->Text;

			// Variables para almacenar los números
			int num1, num2;

			try
			{
				// Convertir las etiquetas a enteros
				num1 = Convert::ToInt32(lblNum1->Text);
				num2 = Convert::ToInt32(lblNum2->Text);
			}
			catch (FormatException^)
			{
				// Manejar la situación en la que los valores no son números válidos
				// Puedes mostrar un mensaje al usuario, registrar el error, etc.
				MessageBox::Show("Error: Los valores en las etiquetas no son números válidos.");
				return false;  // Indicar que la respuesta no es correcta
			}

			// Calcular el resultado de la operación actual
			int resultado = 0;

			if (lblSigno->Text == "+") {
				resultado = num1 + num2;
			}
			else if (lblSigno->Text == "-") {
				resultado = num1 - num2;
			}
			else if (lblSigno->Text == "*") {
				resultado = num1 * num2;
			}

			// Verificar si la respuesta es correcta
			return (respuestaUsuario == resultado.ToString());
		}

#pragma endregion
	private: System::Void PreguntasM_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnGenerarNumero_Click(System::Object^ sender, System::EventArgs^ e) {
		Random^ random = gcnew Random();

		// Generar y mostrar dos números aleatorios
		int numeroAleatorio1 = random->Next(11);
		int numeroAleatorio2 = random->Next(11);

		lblNum1->Text = numeroAleatorio1.ToString();
		lblNum2->Text = numeroAleatorio2.ToString();

		String^ signo;
		int indiceOperador = random->Next(3);  // Número aleatorio entre 0 y 3

		switch (indiceOperador) {
		case 0:
			signo = "+";
			break;
		case 1:
			signo = "-";
			break;
		case 2:
			signo = "*";
			break;
		}

		lblSigno->Text = signo;
	}

	private: System::Void btnRespuesta_Click(System::Object^ sender, System::EventArgs^ e) {
		// Validar la respuesta del usuario
		if (RespuestaCorrecta()) {
			// Respuesta correcta, puedes realizar acciones adicionales si lo deseas
			MessageBox::Show("¡Respuesta correcta!");
			this->Close();
		}
		else {
			// Respuesta incorrecta, puedes realizar acciones adicionales si lo deseas
			MessageBox::Show("Respuesta incorrecta.");
			Application::Exit();

		}

		// Generar nuevos números y operador para la siguiente pregunta
		btnGenerarNumero_Click(sender, e);
	}


	};
}
