#include <bits/stdc++.h>
#define f first
#define s second
#define ent '\n'
#define int long long

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast,unroll-loops,fast-math,O3")

//typedef long double ld;
typedef long long ll;
using namespace std;

struct node{double x,y;};
//double len(node a,node b)
//{return sqrt((a.x-b.x)*(a.x-b.y)+(a.y-b.y)*(a.x-b.y));}

struct seg{
    int mx1=0,mx2=0,ans=0;
};

const string out[2]={"NO\n","YES\n"};
const ll dx[]={0,0,1,-1,-1,1,1,-1};
const ll dy[]={1,-1,0,0,-1,1,-1,1};
//const int mod=998244353;
//const int md=1e9+7;
const int mx=3e5+12;
const int tst=1e5;
const bool T=1;

int mod, md;
vector<int> a[mx];
int pp[mx];
int pw[mx];
int n, m, k;

bool prime(int x){
    for(int i=2;i*i<=x;i++){
        if(x % i == 0){
            return 1;
        }
    }
    return 0;
}

void Press_Fn_with_F11() {
    map<pair<int, int>, int> cnt;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        a[i] = {0};
        for(int j=1;j<=m;j++){
            char x;
            cin >> x;
            a[i].push_back({x - '0'});
        }
    }
    pw[0] = pp[0] =  1;
    int mx = 0;
    pair<int, int> val = {0, 0};
    for(int i=1;i<=n;i++){
        pw[i] = pw[i-1] * 7 % mod;
        pp[i] = pp[i-1] * 17 % mod;
    }
    for(int j=1;j<=m;j++){
        int hash = 0, hash2 = 0;
        for(int i=1;i<=n;i++){
            hash += pw[i-1] * a[i][j];
            hash %= mod;
            hash2 += pp[i-1] * a[i][j];
            hash2 %= md;
        }
        for(int i=1;i<=n;i++){
            int t = hash - pw[i-1] * a[i][j], tt = hash2 - pp[i-1] * a[i][j];
            t += (1 - a[i][j]) * pw[i-1];
            tt += (1 - a[i][j]) * pp[i-1];
            t %= mod, tt %= md;
            if(t < 0){
                t += mod;
            }
            if(tt < 0){
                tt += md;
            }
            cnt[{t, tt}]++;
            if(cnt[{t, tt}] > mx){
                mx = cnt[{t, tt}];
                val = {t, tt};
            }
        }
    }
    for(int j=1;j<=m;j++){
        int hash = 0, hash2 = 0;
        for(int i=1;i<=n;i++){
            hash += pw[i-1] * a[i][j];
            hash %= mod;
            hash2 += pp[i-1] * a[i][j];
            hash2 %= md;
        }
        for(int i=1;i<=n;i++){
            int t = hash - pw[i-1] * a[i][j], tt = hash2 - pp[i-1] * a[i][j];
            t += (1 - a[i][j]) * pw[i-1];
            tt += (1 - a[i][j]) * pp[i-1];
            t %= mod, tt %= md;
            if(t < 0){
                t += mod;
            }
            if(tt < 0){
                tt += md;
            }
            cnt[{t, tt}]++;
            if(pair<int ,int>{t, tt} == val) {
                cout << mx << ent;
                for (int v = 1; v <= n; v++) {
                    int x = a[v][j];
                    if(v == i) x ^= 1;
                    cout << x;
                }
                cout << ent;
                return;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    int d = 5e8;
    mod = d + ((rand() * 1ll * rand() + rand()) % d);
    md = d + ((rand() * 1ll * rand() + rand()) % d);
    while(prime(mod)){
        mod++;
    }
    while(prime(md)){
        md++;
    }
    if(T)cin>>t;
    for(int i=1;i<=t;i++) {
//    	cout<<"Case "<<i<<": ";
        Press_Fn_with_F11();
    }
}