#include<bits/stdc++.h>

#define N 100005

using namespace std;

int num[(1<<20)+1];

int ai[N];

long long ans=0;

int n,m,k,sq;

struct query{

    int l,r,id;//(]

}que[N];

long long out[N];

bool cmpb(const query &a,const query &b){

    int t1=a.l/sq,t2=b.l/sq;

    if(t1!=t2) return t1<t2;

    else if(t1&1) return a.r<b.r;

    else return a.r>b.r;

}

inline void add(int t){

    ans+=num[t^k];num[t]++;

}

inline void del(int t){

    num[t]--;ans-=num[t^k];

}

int main(){

    scanf("%d%d%d",&n,&m,&k);sq=sqrt(n);

    for(int i=1;i<=n;i++) scanf("%d",&ai[i]),ai[i]^=ai[i-1];

    for(int i=1;i<=m;i++) scanf("%d%d",&que[i].l,&que[i].r),que[i].l--,que[i].id=i;

    sort(que+1,que+m+1,cmpb);

    int l=0,r=-1;

    for(int i=1;i<=m;i++){

        if(r<que[i].r) for(int j=r+1;j<=que[i].r;j++) add(ai[j]);

        else if(r>que[i].r) for(int j=r;j>que[i].r;j--) del(ai[j]);

        if(l<que[i].l) for(int j=l;j<que[i].l;j++) del(ai[j]);

        else if(l>que[i].l) for(int j=l-1;j>=que[i].l;j--) add(ai[j]);

        out[que[i].id]=ans;

        l=que[i].l;r=que[i].r;

    }

    for(int i=1;i<=m;i++) printf("%I64d\n",out[i]);

    return 0;

}