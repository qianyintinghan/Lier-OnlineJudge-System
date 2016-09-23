/*题号: 10
//题目: 老板♂的花盆
//提交: 14
//通过: 0
//提交你的代码*/
#include<iostream>
#include<cmath>
using namespace std;

int x[100000],y[100000];
int n,d,maxi=200;
int main()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
	 for(int j=i+1;j<=n;j++)
	if(abs(y[j]-y[i]>=d)&&(abs(x[j]-x[i])<maxi))
	    maxi=abs(x[j]-x[i]);
	    cout<<maxi;
	    return 0;
	    
}