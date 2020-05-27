#include<bits/stdc++.h>
#include<string>
#include<unordered_map>
using namespace std;
unordered_map<string,int> mp;

int scrambled(string A,string B)
{
	if(A.compare(B)==0)
	return 1;
	if(A.length()<=1)
	return 0;
	
	string key(A+" "+B);
	if(mp.find(key)!=mp.end())
	return mp[key];
	int flag=0;
	int n=A.length();
	for(int k=1;k<=n-1;k++)
	{	
		if(
		(scrambled(A.substr(0,k),B.substr(0,k))==1 && scrambled(A.substr(k,n),B.substr(k,n))==1) ||
		(scrambled(A.substr(0,k),B.substr(n-k,n))==1 && scrambled(A.substr(k,n),B.substr(0,n-k)))
		)
		{
			flag=1;
		}
		if(flag==1)
		return 1;
	}
	mp[key]=0;
	return 0;	
}
int main()
{	
	mp.clear();
	string A;
	string B;
	cin>>A>>B;
	cout<<scrambled(A,B);
	return 0;
}
