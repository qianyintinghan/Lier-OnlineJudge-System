/*题号: 11
//题目: 奶牛的智商♂
//用户: rqy
//提交: 0
//通过: 0
//提交你的代码*/
#include<cstdio>
#include<algorithm>
using namespace std;
struct qj{
	int x,y;
	bool operator < (const qj &m)const{
		if(y!=m.y) return y<m.y;
		return x>m.x;
	}
};
int n;
qj x[15005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i].x,&x[i].y);
	sort(x+1,x+n+1);
	int q=0;
	int rr=0;
	for(int i=1;i<=n;i++) if(rr<x[i].x)
	{
		q+=x[i].y-x[i].x+1;
		rr=x[i].y;
	}
	printf("%d",q);
	return 0;
}