#include <bits/stdc++.h>
using namespace std;
typedef  pair<int, int> ipair;

class WeightedQuickUnion
{
	int *id;
	int *sz;
	
	public:
	WeightedQuickUnion(int N)
	{
		id = new int [N];
		sz = new int [N];
		for (int i = 0; i < N; i++)
		{
			id[i] = i;
			sz[i] = 1;
		}
	}
	
	int root(int i)
	{
		while(i!=id[i])
		{
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}
	
	bool find(int p, int q)
	{
		return (root(p)==root(q));
	}
	
	void unite(int p, int q)
	{
		int i = root(p);
		int j = root(q);
		
		if(sz[i]>sz[j])
		{
			id[j] = i;
			sz[i] += sz[j];
		}
		else
		{
			id[i] = j;
			sz[j] += sz[i];
		}
	}
};

class Graph
{
	int V,E;
	vector < pair <int, ipair> > edges;
	
	public:
	Graph(int V, int E)
	{
		this->V = V;
		this->E = E;
	}
	
	void addEdge(int v, int u, int w)
	{
		edges.push_back({w, {v,u}});
	}
	
	int kruskalMST()
	{
		int mst_wt = 0;
		WeightedQuickUnion q(V);
		sort(edges.begin(), edges.end());
		
		vector < pair <int,ipair> > :: iterator it;
		
		for(it = edges.begin(); it!=edges.end(); it++)
		{
			int v = it->second.first;
			int u = it->second.second;
			
			if(q.root(v) != q.root(u))
			{
				cout << u << " - " << v << endl;
				q.unite(v, u);
				mst_wt += it->first;
			}
		}
		return mst_wt;
	}
};
		
	
int main()
{
	Graph g(9,14);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    cout << "Edges of MST are \n";
    int mst_wt = g.kruskalMST();
 
    cout << "\nWeight of MST is " << mst_wt;
 
    return 0;
}
		
