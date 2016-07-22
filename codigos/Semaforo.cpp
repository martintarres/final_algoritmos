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
class Semaforo {
private:
	int cantVehiculos;
	bool verde;
	bool mano;  // si se puede avanzar en esa direccion, es mano = true;
	int ubicacion;
//	Vehiculos *v;
public: 
	Semaforo(){
		cantVehiculos=-1;
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
	cout << s.getUbicacion() << endl;
	cout << "está activado? :" << s.ponerVerde()<< s.ponerVerde() << s.ponerVerde() << endl;
}

//int Semaforo::getCantDeVehiculos()*/
