#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	string a,b;
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
	
	// is a is subsequence in b
	if(dp[m][n]==m)
	cout<<true;
	else
	cout<<false;
	
	return 0;
}
