
#pragma once
#include "CNube.h"
#include "CObs.h"
using namespace System;
using namespace System::Drawing;

public ref class CEscenario {
private:
	int X1;
	int X2;
	int vel;
	int dvel;
	Bitmap^ fl_1;
	Bitmap^ fl_2;
	SolidBrush^ paint;
	array<CNube^>^ nubes;
	int n;
	array<CObs^>^ obs;
	int o;
public:
	CEscenario() {
		fl_1 = gcnew Bitmap("img/floor_03.png");
		fl_2 = gcnew Bitmap("img/floor_03.png");
		X1 = 0;
		X2 = 1500;
		vel = 8;
		dvel = 3;
		nubes = gcnew array<CNube^>(150);
		obs = gcnew array<CObs^>(150);
		nubes[0] = gcnew CNube();
		obs[0] = gcnew CObs();
		o = 1;
		n = 1;
		//paint = gcnew SolidBrush(Color::White);
	};
	void dibujarfondo(BufferedGraphics ^buffer, int sw, int sh) {


		//buffer->Graphics->FillRectangle(paint , 0, 0, 1000, 600);
		//Drawing::Rectangle todaPantalla = Drawing::Rectangle(0, 0, 1000, 600);
		//buffer->Graphics->DrawImage(fl_1, todaPantalla, X1, 420, 50, 50, GraphicsUnit::Pixel);
		buffer->Graphics->DrawImage(fl_1, X1, 428);
		buffer->Graphics->DrawImage(fl_2, X2, 428);
		for (int i = 0; i < n; i++) {
			nubes[i]->dibujarnube(buffer);
			nubes[i]->movernube();

		}
		for (int i = 0; i < o; i++) {
			obs[i]->dibujarobs(buffer);
			obs[i]->moverObs();

		}
	}
		void addnube() {
			nubes[n] = gcnew CNube();
			n++;
	
	}
		void addObs() {
			obs[o] = gcnew CObs();
			o++;
		}
	void velaum() {
		vel += dvel;
		if (dvel > 1) {
			
			dvel--;
		}
		for (int i = 0; i < o; i++) {
			obs[i]->velaum();

		}
		
	}
	void mover() {
		if (X1 < -1500) {
			X1 = 1500;
		}
		if (X2 < -1500) {
			X2 = 1500;
		}
		X1 -= vel;
		X2 -= vel;
	}
	
	
};