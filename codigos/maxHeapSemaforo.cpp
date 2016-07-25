#include <iostream>
#include "Semaforo.cpp"
//#incude "Edge.cpp"

using namespace std;

const int cantt=200;

class Heaparr1 : public Semaforo {
public:
    Heaparr1();
    void insert(Semaforo da);
    int getLeft(int i) { return 2 * i + 1; }
    int getRight(int i) { return 2 * i + 2; }
    int getParent(int i) { return (i - 1) / 2; }
    void print();
    void Build_Max_Heap(Semaforo heapArray[], int heap_size);
    void Max_Heapify(Semaforo heapArray[], int i, int heap_size);
    void heapSort(Semaforo heapArray[]);
    int lugaresDisponibles();
    int size();
    void eliminar();
    int esvaciodesde();
    Semaforo recorre(int);

    

private:
    int num;
   // int* maxHeap;
  //  int index;
    int i;
   Semaforo vector[cantt];
   Semaforo aux;
  // Edge e;
  Semaforo s;

};

Heaparr1::Heaparr1(){
//	Semaforo vector[cantt];
	Semaforo s;
} 
    

int Heaparr1::lugaresDisponibles(){
	int contador=cantt;
	for(int i=0; i<cantt;i++){
		
			if(vector[i].getCantDeVehiculos()>=0){
			
		contador--;
		}
	}
	return contador;
}

int Heaparr1::size(){
	int contador=0;
	for(int i=0; i<cantt;i++){
		contador++;
	}
	return contador;
}

int Heaparr1::esvaciodesde(){
	for(int i=0 ; i<cantt; i++){
		if(vector[i].getCantDeVehiculos()== -1){
	
			return i;
		}
	
	}

}
void Heaparr1::insert(Semaforo da) {

	if(lugaresDisponibles()>0){

	vector[esvaciodesde()]=da;
	}	else {
	cout<<"Cola llena"<< endl;
	}
	
	heapSort( vector);

}

void Heaparr1::print(){
	for(int i=0;i<cantt;i++)	{
	//	cout<< "iteracion "<<i<<endl;
	cout<<vector[i].getCantDeVehiculos()<<endl;//->print();
	//cout<<vector[i].get_origen()<<endl;
//	cout<<vector[i].get_final()<<endl;
//	cout<<vector[i].get_prioridad()<<endl;
	
}
}

Semaforo Heaparr1::recorre(int x){
	return vector[x];
}


void Heaparr1::Max_Heapify(Semaforo heapArray[], int i, int heap_size) {
    // int n = size;
    int largest = 0;
    int l = getLeft(i);
    int r = getRight(i);

    if ((l < heap_size) && (heapArray[l].getCantDeVehiculos() < heapArray[i].getCantDeVehiculos())) {
        largest = l;
    } else {
        largest = i;
    }

    if ((r < heap_size) && (heapArray[r].getCantDeVehiculos() < heapArray[largest].getCantDeVehiculos())) {
        largest = r;
    }

    if (largest != i) {
        swap(heapArray[i], heapArray[largest]);
        Max_Heapify(heapArray, largest, heap_size);
    }
    return;
}
void Heaparr1::heapSort(Semaforo heapArray[]) {
    //size = heap_size;
    int n = size ();
    Build_Max_Heap(heapArray, size());

    for (int i = n - 1; i >= 1; i--) {
        swap(heapArray[0], heapArray[i]);
        n = n - 1;
        Max_Heapify(heapArray, 0,n);
    }
}

void Heaparr1::Build_Max_Heap(Semaforo heapArray[], int heap_size) {
    int n = size();
    for (int i = floor((n - 1) / 2); i >= 0; i--) {
        Max_Heapify(heapArray, i, heap_size);
    }
    return;
}

void Heaparr1::eliminar()
{
	//const int pepito=-1;
	//Semaforo aux;
	aux = vector [0];
	for(int i=0; i< cantt ; i++){
	if((vector[i+1].getCantDeVehiculos()==-1) && (vector[i].getCantDeVehiculos() != -1)){
		vector[0]= vector[i];
		vector [i].setCantDeVehiculos(-1) ;
	//	vector [i].set_origen(-1);
	//	vector [i].set_final(-1);
	//	vector [i].set_patente(-1);

}else {
	if(lugaresDisponibles()==0){
	vector [0].setCantDeVehiculos(-1) ;
	//	vector [0].setCant(-1);
	//	vector [0].set_final(-1);
	//	vector [0].set_patente(-1);
	}
	}
}
 heapSort( vector);
	
//aux1=aux;
//return aux;
}	

/*
int main(){

		Edge e =  Edge(5,10,2);
	Semaforo s=  Semaforo(e);
	Edge e1= Edge (99,98,97);
	Semaforo s1= Semaforo (e1);
		Edge e2= Edge (1024,988,95547);
	Semaforo s2= Semaforo (e2);

	Heaparr1 t;
	t.insert(s1);
	cout<<endl;
	t.print();
	t.insert(s);
	cout<<endl;
	t.print();
	cout<<endl;
	t.insert(s2);
	t.print();
	cout<<endl;
//	t.eliminar();
	t.print();
	t.mostarubi();
}

*/



