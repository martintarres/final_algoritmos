#include <iostream>
#include <math.h>

#include "Edge.cpp"
#include "maxHeapVehiculos.cpp"
#include <string.h> 
#include <stdlib.h> 
#include <fstream> 
//#include "maxHeapSemaforo.cpp"

using namespace std;

//const int cant=10;
class Semaforo : public Heaparr{
private:
	int cantVehiculos;
	bool verde;
	bool mano;  // si se puede avanzar en esa direccion, es mano = true;
	int ubicacion;
	Heaparr h;
//	Vehiculos *v;
public: 
	Semaforo(){
		cantVehiculos=-1;
		 h;
		
	}
	Semaforo(Edge e);
	int getCantDeVehiculos();
	void setCantDeVehiculos(int);
	bool esMano();
	bool ponerVerde(); //pone en verde. A su vez da un booleano que ayuda a saber su estado;
	int getUbicacion();
	
	
};

Semaforo::Semaforo(Edge e)
		{
		ubicacion = e.get_dest();
		cantVehiculos = e.get_weight();
		verde = false;
		mano = false;
		h;
		
	}

int Semaforo::getCantDeVehiculos()
{
	return cantVehiculos;
}

int Semaforo::getUbicacion()
{
	return ubicacion;
}

bool Semaforo::ponerVerde()   //Saca el verde si está en verde y al revés.
{
	if (verde){
		verde = false;
	}else {
		verde = true;
	}
	return verde;
}

bool Semaforo::esMano()
{
	if(mano){
		return true;
	}else
	return false;

}

void Semaforo::setCantDeVehiculos(int cant){
	cantVehiculos=cant;
}


/*
int main()
{
	Edge e =  Edge(5,10,20);
	Semaforo s=  Semaforo(e);
//	Heaparr h;
 	Vehiculos v;
 	v.set_origen(1);
 	v.set_final(2);
 	v.set_patente(0);
 	v.set_prioridad(0);
 		Vehiculos v1;
 	v1.set_origen(1);
 	v1.set_final(9);
 	v1.set_patente(1);
 	v1.set_prioridad(1);
 	
 	s.insert(v);
 	s.insert(v1);
 	
 	s.print();
 	
/*	cout << s.getUbicacion() << endl;
	cout << "está activado? :" << s.ponerVerde()<< s.ponerVerde() << s.ponerVerde() << endl;
	*/
//}

//int Semaforo::getCantDeVehiculos()*/
