#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
	ll n,d;
	cin>>n>>d;
	ll i,j,arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	
//	calculate sum=(totalsum+difference)/2

	ll totalsum=0,sum;
	for(i=0;i<n;i++)
	totalsum+=arr[i];
	
	if((totalsum+d)%2==0)
	sum=(totalsum+d)/2;
	else
	{
		cout<<-1;
		return 0;
	}
	
	ll dp[n+1][sum+1];
	
//	initialization	
	
	memset(dp,-1,sizeof(dp));
	
	for(i=0;i<n+1;i++)
	dp[i][0]=1;
	
	for(i=1;i<sum+1;i++)
	dp[0][i]=0;
	
//	main code
	
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<sum+1;j++)
		{
			if(j>=arr[i-1])
				dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
			else
				dp[i][j]=dp[i-1][j];
					
		}
	}
	

	cout<<dp[n][sum];
	
	return 0;
	
}
