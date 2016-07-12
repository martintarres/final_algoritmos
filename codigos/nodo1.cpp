#include <iostream>
#include "Edge.cpp"
#include <string.h> 
#include <stdlib.h> 
#include <fstream> 
using namespace std;

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

const int n=2;	

int main(){
	Lista a[64];
/*	Lista *l= new Lista();
	Lista *l1= new Lista();
	Edge e;// = Edge();
//	Edge e1;//= Edge(7,9,8);
//	Edge e2;//= Edge(11,98,82);
//	Edge e3;//= Edge (99,98,97);
//	e.Edge();
//	e1.Edge();
//	e2.Edge();

int h=0;
int i=0,arreglo[100],numero; 


ifstream archivo("ficheroTexto.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 


arreglo[i++]=numero;	


for(int j=0;j<i;j++) {

//cout<<h++<<" ="<<arreglo[j];
e.set_source(arreglo[j]);//.arreglo[j]<<" =1"<<endl;
e.set_dest(arreglo[j+1]);//[j+1]<<" =2"<<endl;
e.set_weight(arreglo[j+2]);//[j+2]<<" =3"<<endl; 
//cout<<arreglo[j]<<" =1"<<endl;
//cout<<arreglo[j+1]<<" =2"<<endl;
//cout<<arreglo[j+2]<<" =3"<<endl; 
cout<<endl;
j=j+2;

}

 

}else{ 
cout<<"El archivo no se encuentra\n"; 
} 


/*	e.set_dest(5);
	e.set_source(9);
	e.set_weight(15);
	e1.set_dest(78);
	e1.set_source(2);
	e1.set_weight(45);
	e2.set_dest(98);
	e2.set_source(65);
	e2.set_weight(150);
	e3.set_dest(54);
	e3.set_source(100);
	e3.set_weight(1000);
*/	
//	l->agregar(e);
//	l->agregar(e1);
//	l->agregar(e3);
//	l1->agregar(e2);
//	a[0]=*l;
//	a[1]=*l1;
//	a[0].mostrar();
//	a[1].mostrar();*/
int h=0;
int q=0,arreglo[200],numero; 


ifstream archivo("ficheroTexto.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 


arreglo[q++]=numero;	


for(int j=0;j<q;j++) {
	int k = 0;
	Edge e;
	Edge e1;
	Lista *l= new Lista();
//cout<<h++<<" ="<<arreglo[j];
e.set_source(arreglo[j]);//.arreglo[j]<<" =1"<<endl;
e.set_dest(arreglo[j+1]);//[j+1]<<" =2"<<endl;
e.set_weight(arreglo[j+2]);//[j+2]<<" =3"<<endl; 
//e1.set_source(arreglo[j]);//.arreglo[j]<<" =1"<<endl;
//e1.set_dest(arreglo[j+1]);//[j+1]<<" =2"<<endl;
//e1.set_weight(arreglo[j+2]);
//cout<<arreglo[j]<<" =1"<<endl;
//cout<<arreglo[j+1]<<" =2"<<endl;
//cout<<arreglo[j+2]<<" =3"<<endl; 
	l->agregar(e);
//	l->agregar(e1);
	a[k]=*l;
	a[k].mostrar();



cout<<endl;
j=j+2;
k++;


/*for(int i=0; i<5;i++){


	l->agregar(e);
	a[i]=*l;
	a[i].mostrar();


}*/
}

 

}
else{ 
cout<<"El archivo no se encuentra\n"; 
} 


}

	

