#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define ll long long
#define fo(i,l,r) for(int i = l;i <= r;i++)
#define fd(i,l,r) for(int i = r;i >= l;i--)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int maxn = 100050;
const ll inf = 987654321234500LL;
const ll mod = 1e9+7;
ll read() {
    ll x=0,f=1;
    char ch=getchar();
    while(!(ch>='0'&&ch<='9')) {
        if(ch=='-')f=-1;
        ch=getchar();
    };
    while(ch>='0'&&ch<='9') {
        x=x*10+(ch-'0');
        ch=getchar();
    };
    return x*f;
}
ll n,m,k;
ll p[maxn];
ll lp,rp;
int main() {
    n=read();
    m=read();
    k=read();
    fo(i,1,m){
        p[i]=read();
    }
    lp = 1;
    rp = k;
    ll hasp=0,nowhp;
    ll ans = 0;
    ll pos = 1;
    while(pos <= m){
        nowhp=0;
        while(pos <= m && p[pos]-hasp<=rp){
            nowhp++;
            pos++;
        }
        if(nowhp)ans++;
        hasp += nowhp;
        if(rp < p[pos]-hasp){
            ll tmp = (p[pos]-hasp-rp);
            tmp = (tmp-1)/k + 1;
            tmp *= k;
            lp += tmp;
            rp += tmp;
        }
    }
    cout<<ans;
    return 0;
}