#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=20010;
int n,m,f[N],tt;
int find(int x){return f[x]==x?f[x]:(f[x]=find(f[x]));}
void link(int x,int y){f[find(x)]=find(y),f[find(x+tt)]=find(y+tt);}
void cut(int x,int y){f[find(x+tt)]=find(y),f[find(x)]=find(y+tt);}
int main()
{
    int T;scanf("%d",&T);
    while(T --> 0)
    {
        int k;scanf("%d%d%d",&n,&m,&k);
        tt=n+m-2;
        for(int i=1;i<=tt*2;i++) f[i]=i;
        for(int i=1;i<=k;i++)
        {
            int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(y2==y1+1) link(x1,y1+n-1);
            else cut(x1,y2+n-1);
        }
        bool hv=true;
        for(int i=1;i<=tt;i++) if(find(i)==find(i+tt)){hv=false;break;}
        puts(hv?"YES":"NO");
    }
    return 0;
}