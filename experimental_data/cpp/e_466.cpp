#include<bits/stdc++.h>

using namespace std;

int me[100050];

int st[100050];

int ed[100050];

int peo[100050];

int xx[100050];

int num;

int findme(int a){

    //cout << a << endl;

    if(a!=me[a])return me[a]=findme(me[a]);

    return a;

}

struct edge

{

    int id;

    edge *next;

};

edge edges[100500<<1];

edge *adj[100500];

int ednum;

inline void addEdge(int a,int b)

{

    edge *tmp;

    tmp=&edges[ednum++];

    tmp->id=b;

    tmp->next=adj[a];

    adj[a]=tmp;

}

int fa[200500],top[200500],son[200500],siz[200500],id[200500],fid[200500],dep[200500];

bool vis[200500];

void dfs1(int me,int deep)

{

    int maxsiz=-1;

    vis[me]=1;

    dep[me]=deep;

    siz[me]=1;

    for(edge *it=adj[me];it;it=it->next)

    {

        if(!vis[it->id])

        {

            fa[it->id]=me;

            dfs1(it->id,deep+1);

            if(maxsiz<siz[it->id])

            {

                maxsiz=siz[it->id];

                son[me]=it->id;

            }

            siz[me]+=siz[it->id];

        }

    }

}

void dfs2(int me,int t)

{

    vis[me]=1;

    top[me]=t;

    id[me]=++num;

    fid[num]=me;

    if(son[me])

    {

        dfs2(son[me],t);

    }

    for(edge *it=adj[me];it;it=it->next)

    {

        if(!vis[it->id])

        {

            dfs2(it->id,it->id);

        }

    }

}

int main()

{

    int n,m,id_n=0,id_m=0;

    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++){

        me[i]=i;

    }

    for(int i=1;i<=m;i++){

        int typ;

        scanf("%d",&typ);

        if(typ==1){

            int a,b;

            scanf("%d%d",&a,&b);

            addEdge(a,b);

            addEdge(b,a);

            a=findme(a);

            me[a]=b;

        }

        else if(typ==2){

            int x;

            scanf("%d",&x);

            id_n++;

            st[id_n]=x;

            ed[id_n]=findme(x);

        }

        else if(typ==3){

            int x,a;

            id_m++;

            scanf("%d%d",&x,&a);

            peo[id_m]=x;

            xx[id_m]=a;

        }

    }

    num=0;

    memset(vis,0,sizeof(vis));

    memset(son,0,sizeof(son));

    ednum=0;

    for(int i=1;i<=n;i++){

        if(!vis[i]){

            dfs1(i,1);

        }

    }

    memset(vis,0,sizeof(vis));

    for(int i=1;i<=n;i++){

        if(!vis[i]){

            dfs2(i,i);

        }

    }

    for(int i=1;i<=id_m;i++){

        bool ok=0;

        int a=st[xx[i]],b=ed[xx[i]];

        int f1=top[a],f2=top[b];

        while(f1!=f2)

        {

            if(dep[f1]<dep[f2])

            {

                swap(f1,f2);

                swap(a,b);

            }

            if(id[peo[i]]>=id[f1]&&id[peo[i]]<=id[a]){

                ok=1;break;

            }

            a=fa[f1];

            f1=top[a];

        }

        if(dep[a]>dep[b])

            swap(a,b);

        if(id[peo[i]]>=id[a]&&id[peo[i]]<=id[b])

            ok=1;

        if(ok)puts("YES");

        else puts("NO");

    }

}