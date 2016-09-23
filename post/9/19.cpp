#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	long long b,d=0,e,c=0,f=0;
	cin>>a>>b;
	e=a.length();
	for(long long i=1;i<=b;++i)
	{
		if(a[d]=='E'){c++;d++;}
		else if(a[d]=='S'){f--;d++;}
		else if(a[d]=='W'){c--;d++;}
		else if(a[d]=='N'){f++;d++;}
		if(d==e)d=0;
	}
	cout<<c<<" "<<f;
	return 0;
}