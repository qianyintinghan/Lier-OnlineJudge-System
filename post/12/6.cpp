/*题号: 12
//题目: (烧)水(问)题♂
//提交: 4
//通过: 0
//提交你的代码*/
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	const float a=4200;
	float n,t[50000]={0},tt;
	cin>>n;
	t[1]=100;
	tt=100;
	for(int j=2;j<=n;j++)
	  for(int i=j;i<=n;i++){
		float b=(t[i-1]-t[i])/2;
		t[i-1]-=b;
		t[i]=t[i-1];
		tt+=b;
	  }
	printf("%.2f",a*tt/n);
	//cout<<a*tt/n;
	return 0;
}