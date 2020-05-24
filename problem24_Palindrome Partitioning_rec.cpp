#include<bits/stdc++.h>
using namespace std;
#include<string>

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


int solve(string s,int i,int j)
{
	if(i>=j)
	return 0;
	if(ispalindrome(s,i,j)==true)
	return 0;
	
	int minimum=INT_MAX;
	
	for(int k=i;k<=j-1;k++)
	{
		int temp= solve(s,i,k)+solve(s,k+1,j)+1;
		if(minimum>temp)
		minimum=temp;
	}
	return minimum;
}



int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	cout<<solve(s,0,n-1);
	return 0;
}
