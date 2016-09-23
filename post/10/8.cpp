/*题号: 11
//题目: 老板的花盆
//提交: 150
//通过: 150
//提交你的代码*/
#include<iostream>
#include <algorithm> 
#include <cmath>
#include <cstdio>
using namespace std;
struct eee{
	int x;int y;
}a[100001];
int c(eee a,eee b)
{
	return a.y>b.y;
}
int d,n,s=999999,maxy=-1,miny=1000001,e=1;
int main()
{
	//freopen("123.txt","r",stdin);
	//freopen("456.txt","w",stdout);
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		if(a[i].y>maxy)
			maxy=a[i].y;
		if(a[i].y<miny)
			miny=a[i].y;
	}
	if(maxy-miny<d)
	{
		cout<<"-1";
		return 0;
	}
	sort(a+1,a+n+1,c);
	for(int i=1;i<=n;i++)
	{
		if(s==0)
		{
			cout<<s;
			return 0;
		}
		for(int j=n;j>=e;j--)
		{
			if(a[i].y-a[j].y>=d)
			{
				if(abs(a[i].x-a[j].x<s))
				{
					s=abs(a[i].x-a[j].x);
				}
			}
			else
			{
				e=j;
				break;
			}
		}
	}
    cout<<s;
}