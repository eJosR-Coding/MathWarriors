#pragma once
#include "Juego.h"
#include "PreguntasM.h"

namespace JuegoTF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Game
	/// </summary>
	public ref class Game : public System::Windows::Forms::Form
	{
		Juego^ juego;
		Bitmap^ fondo;
	
	public:
		Game(void)
		{
			InitializeComponent();
			juego = gcnew Juego(2,1,70);
			fondo = gcnew Bitmap("Fondo (4).png");
			preguntasForm = gcnew PreguntasM();
			//
			//TODO: agregar código de constructor aquí
			//

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Game()
		{
			if (components)
			{
				delete components;
			}
			delete juego;
		}
	private: System::Windows::Forms::Timer^ clock;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::ComponentModel::IContainer^ components;





	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		bool mostradoMensajePerdida;  // Nueva variable
		bool estadoPerdida;  // Nuevo estado

	
		PreguntasM^ preguntasForm;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Game::typeid));
			this->clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// clock
			// 
			this->clock->Enabled = true;
			this->clock->Interval = 30;
			this->clock->Tick += gcnew System::EventHandler(this, &Game::clock_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Desktop;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(0, 613);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1709, 114);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1516, 725);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Game";
			this->Text = L"Game";
			this->Load += gcnew System::EventHandler(this, &Game::Game_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Game::Game_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Game::Game_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	Void clock_Tick(Object^ sender, EventArgs^ e)

	{
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);

		// Para el fondo
		int ancho = bf->Graphics->VisibleClipBounds.Width;
		int alto = bf->Graphics->VisibleClipBounds.Height;

		// Dibujar el fondo primero
		bf->Graphics->DrawImage(fondo, 0, 0, ancho, alto);

	
		juego->Mostrar(bf->Graphics, nullptr);
		bf->Render(g);
		juego->Mover(bf->Graphics);
		//BufferedGraphicsContext^ espaciobuffer = BufferedGraphicsManager::Current;

		//supuesot fondo, solo que no se cual es el nombre del lienzo
		//BufferedGraphics^ buffer = espaciobuffer->Allocate(, this->ClientRectangle);
// Verificar las vidas y cerrar el juego si es necesario
		if (juego->GetVidas() == 0 && !estadoPerdida) {
			estadoPerdida = true;  // Cambiar al estado de pérdida

			// Mostrar el mensaje de pérdida
			MessageBox::Show("¡Perdiste!", "¡Game Over!", MessageBoxButtons::OK, MessageBoxIcon::Information);

			// Detener el temporizador para evitar eventos adicionales
			clock->Stop();
		}
	}

	private: System::Void Game_Load(System::Object^ sender, System::EventArgs^ e) {
	
	}
	private: System::Void CerrarFormulario() {
	this->Close();
}
	private: System::Void Game_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		juego->MovimientoJugador(true, e->KeyCode);
	}
	private: System::Void Game_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		juego->MovimientoJugador(false, e->KeyCode);
	}

};
}
