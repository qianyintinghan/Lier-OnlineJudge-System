/*old:*/
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	int x=0,y=0,t,ws=0;
	cin>>s>>t;
	while(t>0)
	{
		if(ws==s.size()) ws=0;
		if(s[ws]=='W') x-=1;
		if(s[ws]=='E') x+=1;
		if(s[ws]=='S') y-=1;
		if(s[ws]=='N') y+=1;
		t-=1;
		ws+=1;
	}
	cout<<x<<" "<<y;
	return 0;
}
