#pragma once
#include <stdlib.h>
#include <Vector>

using namespace System;
using namespace System::Drawing;
using namespace std;

class Entidad {
protected:
	int x, y, dx, dy;
	int ancho, alto;
	int IDx;

public:
	Entidad() {
		//inicializando para que cuando ejecute no tengamos errores
		x = y = 0;
		dx = dy = 0;
		ancho = alto = 0;
		IDx = 0;
	}
	void SetDX(int value) {
		dx = value;
	}
	void SetDY(int value) {
		dy = value;
	}
	Rectangle Area() {
		return Rectangle(x,y,ancho,alto);
	}
	Rectangle NextArea() {
		return Rectangle(x+dx, y+dy, ancho, alto);
	}
	Rectangle Hitbox() {
		return Rectangle(x+ancho/2.5, y+alto/4, ancho/3.5, alto/2);

	}
	Rectangle NextHitbox() {
		return Rectangle(x + ancho / 2.5+dx, y + alto / 4+dy, ancho / 3.5, alto / 2);

	}

	virtual void Mover(Graphics^ g) {
		x += dx;
		y += dy;
	}
	virtual void Mostrar(Graphics^ g, Bitmap^ img) {
		g->FillRectangle(Brushes::Black, Area());
	}
};
