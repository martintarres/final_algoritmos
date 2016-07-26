#include <iostream>
//#include "Nodo.cpp"
#include <string.h> 
#include <stdlib.h> 
#include <fstream> 
#include "heapSemaforo.cpp"

using namespace std;
const int tamano_arcos = 420;
const int num_listas= 64;


class Nodo {
	public:
	Edge dato;
	Nodo *next;
	Nodo (Edge numero, Nodo *next_ptr=NULL){
		dato=numero, next= next_ptr;
	}
};

class Lista{
	private:
		Nodo *cabeza;
		
	public:
		Lista(){
			cabeza=NULL;
		}
		void agregar(Edge);
		void mostrar();
		int getDest();
		int getSource();
};

int Lista::getDest(){
	Nodo *aux;
	

	aux=cabeza;
	
	if(cabeza!=NULL){

		return aux->dato.get_dest();

	}
	

}

int Lista::getSource(){
		if(cabeza!=NULL){
		return cabeza->dato.get_source();

	cabeza=cabeza->next;

	}
}

	void Lista::agregar(Edge edge){
		cabeza= new Nodo(edge, cabeza);

	}
	
	void Lista::mostrar(){
		

		
		if (cabeza!=NULL){
			
		cout<<"("<< cabeza->dato.get_source()<<", ";
		cout<< cabeza->dato.get_dest()<<", ";
		cout<< cabeza->dato.get_weight()<<" )";
		
		cabeza=cabeza->next;
		mostrar();
	

	}
}




int main(){

	Lista *l= new Lista();	
   	Lista a[num_listas];
   	Vehiculos v;
   	heapSemaforos t;
   	heapVehiculos g;
   	Semaforo s;//=  Semaforo(e); 
   	Vehiculos arveh[20];

int numeroo, arregloo[100], qq;
int h=0;
int k = 0;
int q=0,arreglo[tamano_arcos],numero; 


ifstream archivo("ficheroTexto.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 

arreglo[q++]=numero;	

}

ifstream archivoo("ficheroAutos.txt"); 
if(archivoo.good()){ 
while(archivoo>>numeroo) 

arregloo[qq++]=numeroo;
}
int ggg=0;
for(int j=0;j<qq;j++) {
	Vehiculos v;

		v.set_patente(arregloo[j]);
		v.set_origen(arregloo[j+1]);
		v.set_final(arregloo[j+2]);
		v.set_prioridad(arregloo[j+3]);
		

		arveh[ggg]=v;
		j=j+3;
		ggg++;	

	}


	

for(int j=0;j<q;j++) {
	
	Edge e;



e.set_source(arreglo[j]);
e.set_dest(arreglo[j+1]);
e.set_weight(arreglo[j+2]);


s= Semaforo (e);

	int contador=0;
for(int i=0; i<20;i++){

	if(arveh[i].get_origen()== s.getUbicacion() && arveh[i].estado()==false){
		s.insertar(arveh[i]);

			e.set_weight(s.getCantDeVehiculos());

		arveh[i].activarAdentro();
		}

		

	}
	


if (e.get_source()==arreglo[j-3]||e.get_source()==1)
{

	l->agregar(e);
	a[k]=*l;

}
else
{
	k++;
	
	Lista *l1=new Lista();
	l1->agregar(e);
	a[k]= *l1;
	l =l1;

}


j=j+2;

t.insert(s);
s.insertar(v);

}


cout<<endl;
cout<< "Soy ciudad :"<<endl;
for(int i=0; i<64; i++){
	
	a[i].mostrar();
	cout<<endl;
	}

cout<< " maxHeapSemaforo"<<endl<<endl;
//t.print();
cout<<endl<<endl<<endl;

//cout<<" maxHeapVehiculos"<<endl<<endl;
//cout<<" el 0"<<endl;
//cout<< t.recorre(0).getHeap().esvaciodesde()<<endl;
//cout<< t.recorre(1).getHeap().esvaciodesde()<<endl;
//cout<< t.recorre(2).getHeap().esvaciodesde()<<endl;
//cout<< t.recorre(3).getHeap().esvaciodesde()<<endl;
t.recorre(0).getHeap().print();
t.recorre(1).getHeap().print();
t.recorre(2).getHeap().print();
t.recorre(3).getHeap().print();
cout<<endl;

cout<< t.recorre(0).getCantDeVehiculos()<<endl;
cout<< t.recorre(1).getCantDeVehiculos()<<endl;
cout<< t.recorre(2).getCantDeVehiculos()<<endl;
cout<< t.recorre(3).getCantDeVehiculos()<<endl;
//s.eliminar();
t.recorre(0).eliminaVehiculos();

t.recorre(0).getHeap().print();
t.recorre(1).getHeap().print();
t.recorre(2).getHeap().print();
t.recorre(3).getHeap().print();
cout<<endl;

cout<< t.recorre(0).getCantDeVehiculos()<<endl;
cout<< t.recorre(1).getCantDeVehiculos()<<endl;
cout<< t.recorre(2).getCantDeVehiculos()<<endl;
cout<< t.recorre(3).getCantDeVehiculos()<<endl;

}


