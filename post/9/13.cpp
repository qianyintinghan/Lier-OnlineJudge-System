/*���: 9
//��Ŀ: �����������
//�û�: 1234567
//�ύ: 4
//ͨ��: 0
//�ύ��Ĵ���*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int t;
char s[100];
int main()
{
	gets(s);
	int n=strlen(s);
	cin>>t;
	int a=0,b=0;
    if(n>=t)
	{
		for(int i=0;i<t;i++)
	 {
		if(s[i]=='E')
			a++;
		if(s[i]=='S')
		    b--;
		if(s[i]=='W')
		    a--;
		if(s[i]=='N')
		    b++;
	 }
	}
	if(n<t)
	{
		for(int i=0;i<n;i++)
		{
			if(s[i]=='E')
			a++;
		if(s[i]=='S')
		    b--;
		if(s[i]=='W')
		    a--;
		if(s[i]=='N')
		    b++;
		}
		int x=t-n;
		for(int i=0;i<x;i++)
		{
			if(s[i]=='E')
			a++;
		if(s[i]=='S')
		    b--;
		if(s[i]=='W')
		    a--;
		if(s[i]=='N')
		    b++;
		}
	}
	cout<<a<<"  "<<b;
	 return 0;
}