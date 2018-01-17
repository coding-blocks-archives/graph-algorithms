#include<iostream>
#include<map>
#include<list>
#include<queue>
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

	void print(){

		//Iterate over the map
		for(auto i:adjList){
			cout<<i.first<<"->";

			//i.second is LL
			for(T entry:i.second){
				cout<<entry<<",";
			}
			cout<<endl;
		}
	}
	
	int bfs(T src,T dest){
		
		queue<T> q;
		map<T,int> dist;
		map<T,T> parent;

		for(auto i:adjList){
			dist[i.first] = INT_MAX;
		}

		q.push(src);
		dist[src] = 0;
		parent[src] = src;

		while(!q.empty()){

			T node = q.front();
			//cout<<node<<" ";
			q.pop();

			// For the neigbours of the current node, find out the nodes which are not visited
			for(int neigbour :adjList[node]){
				if(dist[neigbour]==INT_MAX){
					q.push(neigbour);
					dist[neigbour] = dist[node]  + 1;
					parent[neigbour] = node;
				}
			}
		}

		

		//You can destination and go backwards
		T temp = dest;
		while(temp!=src){
				cout<<temp<<"<--";
				temp = parent[temp];
		}
		cout<<src<<endl;

		return dist[dest];
	}


	
};

int main(){


	Graph<int> g;
	int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;
    //Lets first the construct the graph, add pairs of u,v

    for(int u=0;u<=36;u++){
    	//At every node, you can throw a dice
    	for(int dice=1;dice<=6;dice++){
    		int v = u + dice + board[u+dice];
    		g.addEdge(u,v,false);
    	}
    }


    cout<<"The shortest dist is "<<g.bfs(1,36)<<endl;
	

	return 0;
}