/*题号: 11
//题目: 奶牛的智商♂
//提交: 5
//通过: 0
//提交你的代码*/
#include<iostream>
#include<algorithm>
using namespace std;
struct oo{
	int x,y,c;
}p[15001];
int all=0,n;
int xx(int ain,int sum)
{
	for(int i=0;i<n;i++)
	if(p[i].x>ain)
	{
		sum+=p[i].c;
		if(sum>all)
		all=sum;
		xx(p[i].y,sum);
		sum-=p[i].c;
	}
}
int main ()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p[i].x>>p[i].y;
		p[i].c=p[i].y-p[i].x+1;
	}
	xx(-1,0);
	cout<<all;
	return 0;
}