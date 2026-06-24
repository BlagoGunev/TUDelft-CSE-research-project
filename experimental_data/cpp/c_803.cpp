#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <vector>
#include <queue>
#include <time.h>
#define eps 1e-7
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define rep0(j,n) for(int j=0;j<n;++j)
#define rep1(j,n) for(int j=1;j<=n;++j)
#define pb push_back
#define mp make_pair
#define set0(n) memset(n,0,sizeof(n))
#define ll long long
#define ull unsigned long long
#define iter(i,v) for(edge *i=head[v];i;i=i->nxt)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define print_runtime printf("Running time:%.3lfs\n",double(clock())/1000.0)
#define TO(j) printf(#j": %d\n",j);
//#define OJ
using namespace std;
const int MAXINT = 100010;
const int MAXNODE = 100010;
const int MAXEDGE = 2*MAXNODE;
char BUF,*buf;
ll read(){
    char c=getchar();ll x=0;
    while(!isdigit(c)){c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x;
}
char get_ch(){
    char c=getchar();
    while(!isalpha(c)) c=getchar();
    return c;
}
//------------------- Head Files ----------------------//

ull n,k;
void get_input();
void work();
int check(ll gcd);
int main() {
    get_input();
    work();
    return 0;
}
void work(){
    if((k/100)*(k+1)>n) {printf("-1\n");return;}
    int ub=sqrt(n)+1;
    ll ans=0,sm=n;
    for(ll i=1;i<ub;i++){
        if(n%i==0){
            if(check(i)) ans=max(ans,i);
            if(check(n/i)) ans=max(ans,n/i);
        }
    }
    if(ans==0) {printf("-1\n");return;}
    n=n/ans;
    rep1(i,k-1) printf("%lld ",ans*i),sm-=ans*i;
    printf("%lld\n",sm);
}
void get_input(){
    n=read();k=read();
}
int check(ll gcd){
    if(n%gcd) return 0;
    if(k*(k+1)/2<=n/gcd) return 1; else return 0;
}