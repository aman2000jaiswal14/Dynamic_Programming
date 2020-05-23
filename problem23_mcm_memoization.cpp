#include<bits/stdc++.h>
using namespace std;
int t[10001][10001];

int mcm(int a[],int i,int j)
{
	if(i>=j)
	return 0;
	if(t[i][j]!=-1)
	return t[i][j];
	
	int minimum=INT_MAX;
	for(int k=i;k<=j-1;k++)
	{
		int temp=mcm(a,i,k)+mcm(a,k+1,j)+a[i-1]*a[k]*a[j];
		
		if(minimum>temp)
		minimum=temp;
	}
	t[i][j]=minimum;
	return minimum;
}
int main()
{	
	memset(t,-1,sizeof(t));
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<< mcm(a,1,n-1);
	return 0;
}
