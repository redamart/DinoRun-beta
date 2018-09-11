#pragma once


using namespace System;
using namespace System::Drawing;

public ref class CObs {
private:
	int x;
	int y;
	int vel;
	int dvel;
	Bitmap^ obs_1;
	
	Random r;


public:
	CObs() {
		if (r.Next(0, 2)%2 == 0) {
			obs_1 = gcnew Bitmap("img/obs_1.png");
			y = 355;
		}
		else
		{
			obs_1 = gcnew Bitmap("img/obs_2.png");
			y = 385;
		}
		
		x = 1200;
		
		vel = 8;
		dvel = 3;
		
	
	};
	void dibujarobs(BufferedGraphics ^buffer) {
		obs_1->MakeTransparent(Color::White);
		buffer->Graphics->DrawImage(obs_1, x,y );
		
		
	}
	

	void velaum() {
		vel += dvel;
		if (dvel > 1) {

			dvel--;
		}

	}
	void moverObs() {
		
		x -= vel;
		
	}


};