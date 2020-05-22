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
	{
		dp[i][0]=0;
	}
	
	for(int i=0;i<n+1;i++)
	dp[0][i]=0;
	
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
	
//	print shortest common subsequence
	string s;
	int i=m;
	int j=n;
	while(i>0 && j>0)
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
			{
				s.push_back(a[i-1]);
				i-=1;
			}
			else
			{
				s.push_back(b[j-1]);
				j-=1;
			}
		}
		
	}
	while(i>0)
	{
		s.push_back(a[i-1]);
		i-=1;
	}
	while(j>0)
	{
		s.push_back(b[j-1]);
		j--;
	}
	reverse(s.begin(),s.end());
	cout<<s;
	cout<<" "<<m+n-dp[m][n];
	return 0;
	
}
