#include<iostream>
#include<map>
#include<list>
using namespace std;


template<typename T>
class Graph{

	map<T,list<T> > adjList;

public:
	Graph(){

	}
	void addEdge(T u, T v,bool bidir=true){

		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}
	bool isCyclicHelper(T node,map<T,bool> &visited,map<T,bool> &inStack){

			//Processing the current node - Visited, InStack
			visited[node] = true;
			inStack[node] = true;

			//Explore the neigbours of the node
			for(T neighbour: adjList[node]){
					//Two things can happen
					//The current node is not visited but its further branch is leading to a cycle
					if((!visited[neighbour] && isCyclicHelper(neighbour,visited,inStack))||inStack[neighbour]){
						return true;
					}

			}
			//Going to pop out the node, inStack = false
			inStack[node] = false;
			return false;

	}

	bool isCyclic(){
		map<T,bool> visited;
		map<T,bool> inStack;

		//To check for cycle in each dfs tree
		for(auto i:adjList){
			T node = i.first;
			if(!visited[node]){
				 bool cyclePresent = isCyclicHelper(node,visited,inStack);
				 if(cyclePresent){
				 	return true;
				 }
			}
		}
		return false;
	}

	
};

int main(){

	Graph<int> g;
	g.addEdge(0,2,false);
	g.addEdge(0,1,false);
	g.addEdge(2,3,false);
	g.addEdge(2,4,false);
	//g.addEdge(3,0,false);
	g.addEdge(4,5,false);
	g.addEdge(1,5,false);

	if(g.isCyclic()){
		cout<<"Cycle Present !";
	}
	else{
		cout<<"Cycle Not found!";
	}

return 0;
}