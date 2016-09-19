/*题号: 9
//题目: 幻想乡♂早苗
//用户: LY
//提交: 3
//通过: 0
//提交你的代码*/
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	long long t,x=0,y=0,n;
	string s;
	cin>>s>>t;
	n=s.size();
	for(long long i=1;i<=t;i++){
		if(i==n+1){
			t-=n;
			i=1;
		}
		switch(s[i-1]){
			case 'E':x+=1;break;
			case 'S':y-=1;break;
			case 'W':x-=1;break;
			case 'N':y+=1;break;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}