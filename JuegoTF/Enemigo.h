#pragma once
#include "Entidad.h"

enum SpriteEnemigo {
	eCaminarIzquierda,
	eCaminarDerecha,

	eMorir
};
//Enemigo herda de entidad
class Enemigo : public Entidad {
	SpriteEnemigo accion;

public:
	Enemigo(Bitmap^ img) {
		x = rand() % 500;
		y = 435;

		if (rand() % 2 == 0) {
		//DX
			dx = rand() % 5 - 3;
			if (dx == 0)
				dx = 3;
		}
		else {
			//DY
			dx = rand() % 5 - 1;
			if (dx == 0)
				dx = 3;
		}

		ancho = img->Width / 4;
		alto = img->Height / 2;
		
		accion = eCaminarDerecha;
	}
	//Usa los mismos métodos es decir se aplica en este caso el polimorfismo
	void Mover(Graphics^ g) {
		if (!(x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width))
			dx *= -1;
	
		if (dx < 0)
			accion = eCaminarIzquierda;
		else if (dx > 0)
			accion = eCaminarDerecha;

	
			x += dx;
	}
	void Mostrar(Graphics^ g, Bitmap^ img) {
		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);

		if (accion >= eCaminarDerecha && accion <= eCaminarIzquierda)
			IDx = (IDx + 1) % 4;

	}
};

class Enemigos {
	vector<Enemigo*> enemigos;
public:
	Enemigos(Bitmap^ img, int cant) {
		for (int i = 0; i < cant; i++) {
			enemigos.push_back(new Enemigo(img));
		}
	}

	~Enemigos() {
		for each (Enemigo * E in enemigos) {
			delete E;
		}
	}

	int Eliminar(Rectangle rect) {
		int cant = 0;

		for (int i = 0; i < enemigos.size(); i++) {
			if (enemigos[i]->Hitbox().IntersectsWith(rect)) {
				delete enemigos[i];
				enemigos.erase(enemigos.begin() + i--);
				cant++;
			}
		}

		return cant;
	}


	bool Colision(Rectangle obj){
		for each (Enemigo * E in enemigos)
			if (E->Hitbox().IntersectsWith(obj))
				return true;

		return false;
	}

	void Mover(Graphics^ g) {
		for each (Enemigo * E in enemigos) {
			E->Mover(g);
		}
	}

	void Mostrar(Graphics^ g, Bitmap^img) {
		for each (Enemigo * E in enemigos) {
			E->Mostrar(g, img);
		}
	}
};