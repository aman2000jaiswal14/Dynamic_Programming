#include<bits/stdc++.h>
using namespace std;
int minimum(int a,int b)
{

	if(a>b)
	return b;
	else if(a<=b)
	return a;
}
int main()
{
	int n,sum;
	cin>>n>>sum;
	int coin[n];
	for(int i=0;i<n;i++)
	cin>>coin[i];
	
	int dp[n+1][sum+1];
	
//	initialization
	
	for(int i=1;i<n+1;i++)
		dp[i][0]=0;
	for(int i=0;i<sum+1;i++)
		dp[0][i]=INT_MAX-1;    	// int_max-1 because after adding +1 in the main code its value become int_max 
		
	for(int i=1;i<sum+1;i++)
	{
		if( i% coin[0]==0)
			dp[1][i]=i/coin[0];
		else
			dp[1][i]=INT_MAX-1;		
	}
	
//	main code

	for(int i=2;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(j>=coin[i-1])
			dp[i][j]=min(1+dp[i][j-coin[i-1]],dp[i-1][j]);
			
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	
	/*	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			cout<<dp[i][j]<<" ";
			
		}
		cout<<endl;
	}
	*/
	cout<<dp[n][sum];
	
	return 0;
		
}
