#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>
#define rep(i,m,n) for(i=m;i<=n;i++)
#define mod 1000000007
#define inf 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pi acos(-1.0)
#define pii pair<int,int>
#define sys system("pause")
const int maxn=2e5+10;
const int N=2e5+10;
using namespace std;
int id(int l,int r){return l+r|l!=r;}
ll gcd(ll p,ll q){return q==0?p:gcd(q,p%q);}
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p%mod;p=p*p%mod;q>>=1;}return f;}
int n,m,k,t,c1,c2;
char a[maxn];
ll gao(int x)
{
    int cnt=n/x,i,j=n%x;
    ll now=0;
    now+=j*(c1+(ll)c2*cnt*cnt);
    x-=j;
    now+=x*(c1+(ll)c2*(cnt-1)*(cnt-1));
    return now;
}
int main()
{
    int i,j;
    scanf("%d%d%d%s",&n,&c1,&c2,a);
    for(i=0;a[i];i++)if(a[i]=='1')m++;
    ll ret=1e18;
    rep(i,1,m)ret=min(ret,gao(i));
    printf("%lld\n",ret);
    return 0;
}