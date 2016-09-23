#include<algorithm>
#include<iostream>
using namespace std;
long long N,D,x[22222],y[22222],z[22222];
int main()
{
	int s=1;
	cin>>N>>D;
	for(int i=1;i<=N;i++)
	cin>>x[i]>>y[i];
	for(int i=1;i<=N;i++)
	for(int j=i;j<=N;j++)
	{
		long long n;
		n=abs(y[j]-y[i]);
		if(n>=D)
		{
			z[s]=abs(x[j]-x[i]);
			++s;
		}
	}
	if(s==1) cout<<"-1";
	else 
	{
		sort(z+1,z+s);
		cout<<z[1];
	}
	
	return 0;	
}