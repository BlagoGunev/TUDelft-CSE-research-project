#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
#define N 100010
using namespace std;
inline int read()
{
	int neg=1,num=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')neg=-1;
	for(;isdigit(c);c=getchar())num=(num<<1)+(num<<3)+c-'0';
	return neg*num;	
}
struct edge
{
	int nxt,to;
}Edge[N<<2];
int n,m,ans,head[N],cnt;
int L[N],R[N];
bool alive[N],tmp[N];
inline void Add_edge(int u,int v)
{
    Edge[++cnt].nxt=head[u];
    Edge[cnt].to=v;
    head[u]=cnt;
}
inline void Delete(int x)
{
    alive[x]=1;
    R[L[x]]=R[x];
    L[R[x]]=L[x];
}
int main()
{
    int a,b;
   	n=read();m=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read();
        Add_edge(u,v);Add_edge(v,u);
    }
    queue<int> q;
    for(int i=1;i<=n;i++)L[i]=i-1,R[i]=i+1;
    R[n]=0;
    for(int i=1;i<=n;i++)
		if(!alive[i])
	    {
	        Delete(i);
	        ++ans;
			q.push(i);
	        while(!q.empty())
	        {
	            int u=q.front();
	            q.pop();
	            for(int i=head[u];i;i=Edge[i].nxt)tmp[Edge[i].to]=1;
	            for(int i=R[0];i;i=R[i])if(!tmp[i] && !alive[i])q.push(i),Delete(i);
	            for(int i=head[u];i;i=Edge[i].nxt)tmp[Edge[i].to]=0;
	        }
	    }
    printf("%d\n",ans-1);
    return 0;
}