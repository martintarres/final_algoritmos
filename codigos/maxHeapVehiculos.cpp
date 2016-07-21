#include <iostream>
#include <math.h>
#include "Vehiculos.cpp"
#include <string.h> 
#include <stdlib.h> 
#include <fstream> 
using namespace std;

const int cant=10;
class Heaparr {
public:
    Heaparr();
    void insert(Vehiculos da);
    int getLeft(int i) { return 2 * i + 1; }
    int getRight(int i) { return 2 * i + 2; }
    int getParent(int i) { return (i - 1) / 2; }
    int getMax() { return maxHeap[0]; }
    void print();
    void reheap(int num);
    void makeArray();
    void Build_Max_Heap(Vehiculos heapArray[], int heap_size);
    void Max_Heapify(Vehiculos heapArray[], int i, int heap_size);
    void heapSort(Vehiculos heapArray[]);
    int lugaresDisponibles();
    int size();
    Vehiculos eliminar();
    int esvaciodesde();

    

private:
    int num;
    int* maxHeap;
    int index;
    int i;
   Vehiculos vector [cant];

};

Heaparr::Heaparr() {
    num = 0;

}
int Heaparr::lugaresDisponibles(){
	int contador=cant;
	for(int i=0; i<cant;i++){
		
			if(vector[i].get_prioridad()>=0){
			
		contador--;
		}
	}
	return contador;
}

int Heaparr::size(){
	int contador=0;
	for(int i=0; i<cant;i++){
		contador++;
	}
	return contador;
}

int Heaparr::esvaciodesde(){
	for(int i=0 ; i<cant; i++){
		if(vector[i].get_prioridad()== -1){
		//	b++;
			return i;
		}
	
	}

}
void Heaparr::insert(Vehiculos da) {
/*		for(int i=0; i<cant; i++){
		cout<<vector[i];
	}*/
//	for(int i= esvaciodesde(); i<cant;i++){
	if(lugaresDisponibles()>0){

	vector[esvaciodesde()]=da;
	}	else {
	cout<<"Cola llena"<< endl;
	}
	
	heapSort( vector);

}

void Heaparr::print(){
	for(int i=0;i<cant;i++)	{
		cout<< "iteracion "<<i<<endl;
	cout<<vector[i].get_patente()<<endl;//->print();
	cout<<vector[i].get_origen()<<endl;
	cout<<vector[i].get_final()<<endl;
	cout<<vector[i].get_prioridad()<<endl;
	
}

}
void Heaparr::Max_Heapify(Vehiculos heapArray[], int i, int heap_size) {
    // int n = size;
    int largest = 0;
    int l = getLeft(i);
    int r = getRight(i);

    if ((l < heap_size) && (heapArray[l].get_prioridad() < heapArray[i].get_prioridad())) {
        largest = l;
    } else {
        largest = i;
    }

    if ((r < heap_size) && (heapArray[r].get_prioridad() < heapArray[largest].get_prioridad())) {
        largest = r;
    }

    if (largest != i) {
        swap(heapArray[i], heapArray[largest]);
        Max_Heapify(heapArray, largest, heap_size);
    }
    return;
}
void Heaparr::heapSort(Vehiculos heapArray[]) {
    //size = heap_size;
    int n = size ();
    Build_Max_Heap(heapArray, size());

    for (int i = n - 1; i >= 1; i--) {
        swap(heapArray[0], heapArray[i]);
        n = n - 1;
        Max_Heapify(heapArray, 0,n);
    }
}

void Heaparr::Build_Max_Heap(Vehiculos heapArray[], int heap_size) {
    int n = size();
    for (int i = floor((n - 1) / 2); i >= 0; i--) {
        Max_Heapify(heapArray, i, heap_size);
    }
    return;
}

Vehiculos Heaparr::eliminar()
{
	//const int pepito=-1;
	Vehiculos aux;
	aux = vector [0];
	for(int i=0; i< cant ; i++){
	if((vector[i+1].get_prioridad()==-1) && (vector[i].get_prioridad() != -1)){
		vector[0]= vector[i];
		vector [i].set_prioridad(-1) ;
		vector [i].set_origen(-1);
		vector [i].set_final(-1);
		vector [i].set_patente(-1);

}else {
	if(lugaresDisponibles()==0){
	vector [0].set_prioridad(-1) ;
		vector [0].set_origen(-1);
		vector [0].set_final(-1);
		vector [0].set_patente(-1);
	}
	}
}
 heapSort( vector);
	

return aux;
}	



int main(){
	
	Heaparr t;
	
	
	int numero, arreglo[40], q;
ifstream archivo("ficheroAutos.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 
arreglo[q++]=numero;


for(int j=0;j<q;j++) {
	Vehiculos *v=new Vehiculos();

		v->set_patente(arreglo[j]);
		v->set_origen(arreglo[j+1]);
		v->set_final(arreglo[j+2]);
		v->set_prioridad(arreglo[j+3]);
			t.insert(*v);
		
	cout<< "patente: "<< v->get_patente()<< endl;
	cout<< "origen: "<< v->get_origen()<< endl;
	cout<< "final: "<< v->get_final()<< endl;
	
	cout << "prioridad: " << v->get_prioridad() << endl;
	cout<<endl;
	j=j+3;
}}
   // }//               
	
	
	
	
/*	Vehiculos *j= new Vehiculos();
	Vehiculos *j1= new Vehiculos();
		Vehiculos *j2= new Vehiculos();
		
	j->set_prioridad(10);
	j1->set_prioridad(2);
	j2->set_prioridad(230);
	t.insert(*j);
	t.insert(*j1);
		t.insert(*j2);*/
/*	int arreglo[cant]={2,6,8,7,4,1,2,5};
	for(int i=0; i<cant;i++){
		Vehiculos *j= new Vehiculos();
		j->set_prioridad(arreglo[i]);
		
		t.insert(*j);
	}*/
	t.print();
	t.eliminar();
	cout << endl << endl;
	t.print();
}
/*	cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;
	t.insert(4);
	cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;
	t.insert(8);
		cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;
		t.eliminar();
		cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;*/
//	t.insert(3);
//	t.print();
/*	int hArray[cant]={0,0,0,0,0,0,0,0};// = {109,14,0,256};
	int vector[cant]= {256,109,50,15,14};
	for(int i=0; i<cant;i++){
		hArray[i]= vector[i];
	}
//	cout<<t.size();
	 t.heapSort(hArray);
	for (int i=0;i<cant;i++) {
      t.insert(hArray[i]);
    }
  */
/*  int vectorr[cant]= {3,109,50,978,14};
  for(int i=0; i<cant;i ++){
  	t.insert(vectorr[i]);
  }
  t.print();
  cout<<endl;*/
 
 // t.print();
  //cout<< endl;
  //t.eliminar();
  //t.print();
  /*
  t.insert(69);
   cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;
  t.insert(114);
  cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;
 t.insert(8);
 cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;
  t.insert(2);
  cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;
  t.insert(999);
  cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;
  t.insert(457);
  cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;
 t.insert(1000);
 cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;
  t.insert(55);
  cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;
  t.print();
  cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;
  cout<<endl;
//  t.insert(9);
  //t.print();
 // cout<<endl;
  t.eliminar();
  cout<<endl;
  t.print();
  cout<< "el tamaño es: " <<t.lugaresDisponibles()<<endl;
  cout<<endl;
  t.insert(9);
  t.print();
  cout<< "el tamaño es: " <<t.lugaresDisponibles()<<endl;
  cout<<endl;
   t.eliminar();
   cout<<endl;
  t.print();
  cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;
  
 /*  t.eliminar();
  t.print();
  cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;
  cout<<endl;
  t.insert(5);
  t.print();
  cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;*/
//  t.insert(97);
//  t.print();
  //t.eliminar();
//  cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;
//  t.print();
////cout<<endl;
//  t.insert(5);
//  t.print();
//  cout<< "el tamaño es: "<<t.lugaresDisponibles()<<endl;
 // t.insert(9);
//  t.insert(8);
//  t.insert(4);
  
  //  std::cout << std::endl;
   // t.print();
  //  cout<< " primera iteracion"<<endl;
  //  cout<< t.esvaciodesde();
  // t.eliminar();
 //  t.heapSort(hArray);
//    for (int i=0;i<cant;i++) {
 //     t.insert(hArray[i]);
//  }
  // t.print();
 /*   for (int i=0;i<cant;i++) { // era para ver si se actualizaba
      t.insert(hArray[i]);
    }*/
  //  cout<<t.esvaciodesde()<<endl;
//    for(int i= t.esvaciodesde(); i<cant;i++){
    //	hArray [3]= 65;
//	}
 //   for (int i=0;i<cant;i++) {  // era para ver si se actualizaba
  //    t.insert(hArray[i]);
  //  }
 //   t.print();
 //   cout<<t.esvaciodesde();
 /*   t.print();
  //  hArray[cant] = {66,1024,98,8};
    t.print();
    t.eliminar();
    cout<< " segunda "<<endl;
    t.eliminar();
    t.eliminar();
    t.print();
    return 0;
	// t.insert()
//	 t.print();*/
//}
