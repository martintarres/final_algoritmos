#include <iostream>

//#include "Nodo.cpp"
using namespace std;

class Edge  { 
	private:
		int dest;
		int source;
		int weight;

		
		public:
		Edge (int source , int dest , int weight){
		this->source=source;
		this->dest=dest;
		this->weight=weight;
		}
		Edge (){
			dest= -1;
			source = -1;
			weight = 9999999;
		}
		bool operator==(Edge);
		int get_dest();
		int get_source();
		int get_weight();
		string to_string;
		void set_dest(int);
		void set_source(int);
		void set_weight(int);
		bool isEdge(int, int);
};
	
	void Edge::set_dest(int a){
		dest=a;
	}
	
	void Edge::set_source(int a){
		source=a;
	}
	
	void Edge::set_weight(int a){
		weight=a;
	}
	int Edge::get_dest(){
		return dest;
	}
	
	int Edge::get_source(){
		return source;
	}
	
	int Edge::get_weight(){
		return weight;
	}
	
	bool Edge::operator==(Edge){
		if (source== dest){
			return true;
		} else {
			return false;
		}
	}
	
	bool Edge::isEdge(int a, int b){
		if(a== get_source() && b==get_dest()){
			return true;
		}else {
			return false;
		}
		
	}

