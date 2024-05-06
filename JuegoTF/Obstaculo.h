#pragma once
#include "Entidad.h"
#include "iostream"
#include "Vector"
using namespace std;

class Obstaculo :public Entidad {
public:
	Obstaculo(Bitmap^ img) {
		x = rand() % 800 + rand() % 300;
		y = 459;

		ancho = img->Width;
		alto = img->Height;
	}
	void Mostrar(Graphics^ g, Bitmap^ img) {
		g->DrawImage(img, Area());
	}
};
//arreglo de 
class Obstaculos {
private:
	vector<Obstaculo*> obstaculos;
public:
	Obstaculos(int n, Rectangle obj, Bitmap^ img) {
		for (int i = 0; i < n; i++) 
		{
			Obstaculo* obs = new Obstaculo(img);
			if(obs->Area().IntersectsWith(obj)==false && Colision(obs->Area())==false)
			obstaculos.push_back(obs);
			else {
				delete obs;
				i--;
			}
		}
	}
	~Obstaculos() {
		for (int i = 0; i < obstaculos.size(); i++) {
			delete obstaculos.at(i);
		}
	}

	int Eliminar(Rectangle rect) {

		int cant = 0;
		for (int i = 0; i < obstaculos.size(); i++) {
			if (obstaculos[i]->Area().IntersectsWith(rect)) {
				obstaculos.erase(obstaculos.begin() + i--);
				cant++;
			}
		}
		return cant;
	}

	bool Colision(Rectangle obj) {
		for (Obstaculo* obs : obstaculos) {
			if (obs->Area().IntersectsWith(obj))
				return true;
		}
		return false;
	}

	void Mover(Graphics^ g) {
		for (int i = 0; i < obstaculos.size(); i++) 
		{
			 obstaculos.at(i)->Mover(g);
		}
	}
	void Mostrar(Graphics^ g, Bitmap^ img) {
		for (Obstaculo* obs: obstaculos) {
			obs->Mostrar(g, img);
		}

	}
	
};