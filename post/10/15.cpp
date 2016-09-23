/*题号: 10
//题目: 老板♂的花盆
//提交: 2
//通过: 0
//提交你的代码*/
#include<bits/stdc++.h>
#define maxn 100000
struct pen{
	int x;
	int y;
} pens[maxn];
using namespace std;
int main() {
	int n, d;
	cin >> n >> d;
	int y = maxn;
	int first=0;
	for(int i=0; i<n; i++) {
		cin >> pens[i].x >> pens[i].y;
		if(y >= pens[i].y) {
			y = pens[i].y;
			first = i;
		}
	}
	int end = maxn;
	//cout << pens[first].y << ' ' << first;
	int time = pens[first].y + d;
	int cur=maxn;
	for(int i=0; i<n; i++) {
		if((pens[i].y>=time)&&(pens[i].y <= cur)) {
			end = i;
			cur = pens[i].y;
		}
	}
	if(end == -1) {
		cout << "-1";
	} 
	else cout << max(pens[end].x, pens[first].x) - min(pens[end].x, pens[first].x);
	return 0;
		
} 
