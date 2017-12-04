main:    main.cpp Usuario.o Cliente.o Personal.o Administrador.o Chef.o LavaPlatos.o Meseros.o 
	g++ -std=c++11 main.cpp Usuario.o Cliente.o Personal.o Administrador.o Chef.o LavaPlatos.o Meseros.o -o main
main.o:	main.cpp Usuario.h Cliente.h Personal.h Administrador.h Chef.h LavaPlatos.h Meseros.h 
	g++ -std=c++11 -c main.cpp
Usuario:	Usuario.cpp Usuario.h
	g++ -std=c++11 Usuario.cppCliente:	Cliente.cpp Cliente.h
	g++ -std=c++11 Cliente.cppPersonal:	Personal.cpp Personal.h
	g++ -std=c++11 Personal.cppAdministrador:	Administrador.cpp Administrador.h
	g++ -std=c++11 Administrador.cppChef:	Chef.cpp Chef.h
	g++ -std=c++11 Chef.cppLavaPlatos:	LavaPlatos.cpp LavaPlatos.h
	g++ -std=c++11 LavaPlatos.cppMeseros:	Meseros.cpp Meseros.h
	g++ -std=c++11 Meseros.cpp
clean:
	rm  *.o main 





	