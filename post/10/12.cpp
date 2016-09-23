#include <iostream>
#include <cmath>

using namespace std;

int n, d, x[100010], y[100010], ans = 2000002;

int main()
{
	int i, j;
	cin >> n >> d;
	for(i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		for(j = i - 1; j >= 1; j--)
		 if(abs(y[i] - y[j]) >= d)
		 {
		 	if(ans > abs(x[i] - x[j])) ans = abs(x[i] - x[j]);
		 }
	}
	if(ans == 2000002) cout << "-1";
	else cout << ans;
	return 0;
}