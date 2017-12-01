#include "LavaPlatos.h"

LavaPlatos::LavaPlatos(int NivelMotivacion){
	this->NivelMotivacion=NivelMotivacion;
}
LavaPlatos::LavaPlatos(){

}void LavaPlatos::setNivelMotivacion(int NivelMotivacion){
   this-> NivelMotivacion=NivelMotivacion;
}
int LavaPlatos::getNivelMotivacion(){
   return NivelMotivacion;
}
