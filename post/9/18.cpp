#include<iostream>
#include<cstring>
using namespace std;
int main() {
	string move;
	long long time,lmove;
	long long x=0,y=0,yushu,xhj;  
	cin>>move>>time;
	lmove=move.size();
	xhj=time/lmove+1;
	yushu=time%lmove;
	for(int i=1;i<=xhj;i++){
		if(i==xhj)
		lmove=yushu;
		for(int j=0;j<=lmove-1;j++){
			if(move[j]=='E'){
				x++;
				continue; 
			}	
			if(move[j]=='S'){
				y--;
				continue;
			}
			if(move[j]=='W'){
				x--;
				continue;
			}
			if(move[j]=='N'){
				y++;
				continue;
			}
		}
	} 
	cout<<x<<" "<<y;
	return 0; 
}