/*���: 9
//��Ŀ: �����������
//�û�: LY
//�ύ: 3
//ͨ��: 0
//�ύ��Ĵ���*/
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