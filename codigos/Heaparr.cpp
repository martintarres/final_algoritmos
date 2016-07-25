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
    int size();
    int eliminar();
    int esvaciodesde();
  //  void swap(int, int);
    

private:
    int num;
    int* maxHeap;
    int index;
    int i;
};

Heaparr::Heaparr() {
    maxHeap = NULL;
    num = 0;
}
int Heaparr::size(){
	int contador=0;
	for(int i=0; i<cant;i++){
		contador++;
	}
	return contador;
}

int Heaparr::esvaciodesde(){
	for(int i=0; i<cant; i++){  // el puto de fabri dice que hagamos : 
		if(maxHeap[i]==NULL){	// if(maxHeap[i]==NULL && maxHeap[i+1]==NULL)
			return i;			// por si las dudas .
		}
	}
}
void Heaparr::insert(int da) {
    num++;
    int* tmp = new int[num];

    for (int i = 0; i < num - 1; i++) {
        tmp[i] = maxHeap[i];
       
        
    }
	
    tmp[num - 1] = da;
    
    delete[] maxHeap;
    maxHeap = tmp;
	
}

void Heaparr::print(){
	for(int i=0;i<8;i++)	{
		
	cout<<maxHeap[i]<<endl;//->print();
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
	int aux;
	aux = maxHeap [0];
	for(int i=0; i< cant ; i++){
	if((maxHeap[i+1]==-0) && (maxHeap[i] != 0)){
		maxHeap[0]= maxHeap[i];
		maxHeap [i]= 0;
}
}

if (maxHeap[0]< maxHeap [1])
	swap(maxHeap[0], maxHeap[1]);

if (maxHeap[0]< maxHeap[2])
	swap(maxHeap[0], maxHeap[2]);


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
//	t.insert(4);
//	t.insert(8);
//	t.insert(3);
//	t.print();
	int hArray[cant] = {109,14,0,256};
//	cout<<t.size();
	 t.heapSort(hArray);
	for (int i=0;i<cant;i++) {
      t.insert(hArray[i]);
    }
  
  //  std::cout << std::endl;
    t.print();
    cout<< " primera iteracion"<<endl;
  //  cout<< t.esvaciodesde();
    t.eliminar();
    for (int i=0;i<cant;i++) {
      t.insert(hArray[i]);
    }
    cout<<t.esvaciodesde()<<endl;
    for(int i= t.esvaciodesde(); i<cant;i++){
    	hArray [3]= 65;
	}
    for (int i=0;i<cant;i++) {
      t.insert(hArray[i]);
    }
    t.print();
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
}
