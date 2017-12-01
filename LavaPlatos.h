#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"

using namespace std;

#ifndef LAVAPLATOS_H
#define LAVAPLATOS_H
class LavaPlatos : Personal{
	protected:
		int NivelMotivacion;
	public:
		LavaPlatos(int);
		LavaPlatos();
		int getNivelMotivacion();
		void setNivelMotivacion(int);

};
#endif