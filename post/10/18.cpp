#include<iostream>
#include<algorithm>
using namespace std;
int a[100100][2];
int main()
{
	long long n,d,minans=100000000,temp1,temp2;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i][1]>>a[i][2];
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=n-i;j++)
			if(a[j][1]>a[j+1][1]){
				temp1=a[j][1];
				a[j][1]=a[j+1][1];
				a[j+1][1]=temp1;
				temp2=a[j][2];
				a[j][2]=a[j+1][2];
				a[j+1][2]=temp2;
			}
/*	
	for(int i=1;i<=n;i++)
		cout<<a[i][1]<<" ";
		cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i][2]<<" ";
		cout<<endl;
*/
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		if(abs(a[j][2]-a[i][2])>=d&& 
			a[j][1]-a[i][1]<minans)
		minans=abs(a[j][1]-a[i][1]);
	if(minans==100000000) 
		cout<<"-1"<<endl;
	else
		cout<<minans<<endl;
	return 0;
}