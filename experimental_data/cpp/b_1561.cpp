#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mst(a,b) memset((a),(b),sizeof(a))
#define rush() int TT;scanf("%d",&TT);for(int TTT=1;TTT<=TT;TTT++)
#define fastio() ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define forrr(i,x,y) for(int i=x;i<=y;++i)
#define rofff(i,x,y) for(int i=x;i>=y;--i)
#define forr(i,x,y) for(int i=x;i<y;++i)
#define roff(i,x,y) for(int i=x;i>y;--i)
#define lowbit(x) (x&-x)
#define fin freopen("in.txt","r",stdin)
#define fout freopen("out.txt","w",stdout)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sf scanf
#define pf printf
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef pair<string,int> psi;
const ldb pi = acos((ldb)-1);
int in(int &a,int &b,int &c,int &d) {
    return scanf("%d%d%d%d",&a,&b,&c,&d);
}
int in(int &a,int &b,int &c) {
    return scanf("%d%d%d",&a,&b,&c);
}
int in(int &a,int &b) {
    return scanf("%d%d",&a,&b);
}
int in(ll &a,ll &b) {
    return scanf("%lld%lld",&a,&b);
}
int in(ll &a,ll &b,ll &c,ll &d) {
    return scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
}
int in(ll &a,ll &b,ll &c) {
    return scanf("%lld%lld%lld",&a,&b,&c);
}
int in(ll &a) {
    return scanf("%lld",&a);
}
int in(int &a) {
    return scanf("%d",&a);
}
int in(char *s) {
    return scanf("%s",s);
}
int in(char &c) {
    return scanf("%c",&c);
}
void out(int a,bool ln) {
    printf("%d%c",a," \n"[ln]);
}
void out(ll a,bool ln) {
    printf("%lld%c",a," \n"[ln]);
}
void out(db a,int digit,bool ln) {
    printf("%.*f%c",digit,a," \n"[ln]);
}
ll gcd(ll a, ll b) {
    return b?gcd(b,a%b):a;
}
ll lcm(ll a, ll b) {
    return a/gcd(a,b)*b;
}
const int inf = 0x3f3f3f3f;
const db eps = 1e-8;
const int maxn = 2e5+10;
const int maxm = 1e6+5;
const ll mod = 1e9+7;
int a,b;
bool vis[maxn];

int main() {
    rush() {
        in(a,b);
        forrr(i,0,a+b){
            vis[i]=0;
        }
        int x=(a+b+1)/2,y=a+b-x,ans=0;
        forrr(i,0,min(a,y)){
            int j = x+i-a;
            if(j>=0&&j<=b&&j<=x){
                if(!vis[i+j])
                    ans++;
                vis[i+j]=1;
            }
        }
        forrr(i,0,min(a,x)){
            int j = y+i-a;
            if(j>=0&&j<=b&&j<=y){
                if(!vis[i+j])
                    ans++;
                vis[i+j]=1;
            }
        }
        out(ans,1);
        forrr(i,0,a+b){
            if(vis[i]){
                ans--;
                out(i,ans?0:1);
            }
        }
    }
}