#include <iostream>
#include <string>
#include <vector>
#include "Usuario.h"

using namespace std;

#ifndef CLIENTE_H
#define CLIENTE_H
class Cliente : Usuario{
	protected:
		string Direccion;
		int RatingRest;
	public:
		Cliente(string,int);
		Cliente();
		string getDireccion();
		void setDireccion(string);

		int getRatingRest();
		void setRatingRest(int);

};
#endif