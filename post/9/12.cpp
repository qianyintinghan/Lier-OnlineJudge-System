#include <iostream>
#include <cstring>

using namespace std;

int t, x, y, la;
char a[5050];

int main()
{
	int i, j;
	cin >> a;
	la = strlen(a);
	cin >> t;
	j = 0;
	for(i = 1; i <= t; i++)
	{
		switch(a[j])
		{
			case 'E': x++; break;
			case 'S': y--; break;
			case 'W': x--; break;
			case 'N': y++; break;
		}
		j++;
		if(j == la) j = 0;
	}
	cout << x << " " << y;
	return 0;
}