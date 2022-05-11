#ifndef CAR_H
#define CAR_H

#include "objects.h"
#include "baseLib.h"

class Mobil: public Objek
{
public:
	Mobil(float x, float y, float z,float rotate);
};

void kerucut(float ngisor, float nduwur, float dowo);

void cylinder(float alas,float atas,float tinggi);

void blok(float tebal,int ratiol,int ratiop);

#endif 
