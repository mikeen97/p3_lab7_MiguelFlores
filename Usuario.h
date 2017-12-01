#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef USUARIO_H
#define USUARIO_H
class Usuario{
	protected:
		string UserName;
		string Password;
		string Nombre;
		int Edad;
		string Id;
		int NumeroTelefonico;
	public:
		Usuario(string,string,string,int,string,int);
		Usuario();
		string getUserName();
		void setUserName(string);

		string getPassword();
		void setPassword(string);

		string getNombre();
		void setNombre(string);

		int getEdad();
		void setEdad(int);

		string getId();
		void setId(string);

		int getNumeroTelefonico();
		void setNumeroTelefonico(int);

};
#endif