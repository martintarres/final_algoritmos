#include <iostream>
//#include "Nodo.cpp"
#include <string.h> 
#include <stdlib.h> 
#include <fstream> 
#include "heapSemaforo.cpp"
//#include "graph.cpp"
#define MAX 64
#define INF 9000

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
		int tamList();
		int recorrerDest();
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

	int Lista::tamList(){
		int contador=0;
		if(cabeza!=NULL){
			contador++;
			cabeza=cabeza->next;
		}
	}
	
	class grafo {

	public:
		Lista ady[MAX];
		int distancia[MAX];
		bool visitado[MAX];
		int previo[MAX];
		heapSemaforos colaPrioridad;
		int V ; //numero de vertices
		
	public:
		grafo();
		void init();
		void djistra(int origen,int destino);
		void relajacion(int actual, int adyacente, int peso);
		void print(int destino);
	
};

 grafo::grafo(){
	for(int i=0; i<=MAX;i++)
	{
		//HeapMinEsquinas ColaPrioridad=new HeapMinEsquinas();
		distancia[i]=INF;
		visitado[i]=false;
		previo[i]=-1;
	}
}
void grafo::djistra(int origen,int destino)
{	//init();
	//Edge arco=new Edge(origen,inf,0);		//no estoy seguro si el peso se debe crear con 0
	//Nodo nodo=new Nodo(arco,NULL);
//	HeapMinNodo colaPrioridad=new HeapMinNodo(nodo);
	Semaforo aux;
	colaPrioridad.insert(colaPrioridad.recorre(origen));
	distancia[origen]=0;
	int actual, adyacente, peso;
		while(colaPrioridad.size()==0){
			aux= colaPrioridad.eliminarFondo(); //extraer o eliminar de minHeapNodos VER BIEN
			actual= aux.getUbicacion();
			
		if(visitado[actual])
			continue;
		
		visitado[actual]=true;				
			
		for(int i=0;i<ady[actual].tamList();i++){
			
			adyacente=ady[actual].getDest();  /// a lo mejor tendria que recorrerla con un metodo parecido al mostrar de lista
			peso=aux.getCantDeVehiculos();
			if(!visitado[adyacente]){
			
			relajacion(actual,adyacente,peso);	
				
			}
			
		}
		}
		
}
void grafo::relajacion(int actual, int adyacente, int peso){
	
	if(distancia[actual]+peso<distancia[adyacente])
		distancia[adyacente]=distancia[actual]+peso;
		previo[adyacente]=actual;
	
}

void grafo::print(int destino){
	if(previo[destino] != -1){
		print (previo [destino]);
			cout<<destino<<endl;
	}
}
	
/*	int Lista::recorrerDest(){
			if (cabeza!=NULL){
		
		int a;
	//	cout<<"("<< cabeza->dato.get_source()<<", ";
		return cabeza->dato.get_dest();
	//	cout<< cabeza->dato.get_weight()<<" )";
		
		cabeza=cabeza->next;
		recorrerDest();
	

	}
	}
*/



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
/*
for(int i=0; i<64; i++){
	
	a[i].mostrar();
	cout<<endl;
	}*/
cout<< " djistra" << endl;
grafo df;
df.djistra(1,15);
df.print(15);

}
/*
for(int i=0 ; i<1; i++){
	cout<< a[1].recorrerDest();
}*/
/*
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

*/
