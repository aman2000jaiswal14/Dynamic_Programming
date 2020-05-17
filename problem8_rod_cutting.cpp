#include<bits/stdc++.h>
#include<vector>
# define ll long long 
using namespace std;
ll MAXIMUM(ll a,ll b)
{return a>=b?a:b;}

int main()
{	ll n,L;
	cin>>n>>L;
	ll l[n],p[n];
	for(ll i=0;i<n;i++)
	cin>>l[i];
	for(ll i=0;i<n;i++)
	cin>>p[i];
	
//	converting to original unbounded knapsack
	ll length[L],price[L];
	ll counter=0;
	for(ll i=0;i<L;i++)
	{
		length[i]=i+1;
		
		if(l[counter]-1==i)
		{
			price[i]=p[counter];
	    	counter++;
		}
		else
		price[i]=0;
	}
	
	
	ll dp[L+1][L+1];
	
//	initilization
	for(ll i=0;i<L+1;i++)
	{
		dp[i][0]=0;
		dp[0][i]=0;
	}
	
//	main code

	for(ll i=1;i<L+1;i++)
	{
		for(ll j=1;j<L+1;j++)
		{
			if(j>=length[i-1])
				dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	
	cout<<dp[L][L];
	return 0;
}
