#include <iostream>
#include "Lista.cpp"
#include <string.h> 
#include <stdlib.h> 
#include <fstream> 
using namespace std;

const int tamano_arcos = 420;
		const int num_listas= 64;

class Grafo{
	
		
		Lista a[num_listas];
		int h=0;
		int q=0,arreglo[tamano_arcos],numero; 

		ifstream archivo("ficheroTexto.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 


arreglo[q++]=numero;	

Lista *l= new Lista();
//Lista *l1=new Lista();


for(int j=0;j<q;j++) {
	int k = 0;
	Edge e;
	Edge e1;
	
//cout<<h++<<" ="<<arreglo[j];
//if (e.get_source()==1)//|| e.get_source() == -1)


e.set_source(arreglo[j]);//.arreglo[j]<<" =1"<<endl;
e.set_dest(arreglo[j+1]);//[j+1]<<" =2"<<endl;
e.set_weight(arreglo[j+2]);//[j+2]<<" =3"<<endl; 
//e1.set_source(arreglo[j]);//.arreglo[j]<<" =1"<<endl;
//e1.set_dest(arreglo[j+1]);//[j+1]<<" =2"<<endl;
//e1.set_weight(arreglo[j+2]);
//cout<<arreglo[j]<<" =1"<<endl;
//cout<<arreglo[j+1]<<" =2"<<endl;
//cout<<arreglo[j+2]<<" =3"<<endl; 


if (e.get_source()==arreglo[j-3]||e.get_source()==1)//|| e.get_source() == -1)
{

	l->agregar(e);
	a[k]=*l;
	a[k].mostrar();
}
else
{
	//a[k]=*l;
	//l->agregar(e);
//	l->agregar(e1);
	k++;
	
	Lista *l1=new Lista();
	l1->agregar(e);
	a[k]= *l1;
	l =l1;
	a[k].mostrar();
}
//l = l1;

//a[k++].mostrar();
cout<<endl;
j=j+2;



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



};
