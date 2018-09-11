#pragma once
using namespace System;
using namespace System::Drawing;
public ref class CDino {
private:
	
	int alto;
	int ancho;
	int vel;
	Bitmap^ dino;
	Bitmap^ dino_up;
	int inX;
	int x;
	int y;
	int lag;
	SolidBrush^ paint;
	int dy;
	Rectangle area;
	bool saltando;
	
public:
	CDino() {
		dino = gcnew Bitmap("img/dino_spr.png");
		dino_up = gcnew Bitmap("img/dino_up.png");
		alto = 136;
		ancho = 150;
		vel = 5;
		inX = 0;
		x = 50;
		y = 365;
		lag = 10;
		paint = gcnew SolidBrush(Color::White);
		dy = 20;
		
		saltando = false;
		
	};
	void dibujarDino(BufferedGraphics ^buffer) {

		Rectangle pAU = Rectangle(inX*ancho, 0, ancho, alto);
		Rectangle pAU2 = Rectangle(0, 0, ancho, alto);
		Rectangle lugar = Rectangle(x, y, ancho, alto);
		
		dino->MakeTransparent(Color::White);
		dino_up->MakeTransparent(Color::White);
		if (saltando == false) {
			buffer->Graphics->FillRectangle(paint, x + 40, y + 80, 50, 45);
			buffer->Graphics->DrawImage(dino, lugar, pAU, GraphicsUnit::Pixel);
		}
		else
			buffer->Graphics->DrawImage(dino_up, lugar, pAU2, GraphicsUnit::Pixel);
		area = Rectangle(x+24,y+22,80,80);
	};
	Rectangle getarea() {
		return area;
	}
	void saltar() {
		if (saltando == true) {

			y -= dy;
			dy-= 1;
			if (y >= 365) {
				saltando = false;
				dy = 20;
			}
		}else
		y = 365;
	}
	void mover() {
		lag--;
		if (lag%7 == 0) {
			if (0 <= inX && inX < 1)
				inX++;
			else
				inX = 0;
		}
		
	}
	bool getState() {
		return saltando;
	}
	void setState(bool saltando) {
		this->saltando = saltando;
	}
};