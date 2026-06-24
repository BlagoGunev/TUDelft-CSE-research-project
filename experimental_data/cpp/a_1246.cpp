#include<bits/stdc++.h>
#include<algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <map>
#include      <set>
using namespace std;
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((long long)(x).size())
#define mod Mod
#define LL ll
typedef vector<long long> VI;
typedef pair<long long,long long> PII;
 
typedef long long ll;
const int maxn = 2e5 + 5;
const ll Mod = 1e9 + 7;
ll powmod(ll a,ll b) {ll res=1;a%=Mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%Mod;a=a*a%Mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//head
	bool bo;
	int n,p,res,ii,tong[40];
 
int main()
{
#ifdef LOCAL
    freopen("D:\\123.txt","r",stdin);
#endif // LOCAL
    scanf("%d%d",&n,&p);
    res = 0;
    bo = false;
    rep(i,1,150){
        n -= p;
        if(n < i) break;
        int nn = n,num = 0,rres = 0;
        ll a2 = 1;
        while(a2 < nn){
            num ++;
            a2 *= 2;
        }
        int ma = num;
 
        while(num != -1){
            if(nn >= a2){
                nn -= a2;
                tong[num] = 1;
                rres ++;
            }
            else tong[num] = 0;
            a2 /= 2;
            num --;
        }
        if(rres <= i){
            res = i;
            bo = true;
            break;
        }
    }
    if(!bo) printf("-1\n");
    else printf("%d\n",res);
    return 0;
}