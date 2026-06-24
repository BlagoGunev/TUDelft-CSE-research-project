#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
#define N 810
int n,tot;
struct Node{
    int value;
    int x,y;
    bool operator < (const Node &a) const{
        return value<a.value;
    }
}A[N*N];
int f[N];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    n=read();
    for(int i=2;i<=2*n;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            A[++tot].value=read();
            A[tot].x=j;A[tot].y=i;
        }
    }
    sort(A+1,A+tot+1);
    for(int i=tot;i>=1;i--)
    {
        if(f[A[i].x]||f[A[i].y])
            continue;
        else
        {
            f[A[i].x]=A[i].y;
            f[A[i].y]=A[i].x;
        }
    }
    for(int i=1;i<=2*n;i++)
    {
        printf("%d ",f[i]);
    }
    printf("\n");
    return 0;
}