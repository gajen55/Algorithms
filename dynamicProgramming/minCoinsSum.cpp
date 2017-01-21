#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;    
	cin>>n;
	ll v[n];
	for(ll i=0; i<n; i++)
	{
	    cin>>v[i];
	}
	ll s;
	cin>>s;
	ll coins[s+1];
	for(ll i=0; i<=s; i++)
	{
	    coins[i] = LLONG_MAX;
	}
	coins[0] = 0;
	for(ll i=1; i<=s; i++)
	{
	    for(ll j=0; j<n; j++)
	    {
	        if(i>=v[j] && (coins[i] > coins[i-v[j]]+1))
	            coins[i] = coins[i-v[j]]+1;
	    }
	}
	cout<<coins[s]<<endl;
	return 0;
}
