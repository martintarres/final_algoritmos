#include <iostream>
//#include "Nodo.cpp"
#include <string.h> 
#include <stdlib.h> 
#include <fstream> 
#include "maxHeapSemaforo.cpp"

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
};

int Lista::getDest(){
	Nodo *aux;
	
//	cout<<cabeza->dato.get_dest()<<" ";
	aux=cabeza;
	
	if(cabeza!=NULL){
	//	cabeza=cabeza->next;
		return aux->dato.get_dest();
//	cout<<cabeza->dato.get_dest()<<" ";
//	return a;
//	cabeza=cabeza->next;
//	cout<<cabeza->dato.get_dest()<<" ";
	}
	
	//cabeza=cabeza->next;
	//cabeza=aux;
}

int Lista::getSource(){
		if(cabeza!=NULL){
		return cabeza->dato.get_source();
//	cout<<cabeza->dato.get_dest()<<" ";
//	return a;
	cabeza=cabeza->next;
//	cout<<cabeza->dato.get_dest()<<" ";
	}
}

	void Lista::agregar(Edge edge){
		cabeza= new Nodo(edge, cabeza);
	//	cabeza=cabeza->next;
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

//const int n=2;	


int main(){
	
	Lista *l= new Lista();	
   	Lista a[num_listas];
   	Vehiculos v;
   	Heaparr1 t;
   	Heaparr g;
   	Semaforo s;//=  Semaforo(e); 

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

for(int j=0;j<qq;j++) {
	Vehiculos v;

		v.set_patente(arregloo[j]);
		v.set_origen(arregloo[j+1]);
		v.set_final(arregloo[j+2]);
		v.set_prioridad(arregloo[j+3]);
		
		g.insert(v);
		j=j+3;	
	}
	cout<<"Soy vehiculos: " <<endl;
	g.print();

	

for(int j=0;j<q;j++) {
	
	Edge e;



e.set_source(arreglo[j]);//.arreglo[j]<<" =1"<<endl;
e.set_dest(arreglo[j+1]);//[j+1]<<" =2"<<endl;
e.set_weight(j+2);

//Semaforo s=  Semaforo(e); 
s= Semaforo (e);
t.insert(s);

e.set_weight(s.esvaciodesde());

if (e.get_source()==arreglo[j-3]||e.get_source()==1)//|| e.get_source() == -1)
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

}

 //t.print();


cout<<endl<<endl;
cout<< "Soy ciudad :"<<endl;
for(int i=0; i<64; i++){
	
	a[i].mostrar();
	cout<<endl;
	}

}

	/*Lista l;//= new Lista();
	
       Heaparr1 t;
       Heaparr g;
	//	Edge e;
	Lista a[num_listas];
//	Semaforo s= Semaforo(e);
		Vehiculos v;
//	Heaparr t;
	
	
	int numero, arreglo[100], q;/*
ifstream archivo("ficheroAutos.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 
arreglo[q++]=numero;


for(int j=0;j<q;j++) {
	Vehiculos v;//=new Vehiculos();

		v.set_patente(arreglo[j]);
		v.set_origen(arreglo[j+1]);
		v.set_final(arreglo[j+2]);
		v.set_prioridad(arreglo[j+3]);
		g.insert(v);
		s.insert(v);
	//	g.print();
	//	s.print();
	//cout<< "patente: "<< v->get_patente()<< endl;
//	cout<< "origen: "<< v->get_origen()<< endl;
//	cout<< "final: "<< v->get_final()<< endl;
	
//	cout << "prioridad: " << v->get_prioridad() << endl;
	cout<<endl;
	j=j+3;
}
}
             

	

ifstream archivo1("ficheroTexto.txt"); 
if(archivo.good()){ 
while(archivo1>>numero) 

*//*
arreglo[q++]=numero;	

	//Heaparr v;
int k = 0;
for(int j=0;j<q;j++) {
	//Heaparr1 t;
	Edge e;
	//Semaforo s;
//	Edge e1;

	e.set_source(arreglo[j]);//.arreglo[j]<<" =1"<<endl;
	e.set_dest(arreglo[j+1]);//[j+1]<<" =2"<<endl;
	e.set_weight(arreglo[j+2]);
	
	Semaforo s= Semaforo(e);
	

		
	
//	s.insert(v);
	
	
 
	//s.print();

Vehiculos v;
	v.set_origen(1);
 	v.set_final(2);
 	v.set_patente(0);
 	v.set_prioridad(0);
 	Vehiculos v1;
 	v1.set_origen(3);
 	v1.set_final(4);
 	v1.set_patente(1);
 	v1.set_prioridad(1);
 	
 	s.insert(v);
	s.insert(v1);
 /*	
 	Semaforo s= Semaforo(e);
	
	cout << s.esvaciodesde();
*//*
 	e.set_weight(s.esvaciodesde());
}
//}

//	s.print();
}
  
	//e.set_weight(s.esvaciodesde());
	
 	
//cout << s.esvaciodesde();
//cout << " e.wei" << e.get_weight();
//s.print();
//cout<< s.size();
//t.insert(s);
/*

if (e.get_source()==arreglo[j-3]||e.get_source()==1)//|| e.get_source() == -1)
{

	l.agregar(e);
	a[k]=l;
	//a[k].mostrar();
	
}
else
{
	k++;
	
	Lista l1;//=new Lista();
	l1.agregar(e);
	a[k]= l1;
	l =l1;
	//a[k].mostrar();

}

//cout<<endl;
j=j+2;




}


 //t.print();
 //s.print();
// t.mostarubi();
}
else{ 
cout<<"El archivo no se encuentra\n"; 
}

	for(int i=0; i<num_listas;i++){
		a[i].mostrar();
		cout<<endl;
	}*/



//l.mostrarArco();
//l.mostrar();

//a[0].mostrar(a[0]);
/*
 for(int i=0;i<64;i++){
 //	cout<<e.get_dest();
 //	int a,b,c;
 if(a[i].getSource()==9){
 	//cout<<a[i].getSource();
 	
 	if(a[i].getDest()==17){
 		cout<<a[i].getSource();
 		cout<<a[i].getDest();
	 }
//	cout<<a[i].getDest();
//	cout<<a[i].getDest(); 	
 	//if()
 }
	
	
//	a[i].getSource();
//	a[i].mostrar();
//	a[i].getDest();
//	a[i].getDest();
	//	a[i].mostrar();
	cout<<endl;
}*/
	 /*
for(int j=0;j<q;j++) {
a[j].mostrar();
}
	*/
/*

		Heaparr g;
	
	
	int numeroo, arregloo[100], c=0;
ifstream archivoo("ficheroAutos.txt"); 
if(archivoo.good()){ 
while(archivoo>>numeroo) 
arregloo[c++]=numeroo;


for(int j=0;j<c;j++) {
	Vehiculos *v=new Vehiculos();

		v->set_patente(arregloo[j]);
		v->set_origen(arregloo[j+1]);
		v->set_final(arregloo[j+2]);
		v->set_prioridad(arregloo[j+3]);
		
	
		g.insert(*v);
		
	
	
		
		
	//	
	//cout<< "patente: "<< v->get_patente()<< endl;
//	cout<< "origen: "<< v->get_origen()<< endl;
//	cout<< "final: "<< v->get_final()<< endl;
	
//	cout << "prioridad: " << v->get_prioridad() << endl;
	
	j=j+3;
}
//g.print();

for(int h=0; h<20; h++){
	bool colocado= false;

	for(int i=0; i<140; i++){
		//cout<< t.recorre(i).getUbicacion()<<endl;
	
		
	
	if((t.recorre(i).getUbicacion()== g.recorrer(h).get_origen() )&& (colocado == false)){
		
		
		cout<< g.recorrer(h).get_patente()<< " entre "<<endl;
		colocado=true;
	}
	}

}
}


*/


