#include<bits/stdc++.h>
using namespace std;
#include<string>

int scrambled(string A,string B)
{		
	if(A.compare(B)==0)
	return 1;
	if(A.length() <= 1)
	return 0;
	
	int n=  A.length();	
	
	int flag = 0;
	for(int k=1;k<=n-1;k++)
	{		
//			cout<<endl<<A<<"   s1s2   "<<B<<"   "<<k<<endl;
//			cout<<endl<<A.substr(0,k)<<" A(0,k)B  "<<B.substr(0,k)<<endl;
//			cout<<A.substr(k,n)<<" A(k,n)B "<<B.substr(k,n)<<endl;
//			cout<<A.substr(0,k)<<" A(0,k)B(n-k,n) "<<B.substr(n-k,n)<<endl;
//			cout<<A.substr(k,n)<<" A(k,n)B(0,n-k) "<<B.substr(0,n-k)<<endl;
	if( 
		(scrambled(A.substr(0,k),B.substr(0,k))==1 && scrambled(A.substr(k,n),B.substr(k,n))==1) ||
		(scrambled(A.substr(0,k),B.substr(n-k,n))==1 && scrambled(A.substr(k,n),B.substr(0,n-k))==1)
		 )
		{
			flag=1;
		}
		
		if(flag==1)
		return 1;
	}
	return 0;
	
	
}

int main()
{
	string A,B;
	cin>>A>>B;
	cout<<scrambled(A,B);
	return 0;
}
