#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define ll long long 
#define boost ios_base::sync_with_stdio(false);\
cin.tie(NULL);

bool OR(int a,int b)
{return (a==0&b==0)?0:1;}

int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
//	CALCULATE TOTAL SUM/2
	ll totalsum=0,sum;
	for(ll i=0;i<n;i++)
	totalsum+=arr[i];
	
	sum=totalsum/2;
	
	
	bool dp[n+1][sum+1];
	
//	initialization

	memset(dp,-1,sizeof(dp));
	
	for(ll i=0;i<n+1;i++)
	dp[i][0]=1;
	
	for(ll i=1;i<sum+1;i++)
	dp[0][i]=0;
	
//	main code	

	for(ll i=1;i<n+1;i++)
	{
		for(ll j=1;j<sum+1;j++)
		{
			if(j>=arr[i-1])
			{
				dp[i][j]=OR(dp[i-1][j-arr[i-1]],dp[i-1][j]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	
	ll max_sum=-1;
	for(ll i=sum;i>=0;i--)
	{
		if(dp[n][i]==1)
		{
			max_sum=i;
			break;
		}
	}
	
	cout<<totalsum-2*max_sum;
	
	return 0;
		
}
						
