#include<bits/stdc++.h>
using namespace std;

class Graph{

	int V;
	list<pair<int,int> > *l;

public:
	Graph(int v){
		V = v;
		l = new list<pair<int,int> >[V];
	}
	void addEdge(int u,int v,int cost,bool bidir=true){
		l[u].push_back(make_pair(v,cost));
		if(bidir){
			l[v].push_back(make_pair(u,cost));
		}

	}
	int dfsHelper(int node,bool *visited,int *count,int &ans){
		visited[node]  = true;

		count[node] = 1;
		for(auto neighbour:l[node]){
			int v = neighbour.first;
			if(!visited[v]){
				count[node] += dfsHelper(v,visited,count,ans);
				ans += 2*min(count[v],V-count[v])*neighbour.second;
			}

		}
		return count[node];
	}


	int dfsMain(){
		bool *visited = new bool[V]{0};
		int *count = new int[V]{0};
		int ans = 0 ;

		dfsHelper(0,visited,count,ans);
		return ans;	
	}
};

int main(){

	Graph g(4);
	g.addEdge(0,1,3);
	g.addEdge(1,2,2);
	g.addEdge(3,2,2);

	cout<<g.dfsMain();


}