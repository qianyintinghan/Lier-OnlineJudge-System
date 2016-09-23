#include<iostream>
using namespace std;
int main()
{
	int N,x[15000],y[15000],m=0,n=0,ac;
	cin>>N;
	for(int i=1;i<=N;i++)
	cin>>x[i]>>y[i];
	for(int i=1;i<=N;i++)
	{
		m+=x[i];
		n+=y[i];
	}
	ac=n-m+1;
	cout<<ac;
	return 0;
}
