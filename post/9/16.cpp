#include<iostream>
#include<cstring>
using namespace std;
char s[2222];
int t,x=0,y=0,ss;
int main()
{
	cin>>s;
	ss=strlen(s);
	cin>>t;
	if(t/ss==0)
    {
		for(int i=0;i<ss;i++)
        {
			if(s[i]=='N') y++;
	 		if(s[i]=='S') y--;
			if(s[i]=='E') x++;
			if(s[i]=='W') x--;
        }
    }
	else if(t/ss!=0&&t%ss==0)
    {
		for(int i=0;i<ss;i++)
        {
			if(s[i]=='N') y++;
	 		if(s[i]=='S') y--;
			if(s[i]=='E') x++;
			if(s[i]=='W') x--;
        }
		x=t/ss*x;
		y=t/ss*y;
    }
	else if(t/ss!=0&&t%ss!=0)
    {
		for(int i=0;i<ss;i++)
        {
			if(s[i]=='N') y++;
	 		if(s[i]=='S') y--;
			if(s[i]=='E') x++;
			if(s[i]=='W') x--;
        }
		x=t/ss*x;
		y=t/ss*y;
		for(int i=0;i<t%ss;i++)
        {
			if(s[i]=='N') y++;
	 		if(s[i]=='S') y--;
			if(s[i]=='E') x++;
			if(s[i]=='W') x--;
        }
    }
	cout<<x<<" "<<y;
	return 0;
}