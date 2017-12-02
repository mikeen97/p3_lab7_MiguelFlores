#include <iostream>
#include <string>
#include "Usuario.h"
#include "Cliente.h"
#include "Personal.h"
#include "Administrador.h"
#include "Chef.h"
#include "LavaPlatos.h"
#include "Meseros.h"
#include <vector>

using namespace std;

//vector de usuarios
vector<Usuario*> listUsuarios;

int main(){
	int menu1=0;
	cout<<"------MENU------\n";
	cout<<"1)Login\n";
	cout<<"2)Registrarse\n";
	cout<<"3) SALIR\n";
	cin>>menu1;
	if (menu1==1){
		bool ingresarSistema=false;
		string verifUser="",verifPassw="";
		cout<<"Ingrese su Usuario\n";
		cin>>verifUser;
		cout<<"Ingrese su Password\n";
		cin>>verifPassw;
		for (int i = 0; i < listUsuarios.size(); ++i){
			if (listUsuarios.at(i)->getUserName()==verifUser&&listUsuarios.at(i)->getPassword()==verifPassw){
				ingresarSistema==true;
				break;
			}
		}
		if (ingresarSistema==true){
			cout<<"Ingreso al Sistema Bienvenido : \n";
			
		}else{
				cout<<"No se encontro su usuarios! \n";
			}
	}
	if (menu1==2){
		int menuAgregar=0;
		do{
			cout<<"-------MENU-----------\n";
			cout<<"1)Agregar Cliente\n";
			cout<<"2)Agregar Administrador\n";
			cout<<"3)Agregar Chef\n";
			cout<<"4)Agregar LavaPlatos\n";
			cout<<"5)Agregar Meseros\n";
			cout<<"6)SALIR \n";
			cin>>menuAgregar;
		}while(menuAgregar<1||menuAgregar>6);
		
		if (menuAgregar>0||menuAgregar<6){
			int edad=0;
			string userName="",password="",nombre="",id="",numeroTelefono="";
			cout<<"Ingrese su UserName\n";
			cin>>userName;
			cout<<"Ingrese su Password\n";
			cin>>password;
			cout<<"Ingrese su Nombre\n";
			cin>>nombre;
			cout<<"Ingrese su Identidad\n";
			cin>>id;
			do{
				cout<<"Ingrese su edad\n";
				cin>>edad;
			} while (edad<18);
			cout<<"Ingrese su numero de telefono\n";
			cin>>numeroTelefono;
			if (menuAgregar>=2&&menuAgregar<=5){
				int anoContratacion=0,sueldo=0;
				cout<<"Ingrese anos de contratacion \n";
				cin>>anoContratacion;
				cout<<"Ingrese el sueldo \n";
				cin>>sueldo;
			}

		}

		if (menuAgregar=1){//AGEGAR CLIENTE
			string direccion="";
			int ratingRest=0;
			cout<<"Ingrese su direccion de hogar: \n";
			cin>>direccion;
			do{
				cout<<"Ingrese Calificacion que le da a nuestro Restaurante: (1-5) \n";
				cin>>ratingHotel;
			} while (ratingRest<1||ratingRest>6);
			Cliente newCliente = new Cliente(userName, password, nombre, edad, id, numeroTelefono,direccion, ratingRest);
			listUsuarios.push_back(newCliente);
			cout<<"El cliente: "<<nombre<<" fue creado con exito. \n";

		}
		if (menuAgregar=2){//AGREGAR ADMINISTRADOR
			Administrador newAdministrador = new Administrador(userName, password, nombre, edad, id, numeroTelefono, anoContratacion, sueldo, 0, 0);
			listUsuarios.push_back(newAdministrador);
			cout<<"El Administrador: "<<nombre<<" fue creado con exito. \n";			
		}
		if (menuAgregar=3){//AGREGAR CHEF
			string favPlatillo="";
			cout<<"Ingrese el Platillo favorito de el chef \n";
			cin>>favPlatillo;
			Chef newChef = new Chef(userName, password, nombre, edad, id, numeroTelefono, anoContratacion, sueldo,favPlatillo);
			listUsuarios.push_back(newChef);
			cout<<"El Chef: "<<nombre<<" fue creado con exito. \n";	
		}
		if (menuAgregar=4){//AGREGAR LAVAPLATOS
			LavaPlatos newLavaplatos = new LavaPlatos(userName, password, nombre, edad, id, numeroTelefono, anoContratacion, sueldo,50);
			listUsuarios.push_back(newLavaplatos);
			cout<<"El LavaPlatos: "<<nombre<<" fue creado con exito. \n";	
		}
		if (menuAgregar=5){//AGREGAR MESEROS
			Meseros newMesero = new Meseros(userName, password, nombre, edad, id, numeroTelefono, anoContratacion, sueldo);
			listUsuarios.push_back(newMesero);
			cout<<"El Meseros: "<<nombre<<" fue creado con exito. \n";	
		}
		if (menuAgregar=6){//SALIR DE ESTE MENU
			cout<<"Se ha salido con exito! \n";
		}

	}
	if (menu1==3){

	}

    return 0;
}