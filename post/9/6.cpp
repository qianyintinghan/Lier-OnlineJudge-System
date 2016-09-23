#include<iostream>
#include<cstring>
using namespace std;
int main(){
	long long m,t,x=0,y=0,p,q,n;
	string s;
	cin>>s>>t;
	n=s.size();
	for(long long i=0;i<n;i++){
		switch(s[i]){
			case 'E':x++;break;
			case 'S':y--;break;
			case 'W':x--;break;
			case 'N':y++;break;
		}
	}
	p=x;q=y;
	m=t/n;
	x=m*p;
	y=m*q;
	m=t%n;
	for(long long i=1;i<=m;i++){
		switch(s[i-1]){
			case 'E':x++;break;
			case 'S':y--;break;
			case 'W':x--;break;
			case 'N':y++;break;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
