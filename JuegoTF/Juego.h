#pragma once
#include <time.h>
#include "Jugador.h"
#include "Obstaculo.h"
#include "Enemigo.h"
#include "Boss.h"

using namespace System::Windows::Forms;



ref class Juego {
private:
		Jugador* jugador;
		Obstaculos* obstaculos;
		Enemigos* enemigos;
		FinalBoss* boss;

		Bitmap^ imgEnemigo;
		Bitmap^ imgJugador;
		Bitmap^ imgObstaculo1;
		Bitmap^ imgObstaculo2;
		Bitmap^ imgEnemigo2;
		//boss
		Bitmap^ imgBoss;

		int CooldownAtaqueEnemigo;
		bool Perder;
		int tiempo;

public:
	Juego(int v, int e, int t) {
		imgEnemigo = gcnew Bitmap("Golem.png");
		imgEnemigo2 = gcnew Bitmap("Enemigo2.png");
		imgObstaculo1 = gcnew Bitmap("Obs1.png");
		imgBoss = gcnew Bitmap("idle.png");
		imgObstaculo2 = gcnew Bitmap("Obs2.png");
		imgJugador = gcnew Bitmap("JugadorCorrer.png");
		jugador = new Jugador(imgJugador, v);
		boss = new FinalBoss(imgBoss, v);
		obstaculos = new Obstaculos(2, jugador->Area(), imgEnemigo);
		enemigos = new Enemigos(imgEnemigo2, e);

		CooldownAtaqueEnemigo = 0;
		Perder = false;
		tiempo = t * 1000;


	}
	~Juego() {
		delete jugador;
		delete obstaculos;
		delete imgEnemigo;
	}
	int GetVidas() {
		return jugador->GetVidas();
	}

	void MovimientoJugador(bool accion, Keys tecla) {

		int v = 4;

		if (accion == true)
		{
			if (tecla == Keys::Up)
				jugador->SetDY(-v);
			else if (tecla == Keys::Down)
				jugador->SetDY(v);
			else if (tecla == Keys::Left) {
				jugador->SetDX(-v);
				jugador->SetAccion(CaminarIzquierda);
			}
			else if (tecla == Keys::Right) {
				jugador->SetDX(v);
				jugador->SetAccion(CaminarDerecha);
			}
			else if (tecla == Keys::Space) {
				jugador->SetDX(v);
				jugador->SetAccion(Atacar);
			}
		}
		else {
			jugador->SetAccion(Descanso);
			if (tecla == Keys::Up)
				jugador->SetDY(0);
			else if (tecla == Keys::Down)
				jugador->SetDY(0);
			else if (tecla == Keys::Left)
				jugador->SetDX(0);
			else if (tecla == Keys::Right)
				jugador->SetDX(0);
		}

	}

	bool Mover(Graphics^ g) {

		if (jugador->GetAccion() == Atacar) {
			obstaculos->Eliminar(jugador->Area());
			enemigos->Eliminar(jugador->Area());
		}


		if (enemigos->Colision(jugador->NextHitbox())&& clock()-CooldownAtaqueEnemigo >= 2000) {
			jugador->SetVidas(-1);
			CooldownAtaqueEnemigo = clock();
			
			if (jugador->GetVidas() == 0 && !Perder) {
				Perder = true;
				MessageBox::Show("¡Perdiste!", "¡Game Over!", MessageBoxButtons::OK, MessageBoxIcon::Information);
				ReiniciarJuego();
				return false;
			}
		}

		if (clock() >= tiempo) {
			MessageBox::Show("¡Ganaste!", "¡Felicidades!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			ReiniciarJuego();
			return false;
		}

		if (obstaculos->Colision(jugador->NextHitbox()) == false) {
			jugador->Mover(g);
		}
	
		obstaculos->Mover(g);
		enemigos->Mover(g);
		 
		return true;
	}
	void ReiniciarJuego() {
		// Restablecer el juego con nuevas configuraciones o reiniciar la aplicación según tus necesidades.
   // Por ejemplo, puedes volver a crear una instancia de Juego con diferentes parámetros o cerrar la aplicación.
   // Puedes ajustar esto según la estructura de tu aplicación.
   // Ejemplo:
		delete jugador;
		jugador = new Jugador(imgJugador, 4); // Ajusta los parámetros según tu juego
		delete obstaculos;
		obstaculos = new Obstaculos(2, jugador->Area(), imgEnemigo); // Ajusta los parámetros según tu juego
		delete enemigos;
		enemigos = new Enemigos(imgEnemigo2, 1); // Ajusta los parámetros según tu juego
		delete boss;
		boss = new FinalBoss(imgBoss, 4);
	
	}



	void Mostrar(Graphics^ g, Bitmap^ img) {

		g->DrawString("Tiempo: " + ((tiempo-clock())/1000), gcnew Font("Pixeboy", 12), Brushes::Black, 0, 20);
		
		jugador->Mostrar(g, imgJugador);
		obstaculos->Mostrar(g, imgEnemigo);
		enemigos->Mostrar(g, imgEnemigo2);
	}
};