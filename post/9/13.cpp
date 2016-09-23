#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
char s[1000];
int t;
int main()
{
	int a=0,b=0,i=0;
	gets(s);
	int n=strlen(s);
	cin>>t;
	while(t>0)
	{
		if(i==n) i=0;
		if(s[i]=='E')  a++;
		if(s[i]=='S')  b--;
		if(s[i]=='W')  a--;
		if(s[i]=='N')  b++;
		t--;  i++;
	}
	cout<<a<<" "<<b;
	return 0;
}
