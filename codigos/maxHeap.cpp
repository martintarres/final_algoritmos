#include <iostream>
//#include "Nodo.cpp"
using namespace std;


const int maximo = 14 ;
class maxHeap{
	private:
		
		int tamano;
		//int ptr;
		int padre;
		int hd, hijo;
		int arreglo[maximo];
	public:
		maxHeap();
		int eliminar();
		void insertar(int);
		int size();	
		bool lugarDisponible();	
		void imprimir();
		void swap(int, int);
		int Padre (int);
	
	};
maxHeap::maxHeap(){
	for(int i=0; i <9; i++){
		arreglo[i]= -1;

}
//arreglo[4]=9;
	for(int i=9; i <maximo; i++){
		arreglo[i]= -1;
	
		}
}
/*
void maxHeap::insertar(int num){
	bool x;
	x= true;
	int aux;
	int n;
	
	for(int i=0;i<maximo;i++){

		if((arreglo[i]== -1)&& (x ==true)){
			arreglo[i] = num;
			hi= arreglo[i];	
			n=((i-1)/2);
			padre = Padre(i);

			x = false;
			
			for(int j=0; j<5; j++){
			while(hi>padre){
			
			swap(hi, padre);
		//	aux = hi;
		//	hi = padre;
		//	padre = aux;
			
			arreglo[i]= padre;
			arreglo[n] = hi;
			hi = arreglo [i];
			padre = arreglo[n];
		
		}
		}
	}
	
		}
	
		
	
}
*/
void maxHeap::insertar(int num){
	bool x;
	x= true;
	int aux;
	int n;
	int h = 4;
	
	for(int i=0;i<maximo;i++){

		if((arreglo[i]== -1)&& (x ==true)){
			arreglo[i] = num;
			n=((i-1)/2);
			hijo= arreglo[i];
			x= false;
			padre = Padre(i);
			while((padre >= 0)&& padre < hijo && h!= 0)
			{
				cout << "padre: " << padre << endl;
				cout << "hijo: " << hijo << endl;
			//	swap(arreglo[i], arreglo[((i-1)/2)]);
				//swap(padre, hijo);
				aux = padre;
				padre = hijo;
				hijo = aux;
				cout << "padre: " << padre << endl;
				cout << "hijo: " << hijo << endl;
				arreglo[i]= hijo;
				arreglo[((i-1)/2)] = padre;
				cout << "arreglo(i): "<< arreglo[i] << "  " ;
				cout << "arreglo(n): " << arreglo[n];
				n=((i-1)/2);
				i= n;
				hijo = padre;
				padre = arreglo[(n)];
				h--;
				cout << "nuevo ciclo" << endl;
			}

}
}
}
//void maxHeap::insertar(int num){



int maxHeap::Padre(int i){
	if((arreglo[((i-1)/2)] < maximo)&& i>=0){
		return arreglo[((i-1)/2)];
	}else {
		return i;
	}
}



/*                           PADRES E HIJOS.
int maxHeap:: hd(int i){
 	if(2*i+2<cant && i>=0){
 		return 2*i+2;
	 }else {
	 	return i;
	 }
 }
 
 int maxHeap::hi(int i){
 	if(2*i+1<cant && i>=0){
 		return i;
	 }
 }

int maxHeap::padre(int i){
	if(floor((i-1)/2)<cant && i>=0){
		return floor((i-1)/2);
	}else {
		return i;
	}
}
*/
/*
void maxHeap::insertar(int num){
	bool x;
	x= true;
	for(int i=0;i<cant;i++){
		if((arreglo[i]==-1) && (arreglo[i-2] != -1)){
			a[i]=num;
			//int t=size();
			hi= a[size()+1];
			padre= a[((hi-1)/2)];
			while (padre>=-1 && a[padre]< a[hi]){
				swap (a[padre],a[hi]);
				int aux;
				aux=hi;
				hi=padre;
				padre=a[((aux -1)/2)];
			}
			}
	 }	  
 }
 */
 
	
	//for()
//arreglo



int maxHeap::eliminar()
{
	int aux;
	aux = arreglo [0];
	for(int i=0; i< maximo ; i++){
	if((arreglo[i+1]==-1) && (arreglo[i] != -1)){
		arreglo[0]= arreglo[i];
		arreglo [i]= -1;
}
}

if (arreglo[0]< arreglo [1])
	swap(arreglo[0], arreglo[1]);

if (arreglo[0]< arreglo[2])
	swap(arreglo[0], arreglo[2]);


return aux;
}	

void maxHeap::imprimir(){
	for(int i=0; i< maximo ; i++){
		cout << "numeros:" << arreglo[i] << endl;
	}
}
	


bool maxHeap::lugarDisponible()
{
	return true;	
}
void maxHeap::swap (int c, int b){
	int aux;
	aux= c;
	c= b;
	b=aux;
}

/*
	void encolar (int a);
	void desencolar();
	int cabeza();
	bool colaVacia();
	*/
	
int main(){
	int hd;
	int hd2;
	maxHeap M = maxHeap();
//	M.imprimir();
//hd=	M.eliminar();
//hd2 = M.eliminar();
//	M.eliminar();
	M.insertar(10);
	M.insertar(18);
//	M.insertar(30);
//	M.insertar(12);
//	M.insertar(8);
//	M.insertar(14);
//	M.insertar(30);
//	M.insertar(19);
//	M.insertar(2);
//	M.insertar(45);
	//hd2 = M.eliminar();
	M.imprimir();
	cout << "aaaaa" << hd << "bbbb "<< hd2;
}
