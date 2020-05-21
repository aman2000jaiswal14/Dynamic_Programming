#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	char a[m],b[n];
	cin>>a>>b;
	
	int dp[m+1][n+1];
	
	for(int i=0;i<m+1;i++)
	dp[i][0]=0;
	for(int j=0;j<n+1;j++)
	dp[0][j]=0;
	
	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(a[i-1]==b[j-1])
			dp[i][j]=dp[i-1][j-1]+1;
			else
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			
		}
	}
	//    insertion         deletion
	cout<<n-dp[m][n]<<" "<<m-dp[m][n];
	return 0;
	
}
