/*���: 9
//��Ŀ: �����������
//�ύ: 5
//ͨ��: 0
//�ύ��Ĵ���*/
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	char str[5001];
	gets(str);
	long long n,m,x(0),y(0),len(0);
	for(long long i=0;str[i]>='A' && str[i]<='Z';i++,len++);
	cin>>n;
	for(long long i=0;i<n;i++){
		m=i%len;
		switch(str[m]){
			case 'N':++y;break;
			case 'S':--y;break;
			case 'E':++x;break;
			case 'W':--x;break;
		}
	}
	cout<<x<<' '<<y;
	return 0;
}