#pragma once
#include "Entidad.h"
#include "Enemigo.h"
enum AccionFinalBoss {
    BossDerecha,
    BossIzquierda,
    BossAtaque
};

class FinalBoss : public Entidad {
private:
    AccionFinalBoss accion;

public:
    FinalBoss(Bitmap^ img, int v) {
        x = rand() % 800;
        y = 435;

        if (rand() % 2 == 0) {
            // DX
            dx = rand() % 5 - 3;
            if (dx == 0)
                dx = 3;
        }
        else {
            // DY
            dx = rand() % 5 - 1;
            if (dx == 0)
                dx = 3;
        }

        ancho = img->Width / 6;
        alto = img->Height / 4;

        accion = BossDerecha;
    }

    void Mover(Graphics^ g) {
        if (!(x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width))
            dx *= -1;

        if (dx < 0)
            accion = BossDerecha;
        else if (dx > 0)
            accion = BossIzquierda;

        x += dx;
    }

    void Mostrar(Graphics^ g, Bitmap^ img) {
        Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);

        if (accion == BossAtaque) {
            g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
        }
        else {
            g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);

            if (accion >= BossDerecha && accion <= BossIzquierda)
                IDx = (IDx + 1) % 4;
        }
    }

    bool ColisionJugador(Rectangle jugadorRect) {
        return Hitbox().IntersectsWith(jugadorRect);
    }
};

