/*old:*/
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n,d,mn=123456,x[100050],y[100050];
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		for(int j=i-1;j>=1;j--){
			if(abs(x[j]-x[i])<mn)
		      if(abs(y[j]-y[i])>=d){
	  		    mn=abs(x[j]-x[i]);
	  		    if(mn==0){
	  			  printf("%d",mn);
	  			  return 0;
	  		    }
	  	      }
		}
	}
	if(mn==123456)
	  printf("-1");
	else
	  printf("%d",mn);
	return 0;
}