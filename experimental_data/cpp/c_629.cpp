#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;
#define fi "input.txt"
#define fo "output.txt"
#define fileopen freopen(fi,"r",stdin);freopen(fo,"w",stdout)
#define FOR(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define FORD(i,l,r) for(int i=(int)(l);i>=(int)(r);i--)
#define xy pair<int,int>
#define int64 long long
#define X first
#define Y second
#define pb push_back
#define init(a,v) memset(a,v,sizeof(a))
#define Sz(s) (int)(s.size())
#define EL printf("\n")
#define digit(x) ('0'<=x&&x<='9')
#define forever while (true)
#define ld long double

const int OO = (int) 2e9;
const int MOD = (int) 1e9+7;
const double Pi = 3.141592653589793;
const int N = (int) 1e5+5;

int dp[2005][2005],n,m,len,mn=0,sz=0,res=0;
char s[N];

int main() {
    cin>>n>>m;
    cin>>(s+1);
    FOR(i,1,m) {
        if (s[i]=='(') sz++; else sz--;
        mn=min(sz,mn);
    }
    len=(n-m);
    dp[0][0]=1;
    FOR(i,1,len) FOR(j,0,i) {
        dp[i][j]=0;
        if (j>0) dp[i][j]+=dp[i-1][j-1];
        dp[i][j]+=dp[i-1][j+1];
        dp[i][j]%=MOD;
    }
    FOR(i,0,len) FOR(j,-mn,i) {
        if (j+sz<=len-i)
            res=(res+1LL*dp[i][j]*dp[len-i][j+sz])%MOD;
    }
    cout<<res;
}