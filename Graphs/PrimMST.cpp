#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ipair;
# define INF 0x3f3f3f3f
class Compare
{
    public:
    bool operator()(ipair &a, ipair &b)
    {
        return(a.second>b.second);
    }
};
class Graph
{
    int V;
    list<ipair> *adj;
    
    public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<ipair> [V];
    }
    
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    void PrimMST()
    {
        priority_queue <ipair,vector<ipair>, Compare> pq;
        pq.push(make_pair(0,0));
        vector<int> parent(V, -1);

        vector<int> weight(V, INF);
        weight[0] = 0;
        vector<bool> inMST(V, false);
        while(!pq.empty())
        {
            pair<int,int> p = pq.top();
            pq.pop();
            inMST[p.first] = true;
            list<ipair>::iterator i;
            for(i=adj[p.first].begin();i!=adj[p.first].end(); i++)
            {

                if(((inMST[i->first]==false)) && weight[i->first]>i->second)
                {
                    parent[i->first] = p.first;
                    weight[i->first] = i->second;
                    pq.push(make_pair(i->first,weight[i->first]));
                }   
            }

        }
        for(int i=1; i<V; i++)
        {
            cout<<parent[i]<<"-"<<i<<endl;
        }
    }
    
    
};
int main() {
    int V = 4;
    Graph g(V);
 
    g.addEdge(0, 1, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 3, 2);

    
	g.PrimMST();
	return 0;
}
