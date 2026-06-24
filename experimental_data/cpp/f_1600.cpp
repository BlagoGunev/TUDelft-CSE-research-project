#include <bits/stdc++.h>

using namespace std;



#define oo 1e18

#define fi first

#define se second

#define sp(iiii) setprecision(iiii)

#define IO ios_base::sync_with_stdio(false); cin.tie(0)

#define ms(aaaa,xxxx) memset(aaaa,xxxx,sizeof(aaaa))

#define cntbit(xxxx) __builtin_popcount(xxxx)

#define getbit(xxxx,aaaa) (((xxxx)>>(aaaa-1))&1)



typedef long double ld;

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int,int> pii;

typedef pair<pair<int,int>,int> piii;

typedef pair<pair<int,int>,pair<int,int>> piiii;

typedef pair<long long,long long> pll;

typedef pair<pair<long long,long long>,long long> plll;

typedef pair<pair<long long,long long>,pair<long long,long long>> pllll;

typedef pair<pair<long long,long long>,bool> pllb;

typedef pair<long double,long double> pld;

typedef pair<pair<long double,long double>,long double> plld;

typedef pair<long double,long long> pdl;



const ll base=361;

const int mod=1e9+7;

const ll mod2=1e9;

const ld eps=1e-8;

const ld eps2=1e-8;

const ll maxn=1e6;

const ll maxsize=6e5+29;

const ld pi=acos(-1);

const ll lim=2;

const ld delta=1e-7;

const int dx[5]={0,1,1,1,2};

const int dy[5]={1,0,1,2,1};



const int dxkn[8]={1,1,2,2,-1,-1,-2,-2};

const int dykn[8]={2,-2,1,-1,2,-2,1,-1};

const int dxki[8]={1,1,1,0,0,-1,-1,-1};

const int dyki[8]={1,0,-1,1,-1,1,0,-1};



int n,m,i,j,l,h,k,u,v;

bool ok[209][209];



bool check(vector<int> x) {

    bool ck1,ck2;

    ck1=true;

    ck2=true;

    for (int ii=0;ii<x.size();ii++) {

        for (int ij=ii+1;ij<x.size();ij++) {

            if (ok[x[ii]][x[ij]]) {

                ck1=false;

            }

            else {

                ck2=false;

            }

        }

    }

    return ck1|ck2;

}



int main() {

    IO;

    #ifndef ONLINE_JUDGE

        freopen("test.inp", "r", stdin);

        freopen("test.out", "w", stdout);

    #else

    #endif

    cin>>n>>m;

    for (i=1;i<=m;i++) {

        cin>>u>>v;

        if (u>60||v>60) {

            continue;

        }

        ok[u][v]=true;

        ok[v][u]=true;

    }

    n=min(60,n);

    for (i=1;i<=n;i++) {

        for (j=i+1;j<=n;j++) {

            for (l=j+1;l<=n;l++) {

                for (h=l+1;h<=n;h++) {

                    for (k=h+1;k<=n;k++) {

                        if (check({i,j,l,h,k})) {

                            cout<<i<<' '<<j<<' '<<l<<' '<<h<<' '<<k<<'\n';

                            return 0;

                        }

                    }

                }

            }

        }

    }

    cout<<-1;

}