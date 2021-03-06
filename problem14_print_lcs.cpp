#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
	int m,n;
	string s="";
	cin>>m>>n;
	char a[m],b[n];
	cin>>a>>b;
	
	int dp[m+1][n+1];
	
	
	for(int i=0;i<m+1;i++)
	dp[i][0]=0;
	
	for(int i=0;i<n+1;i++)
	dp[0][i]=0;
	
	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(a[i-1]==b[j-1])
			{	
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	// Printing the lcs
	
	int i=m;
	int j=n;
	while(i>0 and j>0)
	{
		if(a[i-1]==b[j-1])
		{
			s.push_back(a[i-1]);
			i-=1;
			j-=1;
		}
		else
		{
			if(dp[i-1][j]>dp[i][j-1])
				i-=1;
			else
				j-=1;	
		}
	}
	
	reverse(s.begin(),s.end());
	cout<<s;
	cout<<" "<<dp[m][n];
	return 0;
}
