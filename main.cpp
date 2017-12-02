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


int main(){
	vector<Usuario*> listUsuarios;
	string anoContratacion="";
	int sueldo=0;
	int menu1=0;
	cout<<"------MENU------\n";
	cout<<"1)Login\n";
	cout<<"2)Registrarse\n";
	cout<<"3) SALIR\n";
	cin>>menu1;
	if (menu1==1){
		int cont=0;
		bool ingresarSistema=false;
		string verifUser="",verifPassw="";
		cout<<"Ingrese su Usuario\n";
		cin>>verifUser;
		cout<<"Ingrese su Password\n";
		cin>>verifPassw;

		for (int i = 0; i < listUsuarios.size(); ++i){
			if (listUsuarios.at(i)->getUserName()==verifUser&&listUsuarios.at(i)->getPassword()==verifPassw){
				ingresarSistema==true;
				cont++;
				break;
			}
		}
		while(ingresarSistema==true){
			cout<<"Ingreso al Sistema Bienvenido : \n";
			if (dynamic_cast<Cliente*>(listUsuarios[cont])){

				cout<<"-----MENU DE ADMINISTRADOR---------\n";
				cout<<"1)Agregar Empleado\n";
				cout<<"2)Despedir Empleado\n";
				cout<<"3)Empleado con menor sueldof\n";
				cout<<"4)Agregar platillo\n";
				cout<<"5)Empleado con mayor sueldo\n";
				cout<<"6)Promedio de todos los sueldos \n";
				cout<<"7)SALIR\n";
			
			}

		}
	}
	if (menu1==2){
		int menuAgregar=0;
		string userName="",password="",nombre="",id="";
		int edad=0,numeroTelefono=0;
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
				cout<<"Ingrese ano de Contratacion \n";
				cin>>anoContratacion;
				cout<<"Ingrese sueldo\n";
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
				cin>>ratingRest;
			} while (ratingRest<1||ratingRest>6);

			Cliente* newCliente = new Cliente(userName,password,nombre,edad,id,numeroTelefono, direccion, ratingRest);
			listUsuarios.push_back(newCliente);
			cout<<"El cliente: "<<nombre<<" fue creado con exito. \n";
		}
		if (menuAgregar=2){//AGREGAR ADMINISTRADOR
			Administrador* newAdministrador = new Administrador(userName,password,nombre,edad,id,numeroTelefono, anoContratacion, sueldo,0,0);
			listUsuarios.push_back(newAdministrador);
			cout<<"El Administrador: "<<nombre<<" fue creado con exito. \n";
		}
		if (menuAgregar=3){//AGREGAR CHEF
			cout<<"Ingrese su platillo favorito: \n";
			string favPlato="";
			cin>>favPlato;
			Chef* newChef = new Chef(userName,password,nombre,edad,id,numeroTelefono, anoContratacion, sueldo,favPlato);
			listUsuarios.push_back(newChef);
			cout<<"El Chef: "<<nombre<<" fue creado con exito. \n";
		}
		if (menuAgregar=4){//AGREGAR LAVAPLATOS
			LavaPlatos* newLavaPlatos = new LavaPlatos(userName,password,nombre,edad,id,numeroTelefono, anoContratacion, sueldo,50);
			listUsuarios.push_back(newLavaPlatos);
			cout<<"El LavaPlatos: "<<nombre<<" fue creado con exito. \n";
		}
		if (menuAgregar=5){//AGREGAR MESEROS
			Meseros* newMeseros = new Meseros(userName,password,nombre,edad,id,numeroTelefono, anoContratacion, sueldo);
			listUsuarios.push_back(newMeseros);
			cout<<"El : Meseros"<<nombre<<" fue creado con exito. \n";
		}
		if (menuAgregar=6){//SALIR DE ESTE MENU
			cout<<"Se ha salido con exito! \n";
		}

	}
	if (menu1==3){

	}

    return 0;
}