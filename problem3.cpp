#include<bits/stdc++.h>
#include<vector>
#include<list>
#include<string>
#include<cstdlib>
using namespace std;
#define pb push_back
#define ll long long
#define boost ios_base::sync_with_stdio(false);\
			cin.tie(NULL);
			
ll MAXIMUM(ll a,ll b)
{return a>=b?a:b;}

ll MINIMUM(ll a,ll b)
{return a<b?a:b;}	

bool OR(int a,int b)
{return (a==0&b==0)?0:1;}

//SUBSET_SUM

void subset_sum(ll w[],ll n,ll sum)
{	
	bool dp[n+1][sum+1];
//	Base condition
	dp[0][0]=1;
	for(int i=1;i<n+1;i++)
	dp[i][0]=1;
	for(int i=1;i<sum+1;i++)
	dp[0][i]=0;

//	MAIN CODE
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(w[i-1]<=j)
			{
				dp[i][j]=OR(dp[i-1][j-w[i-1]],dp[i-1][j]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	/*
		
			for(int i=0;i<n;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			cout<<dp[i][j]<<"  ";
		}
		cout<<endl;
	}				
*/
	cout<<dp[n][sum]<<endl;
	
}




int main()
{	boost;
	ll t;
	cin>>t;
	for(int tt=0;tt<t;tt++)
	{
		ll n,sum=0;
		cin>>n;
		ll w[n];
		for(int i=0;i<n;i++)
		cin>>w[i];
		
		for(int i=0;i<n;i++)
		sum+=w[i];
		if(sum%2!=0)
		{
			cout<<false<<endl;
			break;
		}
		sum=sum/2;
		subset_sum(w,n,sum);
	}
	return 0;
}

