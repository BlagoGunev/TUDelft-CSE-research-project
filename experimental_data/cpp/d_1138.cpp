#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")
#include<bits/stdc++.h>
#define N 500005
using namespace std;

#define v1 first
#define v2 second
#define p 1000000007
#define ll long long
#define pb push_back
#define mid ((l+r)>>1)
#define vec vector<int>
#define pr pair<int,int>
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof a)
#define For(x) for(int y,i=head[x];(y=e[i].to);i=e[i].nxt)

inline int POW(int a,int b=p-2,int ans=1){
    for(;b;b>>=1,a=(ll)a*a%p)
        if(b&1) ans=(ll)ans*a%p;
    return ans;
}

inline void rd(int &X){
    X=0;int w=0;char ch=0;
    while(!isdigit(ch))w|=ch=='-',ch=getchar();
    while( isdigit(ch))X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    X=w?-X:X;
}

int n,m;
char a[N],b[N];
int nxt[N],cnt[200];

void work(){
    while(cnt['1']>0) putchar('1'),cnt['1']--;
    while(cnt['0']>0) putchar('0'),cnt['0']--;
    exit(0);
}

signed main(){
    scanf("%s%s",a+1,b+1);
    n=strlen(a+1);m=strlen(b+1);
    if(n<m){puts(a+1);return 0;}
    for(int j=0,i=2;i<=m;i++){
        while(j and b[i]!=b[j+1]) j=nxt[j];
        j+=(b[i]==b[j+1]);nxt[i]=j;
    }
    for(int i=1;i<=n;i++)
        cnt[a[i]]++;
    for(int i=1;i<=m;i++)
        if(cnt[b[i]]>0)
            putchar(b[i]),cnt[b[i]]--;
        else work();
    int now=nxt[m]+1;
    while(1){
        for(int i=now;i<=m;i++)
            if(cnt[b[i]]>0)
                putchar(b[i]),cnt[b[i]]--;
            else work();
        now=nxt[m]+1;
    }
}