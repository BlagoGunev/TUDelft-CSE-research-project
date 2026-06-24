#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstdlib>
#include<stack>
#include<ctime>
#define forin(i,a,n) for(int i=a;i<=n;i++)
#define forni(i,n,a) for(int i=n;i>=a;i--)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
const double eps=1e-7;
const int N=2e5+7 ,M=1e7+7 , INF=0x3f3f3f3f,mod=1e9+7;
inline ll read() {ll x=0,f=1;char c=getchar();while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
while(c>='0'&&c<='9') {x=(ll)x*10+c-'0';c=getchar();} return x*f;}
void stin() {freopen("in_put.txt","r",stdin);freopen("my_out_put.txt","w",stdout);}

template<typename T> T gcd(T a,T b) {return b==0?a:gcd(b,a%b);}
template<typename T> T lcm(T a,T b) {return a*b/gcd(a,b);}

int T;
int n,m,k;
int w[N];

void solve() {  
    n=read(),m=read();
    
    for(int i=1;i<=n;i++) w[i]=read();
    
    int res=0,idx=1;
    for(int i=2;i<m;i++) if(w[i]>w[i-1]&&w[i]>w[i+1]) res++;
    int ans=res;
    for(int i=m+1;i<=n;i++) {
        if(w[i-m+1]>w[i-m]&&w[i-m+1]>w[i-m+2]) res--;
        if(w[i-1]>w[i]&&w[i-1]>w[i-2]) res++;
        if(res>ans) {
            ans=res;
            idx=i-m+1;
        }
    }
    
    printf("%d %d\n",ans+1,idx);
}

int main() {
    // init();
    // stin();
    
    scanf("%d",&T);
    // T=1; 
    while(T--) solve();
    
    return 0;   
}