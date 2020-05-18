#include<bits/stdc++.h>
using namespace std;
# define ll long long
int main()
{
	ll n,sum;
	cin>>n>>sum;
	ll coin[n];
	for(int i=0;i<n;i++)
	{
		cin>>coin[i];
	}
	
	int dp[n+1][sum+1];
	
	for(int i=0;i<n+1;i++)
	{
		dp[i][0]=1;
	}
	for(int i=1;i<sum+1;i++)
	dp[0][i]=0;
	
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(j>=coin[i-1])
			dp[i][j]=dp[i][j-coin[i-1]]+dp[i-1][j];
			else
			dp[i][j]=dp[i-1][j];
			
		}
	}
	cout<<dp[n][sum];
	return 0;
}
