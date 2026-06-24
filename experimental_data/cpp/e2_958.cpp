#include <bits/stdc++.h>
#define rap(i,s,n) for(int i=s;i<=n;i++)
#define drap(i,s,n) for(int i=s;i>=n;i--)
#define N 600000
#define ll long long
#define inf 0x3f3f3f3f
#define M(s,x) memset(s,x,sizeof s);
using namespace std;
char xB[1<<15],*xS=xB,*xTT=xB;
#define getc() (xS==xTT&&(xTT=(xS=xB)+fread(xB,1,1<<15,stdin),xS==xTT)?0:*xS++)
#define isd(c) ((c>='0'&&c<='9')||(c=='-'))
template<typename T>
inline bool rd(T & xa){
    char xchh; T f=1; while(xchh=getc(),(!isd(xchh))&&(xchh!=0));
    if(xchh==0) return 0; if(xchh=='-') f=-1,xchh=getc(); xa=xchh-'0';
    while(xchh=getc(),isd(xchh)) xa=xa*10+xchh-'0'; xa*=f; return 1;
}
int k,n,a[N],pre[N],nxt[N];
ll ans;
bool vis[N];
struct node{
    ll val; int k; node(ll _,int __){val=_,k=__; return;}
    bool operator < (const node& b) const {return val>b.val;}
};
priority_queue<node>q;
void del(int x){pre[nxt[x]]=pre[x]; nxt[pre[x]]=nxt[x]; vis[x]=1;}
int main(){
	//freopen("a.in","r",stdin);
    rd(k); rd(n); rap(i,1,n) rd(a[i]); sort(a+1,a+n+1); n--;
    rap(i,1,n){a[i]=a[i+1]-a[i]; q.push(node(a[i],i)); pre[i]=i-1,nxt[i]=i+1;} a[0]=a[n+1]=inf;
    while(k--){
        while(vis[q.top().k]) q.pop(); int x=q.top().k; ans+=a[x]; q.pop();
        a[x]=a[pre[x]]+a[nxt[x]]-a[x]; del(pre[x]); del(nxt[x]); q.push(node(a[x],x));
    }
    printf("%I64d\n",ans);
    return 0;
}