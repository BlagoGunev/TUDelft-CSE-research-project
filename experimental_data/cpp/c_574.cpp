#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
#define N 100010
#define INF 0x7fffffff
int n;
int A[N];
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
    for(int i=1;i<=n;i++)
    {
        A[i]=read();
        while(A[i]%2==0)
            A[i]/=2;
        while(A[i]%3==0)
            A[i]/=3;
    }
    bool flag=true;
    for(int i=2;i<=n&&flag;i++)
    {
        if(A[i]!=A[i-1])
            flag=false;
    }
    if(flag)
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}