#include<iostream>
using namespace std;
int main()
{
	int T,a,xun,sheng;
	long long x1=0,y1=0,x=0,y=0;
	string s;
	cin>>s>>T;
	a=s.length()-1;
	if(T>a+1){
	for(int i=0;i<=a;i++)
	{
		if(s[i]=='N')
		{
			y1++;
		}
		if(s[i]=='E')
		{
			x1++;
		}
		if(s[i]=='S')
		{
			y1--;
		}
		if(s[i]=='W')
		{
			x1--;
		}
	}
	xun=T/(a+1);
	sheng=T%(a+1);
	x+=x1*xun;
	y+=y1*xun;
	for(int i=0;i<=sheng-1;i++)
	{
		if(s[i]=='N')
		{
			y++;
		}
		if(s[i]=='E')
		{
			x++;
		}
		if(s[i]=='S')
		{
			y--;
		}
		if(s[i]=='W')
		{
			x--;
		}
	}
	cout<<x<<" "<<y;
}

	else
	{
		for(int i=0;i<=T-1;i++)
	{
		if(s[i]=='N')
		{
			y++;
		}
		if(s[i]=='E')
		{
			x++;
		}
		if(s[i]=='S')
		{
			y--;
		}
		if(s[i]=='W')
		{
			x--;
		}
	}
	cout<<x<<" "<<y;
}
}
