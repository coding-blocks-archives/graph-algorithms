#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;


template<typename T>
class Graph{

	int V;
	map<T,list<T> > adjList;

public:
	Graph(int v){
		V = v;
	}
	void addEdge(T u, T v,bool bidir=true){

		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}
	bool isCyclicHelper(T node,map<T,bool> &visited,T parent){
		
		visited[node] = true;

		for(T neigbour:adjList[node]){
			if(!visited[neigbour]){
					bool cycleDetected = isCyclicHelper(neigbour,visited,node);
					if(cycleDetected){
						return true;
					}

			}
			//in this neigbour is already visited
			else if(neigbour!=parent){
				return true;
			}
		}
		return false;
	}
	
	//Check for undirected graph
	bool isCyclicDFS(){
		map<T,bool> visited;

		//You can for finding cycle in every dfs tree
		for(auto i:adjList){
			T node = i.first;
			if(!visited[node]){
					bool ans = isCyclicHelper(node,visited,node);
					if(ans==true){
						return true;
					}
			}
		}
		return false;

	}

		
};

int main(){

	Graph<int> g(4);
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(4,3);

	
	if(g.isCyclicDFS()){
		cout<<"Cyclic Graph";
	}
	else{
		cout<<"Non cyclic!";
	}


return 0;
}