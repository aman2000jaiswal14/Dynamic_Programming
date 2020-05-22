#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string a;
	cin>>a;
	
	//reverse string a
	
	string b(a);
	reverse(a.begin(),a.end());
	
	int dp[n+1][n+1];
	
	for(int i=0;i<n+1;i++)
	{
		dp[0][i]=0;
		dp[i][0]=0;
	}
	
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
					
		}
	}
	
	cout<<dp[n][n];
	
	return 0;
	
}
