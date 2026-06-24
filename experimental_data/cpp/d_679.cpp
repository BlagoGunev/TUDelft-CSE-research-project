#pragma comment(linker, "/STACK:102400000,102400000")

#include <iostream>

#include <algorithm>

#include <stdio.h>

#include <string.h>

#include <vector>

#include <map>

#include <assert.h>

#include <cmath>

#include <queue>

#include <set>

#include <bitset>

using namespace std;

#define vi vector<int>

#define pii pair<int,int>

#define pb push_back

#define mp make_pair

#define all(x) x.begin(),x.end()

#define SZ(x) (int)(x.size())

#define rep(i,a,b) for(int i=a;i<b;i++)

#define per(i,a,b) for(int i=b-1;i>=a;i--)

#define inf 1000000007

#define mod 1000000007

#define x first

#define y second

#define pi acos(-1.0)

#define DBG(x) cerr<<(#x)<<"="<<x<<"\n";

//#define dprintf(...) 

#define hash _hash

//#define dprintf(...) fprintf(outFile,__VA_ARGS__)

 

#define FOREACH(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)

#define ull unsigned long long

#define ll long long

#define N 405





template <class T,class U>inline void Max(T &a,U b){if(a<b)a=b;}

template <class T,class U>inline void Min(T &a,U b){if(a>b)a=b;}

 

//FILE* outFile;

 

inline void add(int &a,int b){a+=b;while(a>=mod)a-=mod;}





int pow(int a,int b){

    int ans=1;

    while(b){

        if(b&1)ans=ans*(ll)a%mod;

        a=(ll)a*a%mod;b>>=1;

    }

    return ans;

}



int n,d[N][N],now,vis[N];

double p[N],dp[N];

vi g[N];

int main(){

    //freopen("A.in","r",stdin);

    //freopen("A.out","w",stdout);

    //freopen("1.txt","w",stdout);

    int j,k,i,ca=0,m=0;

    scanf("%d%d",&n,&m);

    rep(i,0,n)

        rep(j,0,n){

            d[i][j]=i==j?0:n+1;

        }

    rep(i,0,m){

        scanf("%d%d",&j,&k),j--,k--;

        g[j].pb(k);

        g[k].pb(j);

        d[j][k]=d[k][j]=1;

    }

    rep(k,0,n)

        rep(i,0,n)

            rep(j,0,n)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

    double ans=0,P=1./n;

    vi v;

    rep(i,0,n){

        double t=0;

        rep(j,0,n){

            v.clear();now++;m=0;

            rep(k,0,n)if(d[i][k]==j){

                m++;

                FOREACH(it,g[k]){

                    int x=*it;

                    if(vis[x]!=now){vis[x]=now,p[x]=0;v.pb(x);}

                    p[x]+=P/SZ(g[k]);

                }

            }

            if(m==0)continue;

            double s=0,ss=0;

            rep(k,0,n){

                s=0;

                FOREACH(it,v){

                    Max(dp[d[k][*it]],p[*it]);

                }

                FOREACH(it,v){

                    s+=dp[d[k][*it]];

                    dp[d[k][*it]]=0;

                }

                Max(ss,s);

            }

            t+=max(P,ss);

        }

        Max(ans,t);

    }

    printf("%.9lf\n",ans);

    //cerr<<1.*clock()/CLOCKS_PER_SEC<<"s\n";

    return 0;

}