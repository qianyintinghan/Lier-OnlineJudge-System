/*old:*/
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int t,l,m,n,x=0,y=0;
    string a;
    cin>>a;
    l=a.size();
    cin>>t;
    n=t/l;m=t%l;
    for(int i=0;i<l;i++)
    {
        if(a[i]=='N') y++;
        if(a[i]=='S') y--;
        if(a[i]=='E') x++;
        if(a[i]=='W') x--;
    }
    x=x*n;y=y*n;
    for(int i=0;i<m;i++)
    {
        if(a[i]=='N') y++;
        if(a[i]=='S') y--;
        if(a[i]=='E') x++;
        if(a[i]=='W') x--;
    }
    cout<<x<<' '<<y;
    return 0;
}
