#include "Usuario.h"
#include "Cliente.h"
#include "Personal.h"
#include "Administrador.h"
#include "Chef.h"
#include "LavaPlatos.h"
#include "Meseros.h"
#include <vector>
#include <typeinfo>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <stdio.h>



using namespace std;

//funciones 
vector<string> maxSueldo(vector<Usuario*>);
vector<string> minSueldo(vector<Usuario*>);
double PromedioRat(vector<Usuario*>);
void escribir(vector<Usuario*> MiVector);
double PromedioRestaurante(vector<Usuario*>);
vector<Usuario*> RecuperacionDatos();
//crear personal
Chef* crearChef();
LavaPlatos* crearLavaplatos();
Meseros* crearMeseros();

int main(){
	vector<Usuario*> listUsuarios;
	string anoContratacion="";
	int sueldo=0;
	int menu1=0;
	while(menu1!=6){
		cout<<"------MENU------\n";
		cout<<"1)Login\n";
		cout<<"2)Registrar Administrador\n";
		cout<<"3)Promedio de el Restaurante\n";
		cout<<"4)GUARDAR\n";
		cout<<"5)CARGAR ARCHIVO\n";
		cout<<"6)SALIR DEL PROGRAMA\n";
		cin>>menu1;
		if (menu1==1){
			int PosUser=0;
			bool ingresarSistema=false;
			string verifUser="",verifPassw="";
			cout<<"Ingrese su Usuario Administrador\n";
			cin>>verifUser;
			cout<<"Ingrese su Password Administrador\n";
			cin>>verifPassw;
			for (int i = 0; i < listUsuarios.size(); ++i){
				if (listUsuarios.at(i)->getUserName()==verifUser&&listUsuarios.at(i)->getPassword()==verifPassw){
					ingresarSistema=true;
					break;
				}else{
					PosUser++;
				}
			}
			if(ingresarSistema==true) {
				cout<<"Ingreso al Sistema Bienvenido : "<<PosUser<<"\n";
				if (dynamic_cast<Administrador*>(listUsuarios[PosUser])){//////////menu de Administradores.
					cout << "Bienvenido al menu de admin." << endl;
					int menuAdministrador=0;
					string userName="",password="",nombre="",id="";
					int edad=0,numeroTelefono=0;
					while(menuAdministrador!=7){	
						cout<<"-----MENU DE ADMINISTRADOR---------\n";
						cout<<"1)Agregar Empleado\n";
						cout<<"2)Despedir Empleado\n";
						cout<<"3)Empleado con menor sueldo\n";
						cout<<"4)Agregar platillo\n";
						cout<<"5)Empleado con mayor sueldo\n";
						cout<<"6)Promedio de todos los sueldos \n";
						cout<<"7)Cerrar Sesion\n";
						cin>>menuAdministrador;
						if (menuAdministrador==1){
							int agregar1=0;
							do{
								cout<<"-----MENU DE AGREGAR ---------\n";
								cout<<"1)Agregar Chef\n";
								cout<<"2)Agregar LAVA PLATOS\n";
								cout<<"3)Agregar MESEROS\n";
								cout<<"4)SALIR\n";
								cin>>agregar1;
							} while (agregar1<1||agregar1>4);
							if (agregar1==1){//AGREGAR CHEF
								Chef* envioChef;
								envioChef= crearChef();
								listUsuarios.push_back(envioChef);
								dynamic_cast<Administrador*>(listUsuarios[PosUser])->setEmpleadosContratados(1);
								cout<<"Se sumo al array\n";
							}
							if (agregar1==2){//AGREGAR LAAPLATOS
								LavaPlatos* envioLavaplatos;
								envioLavaplatos= crearLavaplatos();
								listUsuarios.push_back(envioLavaplatos);
								dynamic_cast<Administrador*>(listUsuarios[PosUser])->setEmpleadosContratados(1);							
								cout<<"Se sumo al array\n";
							}
							if (agregar1==3){//AGREGAR MESEROS
								Meseros* envioMeseros;
								envioMeseros= crearMeseros();
								listUsuarios.push_back(envioMeseros);
								dynamic_cast<Administrador*>(listUsuarios[PosUser])->setEmpleadosContratados(1);							
								cout<<"Se sumo al array\n";
							}
							if (agregar1==4){//SALIR DE ESTE MENU
								cout<<"Se ha salido con exito! \n";
							}
						}
						if (menuAdministrador==2){
							int posDespedir=0;
							cout<<"Ingrese la posicion del Empleado a Despedir\n";
							for (int i = 0; i < listUsuarios.size(); ++i){
								if (dynamic_cast<Personal*>(listUsuarios[i])){
									cout<<") "<<dynamic_cast<Usuario*>(listUsuarios[i])->getNombre()<<"\n";
								}							
							}
							for (int i = 0; i < listUsuarios.size(); ++i){
								if (posDespedir==i){
							        delete listUsuarios.at(posDespedir);
							        listUsuarios.erase(listUsuarios.begin()+posDespedir);
							        listUsuarios.at(posDespedir)=NULL;
							        cout<<"Se despidio al Empleado correctamente!\n";
								}
							}
						}
						if (menuAdministrador==3){//empleado con menor sueldo
							vector<string> tempmin;
							tempmin = minSueldo(listUsuarios);
							cout<<"---SUELDOS-----\n";
							for (int i = 0; i < tempmin.size(); ++i){
								cout<<tempmin.at(i)<<"\n";
							}
							cout<<"------------------------------\n";						
						}
						if (menuAdministrador==4){//agregar platillo a mesero
							int index=0;
							cout<<"----------MESEROS--------------"<<endl;
							for (int i = 0; i < listUsuarios.size(); ++i){
								if (dynamic_cast<Meseros*>(listUsuarios.at(i))){
									cout<<index<<") ";
									cout<<dynamic_cast<Usuario*>(listUsuarios.at(i))->getNombre()<<"\n";
									index++;
								}						
							}
							cout<<endl;
							cout<<"Ingrese posicion del Meseros que desea agregarle el platillo\n";
							int posMesero=0,cont=0;
							cin>>posMesero;
							for (int i = 0; i < listUsuarios.size(); ++i){
								if (dynamic_cast<Meseros*>(listUsuarios.at(i))){
									if (posMesero==cont){
										cout<<"Ingrese platillo que desea asignarle\n";
										string platillos;
										cin>>platillos;
										dynamic_cast<Meseros*>(listUsuarios.at(i))->setListaPlatillos(platillos);
									}
									cont++;
								}						
							}
						}
						if (menuAdministrador==5){//empleado con mayor sueldo
							vector<string> tempmax;
							tempmax = maxSueldo(listUsuarios);
							cout<<"---SUELDOS-----\n";
							for (int i = 0; i < tempmax.size(); ++i){
								cout<<tempmax.at(i)<<"\n";
							}
							cout<<"\n";
						}
						if (menuAdministrador==6){//promedio de sueldos
							double promedio = PromedioRat(listUsuarios);
							cout<<"EL promedio de sueldos de los empeados es: "<<promedio<<"\n";
						}
						if (menuAdministrador==7){
							ingresarSistema=false;
						}
					}
				}
				if (dynamic_cast<Chef*>(listUsuarios[PosUser])){//MENU DE CHEFS
					int menuChef=0;
					cout<<"-------MENU-----------\n";
					cout<<"1)Gritarle a un LavaPlatos (-50)\n";
					cout<<"2)Agradar a un LavaPlatos(+50)\n";
					cout<<"3)Cerrar Sesion \n";
					cin>>menuChef;
					while(menuChef!=3){
						if (menuChef==1){
							int index=0,posLavaPlatos=0;
							int cont=0;
							cout<<"---------LavaPlatos-------\n";
							for (int i = 0; i < listUsuarios.size(); ++i){
								if (dynamic_cast<LavaPlatos*>(listUsuarios.at(i))){
									cout<<index<<") ";
									cout<<dynamic_cast<Usuario*>(listUsuarios.at(i))->getNombre()<<" con Nivel de motivacion: ";
									cout<<dynamic_cast<LavaPlatos*>(listUsuarios.at(i))->getNivelMotivacion()<<"\n";
									index++;
								}						
							}
							cout<<"\n";
							cout<<"Ingrese a que mesero quiere Gritarle\n";
							cin>>posLavaPlatos;
							for (int i = 0; i < listUsuarios.size(); ++i){
								if (dynamic_cast<LavaPlatos*>(listUsuarios.at(i))){
									if (posLavaPlatos==cont){
										dynamic_cast<LavaPlatos*>(listUsuarios.at(i))->setNivelMotivacion(-50);
									}cont++;
								}								
							}
						}	
						if (menuChef==2){
							int index=0,posLavaPlatos=0;
							int cont=0;
							cout<<"---------LavaPlatos-------\n";
							for (int i = 0; i < listUsuarios.size(); ++i){
								if (dynamic_cast<LavaPlatos*>(listUsuarios.at(i))){
									cout<<index<<") ";
									cout<<dynamic_cast<Usuario*>(listUsuarios.at(i))->getNombre()<<" con Nivel de motivacion: ";
									cout<<dynamic_cast<LavaPlatos*>(listUsuarios.at(i))->getNivelMotivacion()<<"\n";
									index++;
								}						
							}
							cout<<endl;
							cout<<"Ingrese a que mesero quiere Agradar\n";
							cin>>posLavaPlatos;
							for (int i = 0; i < listUsuarios.size(); ++i){
								if (dynamic_cast<LavaPlatos*>(listUsuarios.at(i))){
									if (posLavaPlatos==cont){
										dynamic_cast<LavaPlatos*>(listUsuarios.at(i))->setNivelMotivacion(50);
									}cont++;
								}								
							}
						}
						if (menuChef==3){
							ingresarSistema=false;
						}
					}	
				}
				if (dynamic_cast<LavaPlatos*>(listUsuarios[PosUser])){//MENU DE LAVAPLATOS
					int menuLavaplatos=0;
					cout<<"-------MENU-----------\n";
					cout<<"1)Renunciar \n";
					cout<<"2)Pedir un aumento \n";
					cout<<"3 )Cerrar Sesion \n";
					cin>>menuLavaplatos;
					while(menuLavaplatos!=3){
						if (menuLavaplatos==1){
							if (dynamic_cast<LavaPlatos*>(listUsuarios[PosUser])->getNivelMotivacion()<25){
								cout<<"Usted ha Renunciado "<<dynamic_cast<Usuario*>(listUsuarios[PosUser])->getNombre();
								delete listUsuarios.at(PosUser);
							    listUsuarios.erase(listUsuarios.begin()+PosUser);
							    listUsuarios.at(PosUser)=NULL;
								cout<<"\n";
							}
						}
						if (menuLavaplatos==2){
							if (dynamic_cast<LavaPlatos*>(listUsuarios[PosUser])->getNivelMotivacion()>25){
								dynamic_cast<LavaPlatos*>(listUsuarios[PosUser])->setSueldo(23);
								cout<<"Su sueldo incremento con 23\n";
							}						
						}
						if (menuLavaplatos==3){
							ingresarSistema=false;
						}
					}	
				}
				if (dynamic_cast<Meseros*>(listUsuarios[PosUser])){//MENU DE LAVAPLATOS
					int menuMeseros=0;
					cout<<"-------MENU-----------\n";
					cout<<"1)Entregar platillo Especifico\n";
					cout<<"2)Eliminar platillo Especifico\n";
					cout<<"3)Entregar Lista de platillos\n";
					cout<<"4)Eliminar Lista de platillo\n";
					cout<<"5)Cerrar Sesion \n";
					cout<<"------SU LISTA DE PLATILLOS-----\n";
					for (int i = 0; i < dynamic_cast<Meseros*>(listUsuarios[PosUser])->getListaPlatillos().size(); ++i){
						cout<<dynamic_cast<Meseros*>(listUsuarios[PosUser])->getListaPlatillos().at(i);
					}
					cin>>menuMeseros;
					cout<<endl;
					while(menuMeseros!=5){
						if (menuMeseros==1){
							cout<<"Ingrese que platillo desea entregar\n";
							int posplat=0;
							cin>>posplat;
							dynamic_cast<Meseros*>(listUsuarios[PosUser])->eliminarPlato(posplat);		
						    cout<<"platillo entregado exitosamente!\n";
						}										
						if (menuMeseros==2){
							cout<<"Ingrese que platillo desea eliminar\n";
							int posplat=0;
							cin>>posplat;
							dynamic_cast<Meseros*>(listUsuarios[PosUser])->eliminarPlato(posplat);
						    cout<<"platillo eliminado exitosamente!\n";						
						}
						if (menuMeseros==3){
							dynamic_cast<Meseros*>(listUsuarios[PosUser])->eliminarLista();							
							cout<<"Elimino su Lista de platillos \n";
						}
						if (menuMeseros==4){
							dynamic_cast<Meseros*>(listUsuarios[PosUser])->eliminarLista();
							cout<<"Elimino su Lista de platillos \n";						
						}
						if (menuMeseros==5){
							ingresarSistema=false;
							cout<<"Cerro secion exitosamente!\n";
						}
					}
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
				cout<<"3 )SALIR \n";
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
			if (menuAgregar==1){//AGEGAR CLIENTE
				string direccion="";
				int ratingRest=0;
				cout<<"Ingrese su direccion de hogar: \n";
				cin>>direccion;
				do{
					cout<<"Ingrese Calificacion que le da a nuestro Restaurante: (1-5) \n";
					cin>>ratingRest;
				} while (ratingRest<1||ratingRest>5);
				Cliente* newCliente = new Cliente(userName,password,nombre,edad,id,numeroTelefono, direccion, ratingRest);
				listUsuarios.push_back(newCliente);
				cout<<"El cliente: "<<nombre<<" fue creado con exito. \n";
			}
			if (menuAgregar==2){//AGREGAR ADMINISTRADOR
				Administrador* newAdministrador = new Administrador(userName,password,nombre,edad,id,numeroTelefono, anoContratacion, sueldo,0,0);
				listUsuarios.push_back(newAdministrador);
				cout<<"El Administrador: "<<nombre<<" fue creado con exito. \n";
				cout<<listUsuarios.size()<<endl;
			}
			if (menuAgregar==3){//AGREGAR ADMINISTRADOR
				cout<<"SALIO EXITOSAMENTE! \n";					
			}
		}	
		if (menu1==3){
			int sizevector= listUsuarios.size();
			if (sizevector>0){
				double promedio = PromedioRestaurante(listUsuarios);
				cout<<"EL promedio del restaurante es: "<<promedio<<"\n";
			}else{
				cout<<"Nadie esta ingresado en el sistema\n";
			}
		}
		if (menu1==4){
			ofstream Archivo("Usuarios.txt");
  			if (Archivo.is_open()) {
    			for (int i = 0; i < listUsuarios.size(); i++) {
			    	Archivo<<listUsuarios.at(i)->escritura();
		    	}
    			Archivo.close();
  			}
  			cout<<"Se guardaron EXITOSAMENTE! "<<listUsuarios.size()<<" elementos\n";

		}
		if (menu1==5){
			cout<<"-----------PROBLEMA-----------\n";			
			cout<<"Cuando escribo mis archivos este me altera mis datos(SOlO NUMERICOS), por lo tanto el programa deja de funcionar correctamente\n";
			cout<<"Por lo que les pido revisen mis clases en el .cpp ya que el metodo de casteo falla y no me funciono el metodo To_String() \n";
			cout<<"Aun incluyendo el -std=c++11 porque si investigue bastante y no encontre mi problema.\n";
			cout<<"\n";

			cout<<"Pero si desea cargar aun asi el archivo presione el numero 1 y luego ENTER \n";
			int cargar123=0;
			cin>>cargar123;
			if (cargar123==1){
				listUsuarios= RecuperacionDatos();
				cout<<"SE CARGARON "<<listUsuarios.size()<<" usuarios que usted habia guardado\n";
			}else{
				cout<<"Perfecto, no se cargaron. \n";
			}
		}
	}
    return 0;
}

Chef* crearChef(){
	string userName="",password="",nombre="",id="";
	int edad=0,numeroTelefono=0;
	string anoContratacion="";
	int sueldo=0;
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
	cout<<"Ingrese ano de Contratacion \n";
	cin>>anoContratacion;
	cout<<"Ingrese sueldo\n";
	cin>>sueldo;
	cout<<"Ingrese su platillo favorito: \n";
	string favPlato="";
	cin>>favPlato;
	Chef* newChef = new Chef(userName,password,nombre,edad,id,numeroTelefono, anoContratacion, sueldo,favPlato);
	cout<<"El Chef: "<<nombre<<" fue creado con exito. \n";
	return newChef;
}

LavaPlatos* crearLavaplatos(){
	string userName="",password="",nombre="",id="";
	int edad=0,numeroTelefono=0;
	string anoContratacion="";
	int sueldo=0;
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
	cout<<"Ingrese ano de Contratacion \n";
	cin>>anoContratacion;
	cout<<"Ingrese sueldo\n";
	cin>>sueldo;
	LavaPlatos* newLavaPlatos = new LavaPlatos(userName,password,nombre,edad,id,numeroTelefono, anoContratacion, sueldo,50);
	return newLavaPlatos;
}


void escribir(vector<Usuario*> MiVector){
  ofstream Archivo("Usuarios.txt");
  if (Archivo.is_open()) {
    for (int i = 0; i < MiVector.size(); i++) {
      Archivo<<MiVector.at(i)->escritura();
    }
    Archivo.close();
  }
}

Meseros* crearMeseros(){
	string userName="",password="",nombre="",id="";
	int edad=0,numeroTelefono=0;
	string anoContratacion="";
	int sueldo=0;
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
	cout<<"Ingrese ano de Contratacion \n";
	cin>>anoContratacion;
	cout<<"Ingrese sueldo\n";
	cin>>sueldo;
	Meseros* newMeseros = new Meseros(userName,password,nombre,edad,id,numeroTelefono, anoContratacion, sueldo);
	return newMeseros;
}


vector<Usuario*> RecuperacionDatos(){
  vector<Usuario*> Temp;
  fstream Archivo("Usuarios.txt");
  if (Archivo.is_open()) {
  while(!Archivo.eof()){
    string object,usuario="",password="",nombre="",id="",numero="",edad1="",anocontratacion="",salrio1="";
    int edad=0;
    int numerofin=0;
    double salario=0;
    getline(Archivo,object,';');
    if (object == "L") {
      int empleadosContratados, Empleadosdespedidos;
      string contras,despes;
      getline(Archivo,usuario,';');
      getline(Archivo,password,';');
      getline(Archivo,nombre,';');
      getline(Archivo,edad1,';');
      edad = atoi(edad1.c_str());
      getline(Archivo,id,';');
      getline(Archivo,numero,';');
      numerofin = atoi(numero.c_str());
      getline(Archivo,anocontratacion,';');
      getline(Archivo,salrio1,';');
      salario = stod(salrio1);
      getline(Archivo,contras,';');
      empleadosContratados = atoi(contras.c_str());
      getline(Archivo,despes,',');
      Empleadosdespedidos = atoi(despes.c_str());
      Temp.push_back(new Administrador(usuario,password,nombre,edad,id,numerofin,anocontratacion,salario,empleadosContratados,Empleadosdespedidos));
    }

    if (object == "H") {
      string plato;
      getline(Archivo,usuario,';');
      getline(Archivo,password,';');
      getline(Archivo,nombre,';');
      getline(Archivo,edad1,';');
      edad = atoi(edad1.c_str());
      getline(Archivo,id,';');
      getline(Archivo,numero,';');
      numerofin = atoi(numero.c_str());
      getline(Archivo,anocontratacion,';');
      getline(Archivo,salrio1,';');
      salario = stod(salrio1);
      getline(Archivo,plato,',');
      Temp.push_back(new Chef(usuario,password,nombre,edad,id,numerofin,anocontratacion,salario,plato));
    }


    if (object == "C") {
        string direccion,srate;
    	int rate;
		getline(Archivo,usuario,';');//USER
		getline(Archivo,password,';');//PASS 
		getline(Archivo,nombre,';');//NAME      
		getline(Archivo,edad1,';');
		edad = atoi(edad1.c_str());//EDAD
		getline(Archivo,id,';');//ID
		getline(Archivo,numero,';');
      	numerofin = atoi(numero.c_str());//NUMEO
      	getline(Archivo,direccion,';');//DIRECCION
      	getline(Archivo,srate,',');
      	rate = stoi(srate);//CALIFICACION
      	Temp.push_back(new Cliente(usuario,password,nombre,edad,id,numerofin,direccion,rate));
    }

    if (object == "M") {
   	 	 getline(Archivo,usuario,';');
     	 getline(Archivo,password,';');
   		  getline(Archivo,nombre,';');
   		  getline(Archivo,edad1,';');
   		  edad = atoi(edad1.c_str());
   		  getline(Archivo,id,';');
   		  getline(Archivo,numero,';');
   		  numerofin = atoi(numero.c_str());
   		  getline(Archivo,anocontratacion,';');
   		  getline(Archivo,salrio1,',');
   		  salario = stod(salrio1);
   		  Temp.push_back(new Meseros(usuario,password,nombre,edad,id,numerofin,anocontratacion,salario));
    }
    if (object == "L") {
      string motivacion1;
      int motivacion;
      getline(Archivo,usuario,';');
      getline(Archivo,password,';');
      getline(Archivo,nombre,';');
      getline(Archivo,edad1,';');
      edad = atoi(edad1.c_str());
      getline(Archivo,id,';');
      getline(Archivo,numero,';');
      numerofin = atoi(numero.c_str());
      getline(Archivo,anocontratacion,';');
      getline(Archivo,salrio1,';');
      salario = stod(salrio1);
      getline(Archivo,motivacion1,',');
      motivacion = atoi(motivacion1.c_str());
      Temp.push_back(new LavaPlatos(usuario,password,nombre,edad,id,numerofin,anocontratacion,salario,motivacion));
    }
  }

    Archivo.close();
    return Temp;

  }
}

vector<string> maxSueldo(vector<Usuario*> listUsuarios){
	vector<string> temp;	
	int maxSueldo=0;
	for (int i = 0; i < listUsuarios.size(); ++i){
		if (dynamic_cast<Personal*>(listUsuarios[i])){
			if (dynamic_cast<Personal*>(listUsuarios[i])->getSueldo()>maxSueldo){
				maxSueldo= dynamic_cast<Personal*>(listUsuarios[i])->getSueldo();
			}
		}		
	}
	int sald=0;
	std::stringstream sstm;
	for (int i = 0; i < listUsuarios.size(); ++i){
		if (dynamic_cast<Personal*>(listUsuarios[i])->getSueldo()==maxSueldo){
			string nameSueldo="",sueldo="";
			nameSueldo+=dynamic_cast<Usuario*>(listUsuarios[i])->getNombre();
			sald=dynamic_cast<Personal*>(listUsuarios[i])->getSueldo();
			string envio="";
			envio = nameSueldo;
			envio+=" con: ";
			sstm<<sald;
			sueldo= sstm.str();
			envio+=sueldo;
			temp.push_back(envio);

		}	
	}
	return temp;
}
vector<string> minSueldo(vector<Usuario*> listUsuarios){
	vector<string> temp;	
	int maxSueldo=0;
	for (int i = 0; i < listUsuarios.size(); ++i){
		if (dynamic_cast<Personal*>(listUsuarios[i])){
			if (dynamic_cast<Personal*>(listUsuarios[i])->getSueldo()>maxSueldo){
				maxSueldo= dynamic_cast<Personal*>(listUsuarios[i])->getSueldo();
			}
		}		
	}
	for (int i = 0; i < listUsuarios.size(); ++i){
		if (dynamic_cast<Personal*>(listUsuarios[i])){
			if (dynamic_cast<Personal*>(listUsuarios[i])->getSueldo()<maxSueldo){
				maxSueldo= dynamic_cast<Personal*>(listUsuarios[i])->getSueldo();
			}
		}		
	}	

	int sald=0;
	std::stringstream sstm;
	for (int i = 0; i < listUsuarios.size(); ++i){
		if (dynamic_cast<Personal*>(listUsuarios[i])->getSueldo()==maxSueldo){
			string nameSueldo="",sueldo="";
			nameSueldo+=dynamic_cast<Usuario*>(listUsuarios[i])->getNombre();
			sald=dynamic_cast<Personal*>(listUsuarios[i])->getSueldo();
			string envio="";
			envio = nameSueldo;
			envio+=" con: ";
			sstm<<sald;
			sueldo= sstm.str();
			envio+=sueldo;
			temp.push_back(envio);

		}	
	}
	return temp;
}
double PromedioRat(vector<Usuario*> Lista){
	int cantidad= 0;
	int total=0;
	for (int i = 0; i < Lista.size(); ++i){//RECORRO MI VECTOR 
		if (dynamic_cast<Personal*>(Lista[i])){//VERIFICO QUE EL OBJECT SEA PERSONAL 
			int calificacion = dynamic_cast<Personal*>(Lista[i])->getSueldo();//AGARRO EL SUELDO DE EL PERSONAL QUE ENTRO 
			total+=calificacion;
			cantidad++;			
		}

	} 
	return total/cantidad;

}

double PromedioRestaurante(vector<Usuario*> Lista){
	int cantidad= 0;
	int total=0;
	for (int i = 0; i < Lista.size(); ++i){
		if (dynamic_cast<Cliente*>(Lista[i])){
			int calificacion = dynamic_cast<Cliente*>(Lista[i])->getRatingRest();
			total+=calificacion;
			cantidad++;			
		}

	} 
	return total/cantidad;

}
