#include <iostream>
#include <string>
#include <vector>
#include "Usuario.h"

using namespace std;

#ifndef CLIENTE_H
#define CLIENTE_H
class Cliente : public Usuario{
	public:
		string Direccion;
		int RatingRest;
	public:
		Cliente(string,string,string,int,string,int,string,int);//contructor sobrecargado con usuario.
		Cliente();
		string getDireccion();
		void setDireccion(string);

		int getRatingRest();
		void setRatingRest(int);

		virtual ~Cliente();


};
#endif