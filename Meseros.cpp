#include "Meseros.h"

Meseros::Meseros(vector<string> ListaPlatillos){
	this->ListaPlatillos=ListaPlatillos;
}

Meseros::Meseros(){
}
void Meseros::setListaPlatillos(string m){
   this-> ListaPlatillos.push_back(m);
}
vector<string> Meseros::getListaPlatillos(){
   return ListaPlatillos;
}
