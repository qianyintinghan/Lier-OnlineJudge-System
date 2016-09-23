#include<cstdio>
#include<iostream>
using namespace std;
int main() {
	int n;
  cin >> n;
	int first[10000];
	int end[10000];
	int value[10000];

	for(int i = 1; i<=n; i++) {
		scanf("%d", &first[i]);
		scanf("%d", &end[i]);
	}
	for(int i = 1; i<=n; i++) {
		for(int j = 1; j<=n; j++) {
			if(end[i] < end[j]) {
				swap(first[i], first[j]);
				swap(end[i], end[j]);
			}
		}
	}
	for(int i = 1; i<=n; i++) {
		value[i] = end[i] - first[i] + 1;
	}
	for(int i = 1; i<=n; i++) {
		int max = value[i];
		for(int j = 1;j<=n; j++) {
			if((value[j] > max)&&(end[j]<=first[i])) {
				max += value[j];
			}
		}
		value[i] = max;
	}
	int more = 0;
	for(int i = 1; i<=n; i++) {
		if(value[i] >= more) more = value[i];
	}
	cout << more;
	return 0;
}