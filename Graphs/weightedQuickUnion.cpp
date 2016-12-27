#include <bits/stdc++.h>
using namespace std;

class WeightedQuickUnion
{
	int *id;
	int *sz;	// maintain size of each root. So that smaller tree is connected to the root of bigger tree.
	
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
			id[i] = id[id[i]];	//Path compression. Jumping directly to grand parent.
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

int main()
{
	WeightedQuickUnion q(4);
	q.unite(0,1);
	q.unite(1,3);
	cout<<q.find(0,3);
	return 0;
}
		
