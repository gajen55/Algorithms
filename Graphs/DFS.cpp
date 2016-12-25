#include <iostream>
#include <list>
#include <ulimit.h>
using namespace std;


class Graph
{
	int V;
	list <int> *Adj;
	
	void DFS_VISIT(int s, int * visited)
	{
		list <int> :: iterator i;
		visited[s] = 1;
		
		cout<<s<<endl;
		

		for(i=Adj[s].begin();i!=Adj[s].end(); i++)
		{
			if(!visited[*i])
			{
				DFS_VISIT(*i, visited);
			}
		}
	}
	
	public:
	Graph(int V)
	{
		this->V = V;
		Adj = new list <int> [V];
	}
	
	void addEdge(int v, int w)
	{
		Adj[v].push_back(w);
	}

	
	void DFS(int s)
	{
		int *visited = new int [V];

		for (int j=0; j<V; j++)
		{
			visited[j] = 0;
		}
		DFS_VISIT(s, visited);
	}
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(3, 0);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

	g.DFS(3);
	return 0;
}

