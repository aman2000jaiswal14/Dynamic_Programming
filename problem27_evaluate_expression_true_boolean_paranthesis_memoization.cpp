#include<bits/stdc++.h>
#include<string>
//#include <map> 
using namespace std;
int t[1001][1001][2];
//map<string,int> mp;
int toint(char c)
{
	return int(c-48);
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
//	string tempvar= to_string(i);
//	tempvar.push_back(" ");
//	tempvar.pushback(to_string(j));
//	tempvar.pushback(" ");
//	tempvar.pushback(to_string(istrue));
//	if(mp[tempvar]!=mp.end())
	
	if(t[i][j][istrue]!=-1)
	return t[i][j][istrue];
	
	int ans=0;
	
	for(int k=i+1;k<=j-1;k+=2)
	{
		int lt=solve(s,i,k-1,1);
		int lf=solve(s,i,k-1,0);
		int rt=solve(s,k+1,j,1);
		int rf= solve(s,k+1,j,0);
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
//	mp[tempvar]=ans;
	t[i][j][istrue]=ans;
	return ans;
}

int main()
{	
//	mp.clear();
	memset(t,-1,sizeof(t));
	int n;
	cin>>n;
	string s;
	cin>>s;
	cout<<solve(s,0,n-1,1);
	return 0;
}
