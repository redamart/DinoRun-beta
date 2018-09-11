#pragma once
#include "CDino.h"
#include "Cescenario.h"
#include "CNube.h"

using namespace System;
using namespace System::Drawing;

public ref class CJuego {
private:
	CEscenario ^ esc;
	CDino^ dino;
	int scr;
	String^ puntaje;
	long aum;
	bool saltando;
	bool gameover;


public:
	CJuego() {
		dino = gcnew CDino();
		esc = gcnew CEscenario();
		scr = 0;
		aum = 1;
		saltando = false;
		gameover = false;

	}

	void dibujar(BufferedGraphics ^buffer, int sw, int sh) {
		esc->dibujarfondo(buffer, sw, sh);

		dino->dibujarDino(buffer);

	}
	void Intersect() {
		
	}
	bool getGameOver() {
		return gameover;
	}
	void animar() {
		dino->mover();
		esc->mover();
		scr++;
		aum++;
		if (aum % 550 == 0)
			esc->addnube();
		if (aum % 250 == 0)
			esc->addObs();
		if (aum % 578 == 0) {
			esc->velaum();
		}
		if (dino->getarea().IntersectsWith(esc->getObsArea()) == true)
			gameover = true;
	}
	int getscr() { return scr; }

	
	void valsalto() {
		
		dino->saltar();
		
	}
	void setState(bool state) {
		dino->setState(state);
	}
	bool getState() {
		return dino->getState();
	}


	~CJuego() {

	}



	void penalizar() {};
};