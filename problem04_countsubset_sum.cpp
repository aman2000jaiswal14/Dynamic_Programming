#include<bits/stdc++.h>
using namespace std;
#define ll long long
# define boost ios_base::sync_with_stdio(false);\
						cin.tie(NULL);
int main()
{	boost;
	ll n,sum;
	cin>>n>>sum;
	ll arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	ll dp[n+1][sum+1];
	memset(dp,-1,sizeof(dp));
	
	//initilization
	
	for(int i=0;i<n+1;i++)
	dp[i][0]=1;
	for(int i=1;i<sum+1;i++)
	dp[0][i]=0;
	
	// main code
	
	for(int i=1;i<n+1;i++)
	{
		for (int j=1;j<sum+1;j++)
		{
			if(j>=arr[i-1])
			{
				dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	
	cout<<dp[n][sum];
	return 0;
}															
