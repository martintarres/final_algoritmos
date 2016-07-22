#include <iostream>
#include <math.h>
using namespace std;

const int cant=8;
class Heaparr {
public:
    Heaparr();
    void insert(int da);
    int getLeft(int i) { return 2 * i + 1; }
    int getRight(int i) { return 2 * i + 2; }
    int getParent(int i) { return (i - 1) / 2; }
    int getMax() { return maxHeap[0]; }
    void print();
    void reheap(int num);
    void makeArray();
    void Build_Max_Heap(int heapArray[], int heap_size);
    void Max_Heapify(int heapArray[], int i, int heap_size);
    void heapSort(int heapArray[]);
    int lugaresDisponibles();
    int size();
    int eliminar();
    int esvaciodesde();

    

private:
    int num;
    int* maxHeap;
    int index;
    int i;
   int vector [cant];

};

Heaparr::Heaparr() {
  //  maxHeap = NULL;
    num = 0;
    for(int i=0; i<cant; i++){
		vector[i]=-1;
	}
 
}
int Heaparr::lugaresDisponibles(){
	int contador=cant;
	for(int i=0; i<cant;i++){
		
			if(vector[i]>=0){
			
		contador--;
		}
	}
	return contador;
}

int Heaparr::size(){
	int contador=cant;
	for(int i=0; i<cant;i++){
		
	}
	return contador;
}

int Heaparr::esvaciodesde(){
	for(int i=0 ; i<cant; i++){
		if(vector[i]== -1){
		//	b++;
			return i;
		}
	
	}

}
void Heaparr::insert(int da) {
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
	for(int i=0;i<8;i++)	{
		
	cout<<vector[i]<<endl;//->print();
}
}
void Heaparr::Max_Heapify(int heapArray[], int i, int heap_size) {
    // int n = size;
    int largest = 0;
    int l = getLeft(i);
    int r = getRight(i);

    if ((l < heap_size) && (heapArray[l] < heapArray[i])) {
        largest = l;
    } else {
        largest = i;
    }

    if ((r < heap_size) && (heapArray[r] < heapArray[largest])) {
        largest = r;
    }

    if (largest != i) {
        swap(heapArray[i], heapArray[largest]);
        Max_Heapify(heapArray, largest, heap_size);
    }
    return;
}
void Heaparr::heapSort(int heapArray[]) {
    //size = heap_size;
    int n = size ();
    Build_Max_Heap(heapArray, size());

    for (int i = n - 1; i >= 1; i--) {
        swap(heapArray[0], heapArray[i]);
        n = n - 1;
        Max_Heapify(heapArray, 0,n);
    }
}

void Heaparr::Build_Max_Heap(int heapArray[], int heap_size) {
    int n = size();
    for (int i = floor((n - 1) / 2); i >= 0; i--) {
        Max_Heapify(heapArray, i, heap_size);
    }
    return;
}

int Heaparr::eliminar()
{
	const int pepito=-1;
	int aux;
	aux = vector [0];
	for(int i=0; i< cant ; i++){
	if((vector[i+1]==-1) && (vector[i] != -1)){
		vector[0]= vector[i];
		vector [i]= -1;
}else {
	if(lugaresDisponibles()==0){
	
		vector[0]=-1;
	}
	}
}
 heapSort( vector);
	
//}

if (vector[0]< vector [1])
	swap(vector[0], vector[1]);

if (vector[0]< vector[2])
	swap(vector[0], vector[2]);


return aux;
}	

/*void Heaparr::swap (int c, int b){
	int aux;
	aux= c;
	c= b;
	b=aux;
}*/

int main(){
	
	Heaparr t;
	t.print();
	t.insert(9);
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
