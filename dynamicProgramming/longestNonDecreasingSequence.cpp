#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;    
	cin>>n;
	ll a[n];
	ll s[n];
	ll ans = 0;
	for(ll i=0; i<n; i++)
	{
	    cin>>a[i];
	    s[i] = 1;
	}
	
    for(ll i=1; i<n; i++)
	{
	    for(ll j=i-1; j>=0; j--)
	    {
	        if(a[i]>a[j] && (s[i]<s[j]+1))
	            s[i] = s[j]+1;
	       if(ans<s[i])
	        ans = s[i];
	    }
	}
	cout<<ans<<endl;
	
	return 0;
}
