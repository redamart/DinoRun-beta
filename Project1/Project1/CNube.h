#pragma once



using namespace System;
using namespace System::Drawing;

public ref class CNube {
private:
	
	int x;
	int y;
	int vel;
	Bitmap^ nube;
	Random r;
	int dvel;
	
public:
	CNube() {
		nube = gcnew Bitmap("img/cloud.png");
		vel = 1;
		this->y = r.Next(120, 300);
		x = 1200;
		dvel = 2;
	}
	void dibujarnube(BufferedGraphics ^buffer) {


		
		buffer->Graphics->DrawImage(nube,x, y);
		


	}
	
	void movernube() {
		x -= vel;
	}
	int getX() { return this->x; }

};