#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// get GCD of 2 numbers
ll gcd(ll a, ll b)
{
	if(a==0)
		return b;
	return(gcd(b%a,a));
}

// Get sum of all digits in a number
ll getSum(ll n)
    {
    int sum;
    while(n%10)
        {
        sum += (n%10);
        n = n/10;
    }
    return sum;
}

// Check whether a number is prime or not
bool find_prime(ll n)
{
    if(n==2 || n==3)
		  return true;
	  if(n%2==0)
		  return false;
	  if(n%3==0)
		  return false;
  	ll i = 5;
	  ll w = 2;

	  while(i*i <= n)
    {
		  if(n%i==0)
			  return false;
		  i += w;
		  w = 6-w;
	  }
	  return true;
}

int main()
{
	cout<<gcd(4,8);
	return 0;
}
