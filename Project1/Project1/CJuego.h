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
	
	
	
public:
	CJuego() {
		dino = gcnew CDino();
		esc = gcnew CEscenario();
		scr = 0;
		aum = 1;
		saltando = false;
		
	}

	void dibujar(BufferedGraphics ^buffer, int sw, int sh) {
		esc->dibujarfondo(buffer, sw, sh);

		dino->dibujarDino(buffer);

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
		
	}
	int getscr() { return scr; }

	
	void valsalto() {
		
		dino->saltar();
		
	}
	void setState(bool state) {
		dino->setState(state);
	}


	~CJuego() {

	}



	void penalizar() {};
};