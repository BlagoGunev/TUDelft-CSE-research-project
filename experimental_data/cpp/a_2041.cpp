#include<cstdio>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;
const int Maxn = 5e5 + 5,Maxm = 1e6 + 5;
#define ll long long
#define ull unsigned long long
const ll INF= 1e18 + 5LL;
const ll Mod = 1e9 + 7;
int n,m,k,Cnt,q,Cnt0,Cnt1,Flag;
int x,y;
ll num[Maxn],num0[Maxn],head[Maxn],head1[Maxn],vis[Maxn],anc[Maxn][25],sum[Maxn],pre[Maxn],pre1[Maxn],suf[Maxn],P[Maxn],indeg[Maxn],indeg1[Maxn],ans1[Maxn],ans2[Maxn];
ll dp[Maxn][5];
ll tot;
char str[Maxn],str1[Maxn],ch,Map[5][Maxn];
map<int,int> mp;
int dirx[] = {1,-1,0,0},diry[] = {0,0,1,-1};

vector<vector<ll>> side(205,vector<ll>(205,INF)); 

struct Side{
    int e;
    int next;
}side1[Maxm];

ll fact(ll x){
    if(x <= 1)return 1;
    return x * fact(x-1);
}

ll C(ll m,ll n){
    if(m > n)return 0LL;
    return fact(n)/(fact(m))/fact(n-m);
}

// void add(int s,int e){
//     ++Cnt;
//     ++indeg[e];
//     side[Cnt].e = e;
//     side[Cnt].next = head[s];
//     head[s] = Cnt;
// }


ll max(ll x,ll y){
    return x > y ? x : y;
}

ll min(ll x,ll y){
    return x < y ? x : y;
}

ll gcd(ll x,ll y){
    return y ? gcd(y,x%y) : x;
}

ll ex_gcd(ll a,ll b,ll &x,ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll d;
    d = ex_gcd(b,a % b,y,x);
    y -= a / b * x;
    return d;
}

ll Reverse(ll p,ll q){
    ll x,y;
    ex_gcd(q,Mod,x,y);
    return (x * p % Mod + Mod) % Mod;
}

ll lcm(ll x,ll y){
    return x * y / gcd(x,y);
}

int count_bit(int x){
    int res = 0;
    while(x){
        ++res;
        x >>= 1;
    }
    return res;
}

ll quick_pow(ll x,ll y){
    ll res = 1,unit = x;
    while(y){
        if(y & 1)res = res * unit % Mod;
        unit = unit * unit % Mod;
        y >>= 1;
    }
    return res;
}

struct Node{
    ll dis;
    int idx;
    int operator < (const Node &w) const &{
        return dis > w.dis;
    }
}cur;

ll find(ll x){
    if(x <= 0)return 0;
    ll l = 0,r = x,mid;
    while(l <= r){
        mid = (l + r) >> 1;
        if(mid * (mid + 1) / 2 > x){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return r;
}

ll highbit(ll x){
    if(x == 0)return 0;
    ll res = 1;
    while(x > 1){
        x >>= 1;
        res <<= 1;
    }
    return res;
}

void swap(int &x,int &y){
    int tmp = x;
    x = y;
    y = tmp;
}




int main(){
    int i,j,k,v;
    // ll x0,y0,k;
    
    int tmp;
    int tmp1,tmp2;
    int _;
    // scanf("%d",&_);
    _ = 1;
    while(_--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%d\n",15-a-b-c-d);
    }
    scanf("%d %d ",&n,&k);
    return 0;
}