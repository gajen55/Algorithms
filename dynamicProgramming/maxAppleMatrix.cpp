#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, m;
    cin>>n>>m;
    ll a[n][m];
    ll s[n][m];
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            cin>>a[i][j];
            s[i][j] = a[i][j];
            
        }
    }
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            if(i > 0 && j > 0 )
            {
                s[i][j] = max(s[i][j-1], s[i-1][j]) + a[i][j];
            }
            else if(i > 0)
            {
                s[i][j] = s[i-1][j] +  a[i][j];
            }
            else if(j > 0)
            {
                s[i][j] = s[i][j-1] +  a[i][j];
            }
            else;
        }
    }
    cout<<s[n-1][m-1]<<endl;
	return 0;
}
