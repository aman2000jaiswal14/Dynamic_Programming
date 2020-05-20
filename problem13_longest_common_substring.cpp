#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,ans=0;
	cin>>m>>n;
	char x[m],y[n];
	cin>>x>>y;
	
	int dp[m+1][n+1];
	
	for(int i=0;i<m+1;i++)
	dp[i][0]=0;
	for(int i=0;i<n+1;i++)
	dp[0][i]=0;
	
	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(x[i-1]==y[j-1])
			dp[i][j]=1+dp[i-1][j-1];
			else
			{
			ans=max(dp[i-1][j-1],ans);
			dp[i][j]=0;
			}
		}
	}
	
	cout<<ans;
	return 0;
}
