//find the minimum no of attempts to find the threshold floor ( in worst case).

#include<bits/stdc++.h>
using namespace std;
int egg(int f,int e)
{
	if(f==0||f==1)
	return f;
	if(e==1)
	return f;
	
	int ans=INT_MAX; 
	for(int k=1;k<=f;k++)
	{
		int temp=1 + max(egg(k-1,e-1),egg(f-k,e));   // max for worst case
		if(ans>temp)
		ans=temp;						// for minimum no. of attempts
	}
	return ans;
}

int main()
{
	int f,e;
	cin>>f>>e;   // f- floor , e- egg
	cout<<egg(f,e);
	return 0;
}
