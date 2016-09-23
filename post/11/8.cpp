#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
struct hp{  
    int x,y,z;  
}a[15005];  
int n,i,j,k,maxn;  
int f[15005];  
  
int cmp(hp a,hp b)  
{  
    return a.y<b.y;  
}  
  
int main()  
{   
    scanf("%d",&n);  
    for (i=1;i<=n;i++)  
    {  
        scanf("%d%d",&a[i].x,&a[i].y);  
        a[i].z=a[i].y-a[i].x+1; 
    }  
    sort(a+1,a+n+1,cmp);  
    for (i=1;i<=n;i++)  
    {  
        f[i]=a[i].z;  
        if (maxn<f[i])  
          maxn=f[i];  
    }  
    for (i=2;i<=n;i++)  
    {  
        k=0;  
        for (j=1;j<=i-1;j--)  
          if (a[i].x>a[j].y&&k<f[j])  
            k=f[j];  
        f[i]+=k;  
        if (maxn<f[i])  
          maxn=f[i];  
    }  
    printf("%d",maxn);   
}  