#include<iostream>
#include<cstdio> 
#include<cmath>
#include<queue>
#include<vector>
#include<string.h>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<list>
#include<climits>
#include<bitset>
#include<random>
#include <ctime>
#include <cassert>
#include <complex>
#include <cstring>
#include <chrono>
using namespace std;
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fopen freopen("input.in", "r", stdin);freopen("output.in", "w", stdout);
#define left asfdasdasdfasdfsdfasfsdfasfdas1
#define tan asfdasdasdfasdfasfdfasfsdfasfdas
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef unsigned int un;
const int desll[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int mod=1e9+7;
const int maxn=2e4+7;
const int maxm=1e5+7;
const double eps=1e-4;
int m,n;
int ar[maxn];

char ch1[maxn],ch2[maxn];


ll func(int x,int num)
{
    if(x<0 || num<0)return 0;
    if(x==0 || num==0)return 1;
    if(num==1||x==1)return x*9+1;
    if(num==2 || x==2){
        return (ll)x*(x-1)*81/2+x*9+1;
    }
    ll ans=0;
    for(int i=1;i<=x-2;i++){
        ans += (ll)(x-i-1)*(x-i)*81*9/2;
    }
    ans += x*9;
    ans += (ll)x*(x-1)/2*81;
    //cout<<x<<" "<<num<<" "<<ans<<endl;
    return ans+1;
}
ll solve(char* ch)
{
    int len=strlen(ch);
    int ins=0;
    ll ans=0;
    for(int i=0;i<len;i++){
        if(ch[i]=='0')continue;
        ins++;
        if(ins==4){
            ans++;break;
        }
        ans += func(len-1-i,3-ins)*(ch[i]-'0'-1);
        //cout<<i<<" "<<ans<<endl;
        ans += func(len-1-i,3-ins+1);
        //cout<<i<<" "<<ans<<endl;
    }
    //cout<<ch<<" "<<ans<<endl;
    return ans;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--){
        scanf("%s",ch1);
        scanf("%s",ch2);
        int ins=0,len=strlen(ch2);
        for(int i=0;i<len;i++){
            if(ch2[i]!='0')ins++;
        }
        if(ins<=3)ins=1;
        else ins=0;
        printf("%I64d\n",solve(ch2)-solve(ch1)+ins);
    }
    return 0;
}