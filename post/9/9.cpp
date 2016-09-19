/*题号: 9
//题目: 幻想乡♂早苗
//提交: 0
//通过: 0
//提交你的代码*/
#include<cstdio>
#include<cstring>
int x,y,x1,y1;
char s[5050];
int main()
{
	int T;
	x=y=0;
	scanf("%s",s);
	int n=strlen(s);
	scanf("%d",&T);
	int q=T%n;
	for(int i=0;i<n;i++)
	{
		if(q==i)
		{
			x1=x;y1=y;
		}
		switch(s[i])
		{
			case 'E':
				x++;break;
			case 'S':
				y--;break;
			case 'W':
				x--;break;
			case 'N':
				y++;break;
		}
	}
	x=x*(T/n)+x1;
	y=y*(T/n)+y1;
	printf("%d %d\n",x,y);
	return 0;
}