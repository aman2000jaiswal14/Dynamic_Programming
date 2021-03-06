#include<bits/stdc++.h>
#include<vector>
# define ll long long 
using namespace std;
ll MAXIMUM(ll a,ll b)
{return a>=b?a:b;}

int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,wt;
	cin>>n>>wt;
	ll w[n],v[n];
	ll dp[n+1][wt+1];
	for(int i=0;i<n;i++)
	cin>>w[i];
	for(int i=0;i<n;i++)
	cin>>v[i];
	
//	BASE CONDITION
	
	for(int i=0;i<n+1;i++)
		dp[i][0]=0;
	for(int i=0;i<wt+1;i++)
		dp[0][i]=0;
	
//	MAIN CODE
	for(int i=1;i<n+1;i++)	
	{	
		for(int j=1;j<wt+1;j++)
		{
			if(w[i-1]<=j)    //i-1 because array start from 0
				dp[i][j]=MAXIMUM((v[i-1]+dp[i-1][j-w[i-1]]),dp[i-1][j]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}	
	/*
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<wt+1;j++)
		{
			cout<<dp[i][j]<<"  ";
		}
		cout<<endl;
	}
	*/
	cout<<dp[n][wt]<<endl;	
	
	return 0;
}
