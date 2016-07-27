#include <iostream>
#include "nodo1.cpp"
//using namespace std;

class pepito{
	private:
		int dist[140];
		int previo[140];
		heapSemaforos t;
		Semaforo auxiliar;
		int chota;
		bool visitado[140];
		
public:
	pepito(){
		for(int i=0; i< 140; i++){
		
		visitado[ i ] = false;
		dist[i]=9999;
		previo[i]=-1;
		}
		t;
		
	}
	void dijkstra(Lista a[], Semaforo , heapSemaforos );
	void relajacion(int actual, int adyacente, int peso, Semaforo);
	void print (int);
};

void pepito::dijkstra(Lista a[], Semaforo s, heapSemaforos t){
	this->t=t;
	int numarreglo;
	int adyacente;
	int peso;
	//dist[t.recorre(0)]=0;
//	Lista a;
//	b=a;
	while (t.size()-t.lugaresDisponibles() != 0){
		auxiliar=t.eliminarFondo();
		chota = auxiliar.getOrigen()-1;
		if(visitado[chota])	continue;
			visitado[chota]= true;
		//	auxiliar.setFuiVisitado();
			
			for(int i=0; i<a[chota].getContador(); i++){
				peso=a[chota].pesos(i);
				adyacente= a[chota].destinos(i);
				if(!visitado[adyacente]){
					relajacion(chota, adyacente, peso, auxiliar);
				}
			}
			
			
	//	numarreglo=auxiliar.getOrigen()-1;
	//	b[numarreglo].
		
		}
		cout<< "Distancias mas cortas iniciando en Semaforo "<< s.getOrigen()<<endl;
		
    for( int i = 1 ; i <= 140 ; ++i ){
    	cout<< "Semaforo " << i << " distancia mas corta " << dist[i]<< endl;
       // printf("Vertice %d , distancia mas corta = %d\n" , i , distancia[ i ] );
    }
	cout<<"Impresion del camino mas corto "<< endl << "Ingrese semaforo destino "<<endl;;
//    puts("\n**************Impresion de camino mas corto**************");
   // printf("Ingrese vertice destino: ");
    int destino;
    cout<< destino <<endl;
   // scanf("%d" , &destino );
    //print( destino );
    //printf("\n");
}

void pepito::relajacion(int actual, int adyacente, int peso, Semaforo auxiliar){
	if( actual + peso < adyacente){
		adyacente = actual + peso;
		adyacente = actual;
		t.insert(auxiliar);
	}
}

void pepito::print(int destino){
	
	if( previo[ destino ] != -1 )    //si aun poseo un vertice previo
        cout<< previo [destino];
	//	print( previo[ destino ] );  //recursivamente sigo explorando
  //  printf("%d " , destino );   
}

int main(){
	


	Lista *l= new Lista();	
   	Lista a[num_listas];
   	Vehiculos v;
   	heapSemaforos t;
   	heapVehiculos g;
   	Semaforo s;//=  Semaforo(e); 
   	Vehiculos arveh[20];
   	grafo df;

int numeroo, arregloo[100], qq;
int h=0;
int k = 0;
int q=0,arreglo[tamano_arcos],numero; 


ifstream archivo("pDijkstra.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 

arreglo[q++]=numero;	

}

ifstream archivoo("ficheroAutos.txt"); 
if(archivoo.good()){ 
while(archivoo>>numeroo) 

arregloo[qq++]=numeroo;
}
/*
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
//	df.djistra(v.get_origen(), v.get_final());
//	df.print(v.get_origen());
	
	}

*/
	

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
//	cout<<a[i].tamList()<<endl;
	}
//t.print();
cout<<endl;
 //a[0].mostrar();	
	pepito p;
	t.print();
//	int inicial;
//	cout<< " Ingrese semaforo incial "<<endl;
//	cin>>inicial;
	p.dijkstra(a, t.recorre(0), t); 
//	dijkstra(inicial);
	
//cout<< " djistra" << endl;





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
	
	
	
	
	/*
	int E , origen, destino , peso , inicial;
   // scanf("%d %d" , &V , &E );
    while( E-- ){
        scanf("%d %d %d" , &origen , &destino , &peso );
        ady[ origen ].push_back( Node( destino , peso ) ); //consideremos grafo dirigido
        //ady[ destino ].push_back( Node( origen , peso ) ); //grafo no dirigido
    }
    printf("Ingrese el vertice inicial: ");
    scanf("%d" , &inicial );
    dijkstra( inicial );
    return 0;*/
//}
