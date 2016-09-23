#include<iostream>
#include<algorithm>
using namespace std;
struct oo{
	int x,y;
}p[100001];
int com(oo a,oo b)
{
	return a.x<b.x;
}
int main ()
{
	std::ios::sync_with_stdio(false);
	int n,d;
	int max[100001];
	for(int i=0;i<n;i++)
	max[i]=123456789;
	cin>>n>>d;
	for(int i=0;i<n;i++)
	cin>>p[i].x>>p[i].y;
	sort(p+0,p+n,com);
	for(int i=0;i<n;i++)
	{
		int a=p[i].y;
		for(int j=i+1;j<n;j++)
		{
			int b=p[j].y,c;
			if(a>b)
			c=a-b;
			else
			c=b-a;
			if(c>=d&&max[i]>p[j].x-p[i].x)
			max[i]=p[j].x-p[i].x;
		}
		
	}
	sort(max+0,max+n);
	if(max[0]==123456789)
	{
		cout<<"-1";
		return 0;
	}
	cout<<max[0];
	return 0;
}
