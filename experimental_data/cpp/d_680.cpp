#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using  namespace  std;



#define ff first

#define ss second

#define pb push_back

#define ll int64_t

#define ull unsigned long long

#define mod 1000000007

#define mst(ss,b) memset(ss,b,sizeof(ss));

template<class T> T sqr(T x){ return x * x * x; }



const int inf=0x3f3f3f3f;

const int N=3e5+10; 



ll m;

pair<int, ll> P;



void dfs(ll x, int num, ll sum){

    if(!x){ P=max(P, {num, sum}); return ;}//所选的X能到0时更新一下答案

    ll t=1;

    while(sqr(t+1)<=x)t++;

    dfs(x-sqr(t), num+1, sum+sqr(t));

    if(x>0)dfs(sqr(t)-1-sqr(t-1), num+1, sum+sqr(t-1));

}



int  main(){

    scanf("%lld", &m), dfs(m, 0, 0);

    printf("%d %lld\n", P.ff, P.ss);

    return 0;

}