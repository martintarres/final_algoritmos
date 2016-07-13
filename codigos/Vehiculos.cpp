#include <iostream>
using namespace std;

class Vehiculos{
	private:
		int origen;
		int final;
		int prioridad;
		int patente;
		
	public:
		Vehiculos(int patente, int final){
			this->patente=patente;
			this->final=final;
			//this->prioridad=prioridad;   //Sacamos la prioridad del constructor. A lo sumo agregarla de nuevo.
		}
		void set_origen(int);
		void set_final (int);
		void set_prioridad(int);
		int get_origen();
		int get_final();
		int get_patente();
		int get_prioridad();
};

void Vehiculos::set_origen(int orig){
	origen=orig;
}

void Vehiculos::set_final(int fin){
	final=fin;	
}
	void Vehiculos::set_prioridad(int priori)
	{
		prioridad = priori;
	}

int Vehiculos::get_origen(){
	return origen;
}

int Vehiculos::get_final(){
	return final;
}
int Vehiculos::get_patente(){
	return patente;
}

int Vehiculos::get_prioridad(){
	return prioridad;
}

/*int main(){                                                          la clase main fue implementada
	const int max=6;												   solo para hacer la prueva.
	for (int i=0; i<max;i++){										   La saco para subirla a git y que 
		Vehiculos *v= new Vehiculos(00+i,i+1);						   no tire errores.
		v->set_origen(i);
		v->set_prioridad(1);
	cout<< "origen: "<< v->get_origen()<< endl;
	cout<< "final: "<< v->get_final()<< endl;
	cout<< "patente: "<< v->get_patente()<< endl;
	
	if (i==3)
	{
		v->set_prioridad(0);
	}
	cout << "prioridad: " << v->get_prioridad() << endl;
}
}
*/



