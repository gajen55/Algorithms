#include <iostream>
#include <list>

using namespace std;
class Graph
{
    int V;
    list <int> *List;
    
    public:
    Graph(int V)
    {
        this->V=V;
        List = new list <int> [V];
    }
    
    int addEdge(int v, int w)
    {
        List[v].push_back(w);
    }
    
    int BFS(int s)
    {
        bool *visited = new bool [V];
        int i;
        for(i=0;i<V;i++)
        {
            visited[i]=false;
            
        }
        
        list <int> queue;
        
        visited[s] = true;
        queue.push_back(s);
        
        list <int>:: iterator j;
        int current;
        
        while(!queue.empty())
        {
            current = queue.front();
            cout <<"  "<<current;
            queue.pop_front();
            
            for(j = List[current].begin(); j != List[current].end();j++)
            {
                if(!visited[*j])
                {
                    visited[*j] = true;
                    queue.push_back(*j);
                }
            }
        }
    }
};


int main()
{
   Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS(2);
   return 0;
}


