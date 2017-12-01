#include "Chef.h"

Chef::Chef(string PlatilloFavorito){
	this->PlatilloFavorito=PlatilloFavorito;
}
Chef::Chef(){

}void Chef::setPlatilloFavorito(string PlatilloFavorito){
   this-> PlatilloFavorito=PlatilloFavorito;
}
string Chef::getPlatilloFavorito(){
   return PlatilloFavorito;
}
