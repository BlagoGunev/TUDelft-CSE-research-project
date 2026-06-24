#include<iostream>

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<string>

#include<vector>

#include <ctime>

#include<queue>

#include<set>

#include<map>

#include<stack>

#include<iomanip>

#include<cmath>

#define mst(ss,b) memset((ss),(b),sizeof(ss))

#define maxn 0x3f3f3f3f

#define MAX 1000100

///#pragma comment(linker, "/STACK:102400000,102400000")

typedef long long ll;

typedef unsigned long long ull;

#define INF (1ll<<60)-1

using namespace std;

int n,m;

struct edge{

    int v,next;

}e[200100];

int tot=0,head[100100];

void Add(int u,int v){

    e[tot].v=v;

    e[tot].next=head[u];

    head[u]=tot++;

}

int flag=0,color[100100];

int num1=0,num2=0;

void DFS(int u){

    if(color[u]==1) num1++;

    else num2++;

    for(int i=head[u];i!=-1;i=e[i].next){

        int v=e[i].v;

        if(color[v]==-1){

            color[v]=color[u]^1;

            DFS(v);

        } else if(color[v]==color[u]){

            flag=1;

            return ;

        }

    }

}

int sz[100100];

int main(){

    mst(head,-1);

    mst(color,-1);

    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++){

        int u,v;

        scanf("%d%d",&u,&v);

        Add(u,v);

        Add(v,u);

        sz[u]++;

        sz[v]++;

    }

    if(m==0){

        ll ans=(ll)(n-1)*(n-2)*n/6;

        cout<<3<<" "<<ans<<endl;

        return 0;

    }

    ll ans1=0,ans2=0;

    for(int i=1;i<=n;i++){

        num1=num2=0;

        if(color[i]==-1){

            color[i]=1;

            DFS(i);

        } else continue;

        if(flag){

            cout<<0<<" "<<1<<endl;

            return 0;

        }

        if(e[head[i]].next==-1) ans2+=n-2;

        ans1+=(ll)num1*(num1-1)/2+(ll)num2*(num2-1)/2;

    }

    if(ans1) printf("1 %I64d\n",ans1);

    else printf("2 %I64d\n",ans2);

    return 0;

}