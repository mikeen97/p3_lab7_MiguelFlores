#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"

using namespace std;

#ifndef CHEF_H
#define CHEF_H
class Chef : public Personal{
	protected:
		string PlatilloFavorito;
	public:
		Chef(string,string,string,int,string,int,string,double,string);
		Chef();
		string getPlatilloFavorito();
		void setPlatilloFavorito(string);

		virtual ~Chef();


};
#endif