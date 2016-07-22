#include <iostream>
//#include "Nodo.cpp"
#include <string.h> 
#include <stdlib.h> 
#include <fstream> 
#include "maxHeapSemaforo.cpp"

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
};

	void Lista::agregar(Edge edge){
		cabeza= new Nodo(edge, cabeza);
		//num_items ++;
	}
	
	void Lista::mostrar(){
		

		
		if (cabeza!=NULL){
		cout<<"("<< cabeza->dato.get_source()<<", ";
		cout<< cabeza->dato.get_dest()<<", ";
		cout<< cabeza->dato.get_weight()<<" )";
		cabeza=cabeza->next;
		mostrar();
	
	//	return cabeza->dato.get_dest();
	}
}

//const int n=2;	

int main(){
	
	Lista *l= new Lista();	
       
	
	Lista a[num_listas];

int h=0;
int q=0,arreglo[tamano_arcos],numero; 


ifstream archivo("ficheroTexto.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 


arreglo[q++]=numero;	

//Lista *l= new Lista();
//Lista *l1=new Lista();
	Heaparr1 t;
	//Heaparr v;
int k = 0;
for(int j=0;j<q;j++) {
	//Heaparr1 t;
	Edge e;
//	Edge e1;


e.set_source(arreglo[j]);//.arreglo[j]<<" =1"<<endl;
e.set_dest(arreglo[j+1]);//[j+1]<<" =2"<<endl;
e.set_weight(j*2);
Semaforo s=  Semaforo(e); 
t.insert(s);


if (e.get_source()==arreglo[j-3]||e.get_source()==1)//|| e.get_source() == -1)
{

	l->agregar(e);
	a[k]=*l;
	a[k].mostrar();
}
else
{
	k++;
	
	Lista *l1=new Lista();
	l1->agregar(e);
	a[k]= *l1;
	l =l1;
	a[k].mostrar();
}

cout<<endl;
j=j+2;




}

 t.print();

}
else{ 
cout<<"El archivo no se encuentra\n"; 
} /*
for(int j=0;j<q;j++) {
a[j].mostrar();
}
	*/
	a[4].mostrar();
/*
		Heaparr g;
	
	
	int numeroo, arregloo[100], c=0;
ifstream archivoo("ficheroAutos.txt"); 
if(archivoo.good()){ 
while(archivoo>>numeroo) 
arregloo[c++]=numeroo;


for(int j=0;j<c;j++) {
	Vehiculos *v=new Vehiculos();

		v->set_patente(arregloo[j]);
		v->set_origen(arregloo[j+1]);
		v->set_final(arregloo[j+2]);
		v->set_prioridad(arregloo[j+3]);
		g.insert(*v);
		
	
	
		
		
	//	
	//cout<< "patente: "<< v->get_patente()<< endl;
//	cout<< "origen: "<< v->get_origen()<< endl;
//	cout<< "final: "<< v->get_final()<< endl;
	
//	cout << "prioridad: " << v->get_prioridad() << endl;
	
	j=j+3;
}
g.print();


}

*/

}
