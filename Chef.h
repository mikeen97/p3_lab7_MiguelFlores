#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"

using namespace std;

#ifndef CHEF_H
#define CHEF_H
class Chef : Personal{
	protected:
		string PlatilloFavorito;
	public:
		Chef(string);
		Chef();
		string getPlatilloFavorito();
		void setPlatilloFavorito(string);

};
#endif