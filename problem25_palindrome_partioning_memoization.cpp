#include<bits/stdc++.h>
#include<string>
using namespace std;

static int t[10001][10001];


bool ispalindrome(string s,int i,int j)
{
	
	int n = i+j+1;
	int n2= n/2;
	for(int l=i;l<n2;l++)
	{
		if(s[l]!=s[n-l-1])
		return 0;
	}
	return 1;
}

int solve(string s,int i ,int j)
{
	if(i>=j)
	return 0;
	if(ispalindrome(s,i,j)==true)
	return 0;
	
	if(t[i][j]!=-1)
	return t[i][j];
	
	int minimum = INT_MAX;
	for(int k=i;k<=j-1;k++)
	{	
		int left,right;
		if(t[i][k]!=-1)
			left = t[i][k];
		else
			left= solve(s,i,k);
		
		if(t[k+1][j]!=-1)
			right = t[k+1][j];
		else
			right= solve(s,k+1,j);	
			
		int temp=left+right+1;
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
	string s;
	cin>>s;
	cout<<solve(s,0,n-1);
	return 0;
}
