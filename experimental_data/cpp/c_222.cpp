#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstring>
#include <ctime>
#define mem(a,b) memset(a,b,sizeof(a));
#define INF 0x3f3f3f3f
#define lldINF 0x3f3f3f3f3f3f3f3fll
#define eps 1e-8
#define lld long long
#define sqr(x) ((x)*(x))
#define ab(x) (((x)>0) ? (x) : -(x))
#define PI 3.14159265358979323846
#define psl pair<sting,lld>
#define pll pair<lld,lld>
#define pii pair<int,int>
#define MP make_pair
#define er(i) (1ll<<(i))
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define rin freopen("in.txt","r",stdin)
#define pout freopen("out.txt","w",stdout)
#pragma comment(linker, "/STACK:102400000,102400000")
using std::bitset;
using namespace std;

#define maxup 10001000
#define maxn 101000

int adja[maxup],nexa[maxn],adjb[maxup],nexb[maxn];
int prim[maxup],pnum,flag[maxup];
int a[maxn],b[maxn],ansb[maxn],ansa[maxn];
int n,m;

void init(){
    int i,j,tem;
    pnum=0;
    mem(flag,0);
    for (i=2; i<=10000000; i++){
        if (flag[i]==0){
            prim[++pnum]=i;
            flag[i]=i;
        }
        for (j=1; j<=pnum && i*prim[j]<=10000000; j++){
            flag[i*prim[j]]=prim[j];
            if (i%prim[j]==0) break;
        }
    }
}

int cau(int x){
    int i,j,tem,tt,pa,pb,na,nb;
    while (adja[x]!=-1 && adjb[x]!=-1){
        pa=adja[x];
        a[pa]/=x;
        if (flag[a[pa]]!=x){
            adja[x]=nexa[pa];
            tem=flag[a[pa]];
            nexa[pa]=adja[tem];
            adja[tem]=pa;
        }
        pb=adjb[x];
        b[pb]/=x;
        if (flag[b[pb]]!=x){
            adjb[x]=nexb[pb];
            tem=flag[b[pb]];
            nexb[pb]=adjb[tem];
            adjb[tem]=pb;
        }
    }
    if (adja[x]!=-1) return 1;
    return 2;
}

void process(int x,int ss){
    int i,j,tem,pa,pb,na,nb;
    if (ss==1){
        while (adja[x]!=-1){
            pa=adja[x];
            ansa[pa]*=x;
            a[pa]/=x;
            if (flag[a[pa]]!=x){
                adja[x]=nexa[pa];
                tem=flag[a[pa]];
                nexa[pa]=adja[tem];
                adja[tem]=pa;
            }
        }
    }else {
        while (adjb[x]!=-1){
            pb=adjb[x];
            ansb[pb]*=x;
            b[pb]/=x;
            if (flag[b[pb]]!=x){
                adjb[x]=nexb[pb];
                tem=flag[b[pb]];
                nexb[pb]=adjb[tem];
                adjb[tem]=pb;
            }
        }
    }
}

int main(){
    int i,j,tem;
    init();
    while (scanf("%d%d",&n,&m)!=EOF){
        for (i=1; i<=n; i++){
            scanf("%d",&a[i]);
            ansa[i]=1;
        }
        for (i=1; i<=m; i++){
            scanf("%d",&b[i]);
            ansb[i]=1;
        }
        mem(adja,-1);
        for (i=1; i<=n; i++)
            if (a[i]>1){
                tem=flag[a[i]];
                nexa[i]=adja[tem];
                adja[tem]=i;
            }
        mem(adjb,-1);
        for (i=1; i<=m; i++)
            if (b[i]>1){
                tem=flag[b[i]];
                nexb[i]=adjb[tem];
                adjb[tem]=i;
            }
        for (i=1; i<=pnum; i++){
            tem=cau(prim[i]);
            process(prim[i],tem);
        }
        printf("%d %d\n",n,m);
        for (i=1; i<n; i++)
            printf("%d ",ansa[i]);
        printf("%d\n",ansa[n]);
        for (i=1; i<m; i++)
            printf("%d ",ansb[i]);
        printf("%d\n",ansb[m]);
    }
    return 0;
}