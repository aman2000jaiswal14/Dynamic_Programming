#include<bits/stdc++.h>
#include<string>
using namespace std;

int toint(char c)
{return int(c)-48;
}

int solve(string s,int i,int j,int istrue)
{
	if(i>j)
	return 0;
	
	if(i==j)
	{
		if(toint(s[i])==istrue)
		return 1;
	 else
		return 0;
	}
	
	int ans=0;
	
	for(int k=i+1;k<=j-1;k+=2)
	{
		int lt=solve(s,i,k-1,1);  // left true
		int lf=solve(s,i,k-1,0);  // left false
		int rt=solve(s,k+1,j,1);  // right true
		int rf=solve(s,k+1,j,0);  // right false
		int temp;
		
		if(s[k]=='&')
		{
			if(istrue==1)
			{
				temp=lt*rt;
			}
			else
			{
				temp=lt*rf+lf*rt+lf*rf;
			}
		}
		
		if(s[k]=='|')
		{
			if(istrue==1)
			{
				temp=lt*rt+lt*rf+lf*rt;
			}
			else
			{
				temp=lf*rf;
			}
		}
		
		if(s[k]=='^')
		{
			if(istrue==1)
			{
				temp=lt*rf+lf*rt;
			}
			else
			{
				temp=lt*rt+lf*rf;
			}
		}
		
		ans=ans+temp;
	}
	return ans;
}


int main()
{	
	int n;
	cin>>n;
	string s;
	cin>>s;
	cout<<solve(s,0,n-1,1);  // 1 for true
	return 0;
}
