#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];

int egg(int f,int e)
{
	if(f==0||f==1)
	return f;
	if(e==1)
	return f;
	
	if(t[f][e]!=-1)
	return t[f][e];
	
	int ans=INT_MAX;
	for(int k=1;k<=f;k++)
	{
		int temp=1+ max(egg(k-1,e-1),egg(f-k,e));
		if(ans>temp)
		ans=temp;
	}
	t[f][e]=ans;
	return ans;
}
int main()
{
	memset(t,-1,sizeof(t));
	int f,e;
	cin>>f>>e;
	cout<<egg(f,e);
	return 0;
}
