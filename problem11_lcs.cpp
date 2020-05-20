#include<bits/stdc++.h>
using namespace std;

int id=100
int rc[id][id];

int lcs(char a[],char b[],int n,int m)
{
	if(n==0 || m==0)
	{
	return 0;
	}
	if(rc[n][m]!=-1)
	{
		return rc[n][m];
	}
	if(a[n-1]==b[m-1])
	{
		rc[n][m]=lcs(a,b,n-1,m-1)+1;
		return rc[n][m];
	}
	else
	{
		rc[n][m]= max(lcs(a,b,n-1,m),lcs(a,b,n,m-1))
		return rc[n][m];
	}
}

int main()
{	memset(rc,-1,sizeof(rc));
	int n,m;
	cin>>n>>m;
	char a[n],b[m];
	cin>>a;
	cin>>b;
	cout<<lcs(a,b,n,m);	
}
