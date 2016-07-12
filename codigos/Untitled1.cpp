/*#include <iostream> 
#include <string.h> 
#include <stdlib.h> 
#include <fstream> 
#include "nodo1.cpp"
#include "Edge.cpp"
using namespace std; 


class cargar{
	

//int main() { 

Edge e;// = Edge();
	Edge e1;//= Edge(7,9,8);
	Edge e2;//= Edge(11,98,82);
	Edge e3;
	
int h=0;
int i=0,arreglo[100],numero; 


ifstream archivo("ficheroTexto.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 


arreglo[i++]=numero;	


for(int j=0;j<i;j++) {

//cout<<h++<<" ="<<arreglo[j];
 e.arreglo[j]<<" =1"<<endl;
cout<<arreglo[j+1]<<" =2"<<endl;
cout<<arreglo[j+2]<<" =3"<<endl; 
cout<<endl;
j=j+2;

}

 

}else{ 
cout<<"El archivo no se encuentra\n"; 
} 
 
};

const int n=2;	

 int main(){
	Lista a[2];
	Lista *l= new Lista();
	Lista *l1= new Lista();
//	Edge e;// = Edge();
//	Edge e1;//= Edge(7,9,8);
//	Edge e2;//= Edge(11,98,82);
//	Edge e3;//= Edge (99,98,97);
//	e.Edge();
//	e1.Edge();
//	e2.Edge();
	e.set_dest(5);
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
	
	l->agregar(e);
	l->agregar(e1);
	l->agregar(e3);
	l1->agregar(e2);
	a[0]=*l;
	a[1]=*l1;
	a[0].mostrar();
	a[1].mostrar();

}
*/

