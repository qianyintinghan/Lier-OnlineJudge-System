#include<bits/stdc++.h>
#define maxn 10
using namespace std;
int main() {
	int i = 0;
	int x = 0, y = 0;
	string command;
	cin >> command;
	int t;
	cin >> t;
	while(t-- >= 0) {
		char c = command[i++];
		if(c == 'N') y++;
		else if(c == 'S') y--;
		else if(c == 'W') x--;
		else if(c == 'E') x++;
		if(i>=command.length()) i=-1;
	}
	cout << x << ' ' << y;
	return 0;
} 