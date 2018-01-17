# include<iostream>
# include<list>
using namespace std;



class Graph{

	int V;
	list<int> *l;

public:
	Graph(int v){
		V = v;
		//Array of Linked Lists
		l = new list<int>[V];
	}

	void addEdge(int u,int v,bool bidir=true){
		l[u].push_back(v);
		if(bidir){
			l[v].push_back(u);
		}
	}

	void printAdjList(){
		for(int i=0;i<V;i++){

				cout<<i<<"->";
				//l[i] is a linked list
				for(int vertex: l[i]){
					cout<<vertex<<",";
				}
				cout<<endl;
		}
	}

	
};

int main(){

	// Graph has 5 vertices number from 0 to 4
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(4,3);
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(1,3);

	g.printAdjList();

return 0;
}

