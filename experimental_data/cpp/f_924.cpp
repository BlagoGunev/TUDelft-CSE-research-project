#include <bits/stdc++.h>
# include <iostream>
# include <sstream>
# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <string>
# include <cstring>
# include <cmath>
# include <stack>
# include <queue>
# include <vector>
# include <list>
# include <map>
# include <set>
# include <deque>
# include <iterator>
# include <functional>
# include <bitset>
# include <climits>
# include <ctime>
# include <unordered_map>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define odd(x) ((x)&1)
#define sqr(x) ((x)*(x))
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define all(x) (x).begin(),(x).end()
#define mem(a,x) memset(a,x,sizeof(a))
#define rep(i,a,b) for (int i=(a); i<=(b); ++i)
#define per(i,a,b) for (int i=(a); i>=(b); --i)
#define rep_it(it,x) for (__typeof((x).begin()) it=(x).begin(); it!=(x).end(); it++)
#define ____ puts("\n_______________\n\n") 
#define debug(x) ____; cout<< #x << " => " << (x) << endl
#define debug_pair(x) cout<<"\n{ "<<(x).fir<<" , "<<(x).sec<<" }\n"
#define debug_arr(x,n) ____; cout<<#x<<":\n"; rep(i,0,n) cout<<#x<<"["<<(i)<<"] => "<<x[i]<<endl
#define debug_arr2(x,n,m) ____; cout<<#x<<":\n"; rep(i,0,n) rep(j,0,m) cout<<#x<<"["<<(i)<<"]["<<(j)<<"]= "<<x[i][j]<<((j==m)?"\n\n":"    ")
#define debug_set(x) ____; cout<<#x<<": \n"; rep_it(it,x) cout<<(*it)<<" "; cout<<endl
#define debug_map(x) ____; cout<<#x<<": \n"; rep_it(it,x) debug_pair(*it)
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int oo = /*2 * 1000 * 1000 * 1000*/0x3f3f3f3f;
const ll ooo=9223372036854775807ll; 
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N=100005; 
const double PI=acos(-1.0);
const double eps=1e-9;
int o(int x) { return x%_p; }
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a / gcd(a, b)*b; }

void file_put() {
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
}

typedef bitset<165> BT; BT B[N]; unordered_map <BT,int> M;
int T,tot=0,no[N],k,go[N][10],d[20],top; ll l,r,s[10][20][N],ans;

int I(const BT &x) { if (M.count(x)==0) B[M[x]=++tot]=x; return M[x]; }

void init() {
 I(BT(1));
 rep(i,1,tot) rep(j,0,9) {
  BT t=B[i]<<j | B[i]>>j;
  rep(k,0,j-1) if (B[i][k]) t[j-k]=1;
  go[i][j]=I(t);
 }
 rep(i,1,tot) rep(k,0,162) { if (B[i][k]) { no[i]=k; break; } }
 rep(i,1,tot) rep(k,0,9) s[k][0][i]=(k>=no[i]);
 rep(k,0,9) rep(i,1,19) rep(j,1,tot) rep(c,0,9) s[k][i][j]+=s[k][i-1][go[j][c]];
}

ll Query(ll x,int k) {
 for (top=0; x; x/=10) d[++top]=x%10; ans=0;
 for (int i=top,now=1; i; now=go[now][d[i--]]) 
  rep(j,0,d[i]-1) ans+=s[k][i-1][go[now][j]];
 return ans;
}

int main() {
    //file_put();
    
    scanf("%d",&T),init();
    while (T--) {
     scanf("%lld%lld%d",&l,&r,&k);
     printf("%lld\n",Query(r+1,k)-Query(l,k));
 }
 
    return 0;
}