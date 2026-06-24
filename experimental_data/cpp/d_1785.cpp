#include<bits/stdc++.h>

#define rep(i,a,b) for(int i=(a);i<=(b);i++)

#define per(i,a,b) for(int i=(a);i>=(b);i--)

#define op(x) ((x&1)?x+1:x-1)

#define odd(x) (x&1)

#define even(x) (!odd(x))

#define lc(x) (x<<1)

#define rc(x) (lc(x)|1)

#define lowbit(x) (x&-x)

#define mp(x,y) make_pair(x,y)

typedef long long ll;

typedef unsigned long long ull;

typedef double db;

using namespace std;

const int MAXN=(1<<20)+1,MAXM=21,mod=998244353;

void add(int& x,int y){x=(x+y)%mod;}

void sub(int& x,int y){x=(x-y+mod)%mod;}

int fact[MAXN],ans[MAXN],pw[MAXM];

int n,dp[MAXN][MAXM];



int main(){

    cin>>n;

    rep(i,0,n)pw[i]=(1<<i);

    fact[0]=1;rep(i,1,(1<<n))fact[i]=1ll*fact[i-1]*i%mod;



    dp[0][0]=1;

    rep(i,0,(1<<n)-1)rep(j,0,n){

        int w=dp[i][j];

        add(dp[i+1][j],1ll*w*(pw[n]-pw[n-j]-i)%mod);

        if(j!=n){

            add(dp[i+1][j+1],1ll*w*(pw[n-j-1])%mod);

        }else{

            add(ans[i+1],1ll*w*fact[pw[n]-i-1]%mod);

        }

    }



    rep(i,1,(1<<n))cout<<1ll*ans[i]*pw[n]%mod<<"\n";

    return 0;

}