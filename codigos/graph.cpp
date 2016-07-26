#include<iostream>
//#include "Edge.cpp"
//#include "nodo1.cpp"
#define MAX 64
#define INF 9000
using namespace std;

class grafo : public Nodo{

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
/*
int main(){
	
	grafo g;
	g.djistra(5,9);
	g.print(9);
}*/

