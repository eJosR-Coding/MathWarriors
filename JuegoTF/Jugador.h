#pragma once
#include "Entidad.h"

enum SpriteJugador {
	CaminarDerecha,
	CaminarIzquierda,
	Descanso,
	Atacar
};

class Jugador :public Entidad
{
private:
	int vidas;
	SpriteJugador accion;
public:
	Jugador(Bitmap^ img, int v) {
		x = 60; y = 370;
		dx = dy = 0;
		ancho = img->Width / 8;
		alto = img->Height / 4;

		accion = CaminarDerecha;
		
		vidas = v;

	}
	void SetVidas(int value) {
		vidas += value;
	}
	int GetVidas() {
		return vidas;
	}

	void SetAccion(SpriteJugador value) {
		accion = value;
	}

	SpriteJugador GetAccion() {
		return accion;
	}

	void Mover(Graphics^ g) {
		if (x + dx >= 0 && x+ancho+ dx < g->VisibleClipBounds.Width)
			x += dx;
	}
	void Mostrar(Graphics^ g, Bitmap^ img) {
		g->DrawString("Vidas: "+ vidas, gcnew Font("Pixeboy",12),Brushes::Black,0,0);
		Rectangle corte = Rectangle(IDx*ancho,accion*alto,ancho,alto);
		g->DrawImage(img, Area(),corte, GraphicsUnit::Pixel);

		if(accion>=Atacar &&accion<=CaminarDerecha && (dx!=0||dy!=0))
			IDx = (IDx + 1) % 8;


	}
};

