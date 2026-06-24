#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <deque>

using namespace std;

#define pr pair <int,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define rep(i,j,k) for(int i = (j);i <= (k);i ++)
#define repd(i,j,k,d) for(int i = (j);i <= (k);i += (d))
#define rrep(i,j,k) for(int i = (j);i >= (k);i --)
#define rrepd(i,j,k,d) for(int i = (j);i >= (k);i -= (d))
#define mo 1000000007
#define cl(x,d) memset(x,(d),sizeof(x))
#define repg(i,u) for(int i = h[u];~i;i = n1[i])
typedef long long ll;

void read(int &x){
    char ch = getchar();    int f = 1;  while((ch != '-') && (ch < '0' || ch > '9'))    ch = getchar();
    if(ch == '-')   f = -1, x = 0;  else     x = ch - 48;
    ch = getchar(); while(ch >= '0' && ch <= '9')   x = x * 10 + ch - 48, ch = getchar();   x *= f;
}
void read(ll &x){
    char ch = getchar();    int f = 1;  while((ch != '-') && (ch < '0' || ch > '9'))    ch = getchar();
    if(ch == '-')   f = -1, x = 0;  else     x = ch - 48;
    ch = getchar(); while(ch >= '0' && ch <= '9')   x = x * 10LL + ch - 48, ch = getchar(); x *= f;
}
void _print(const int &x){  if(x < 10)  putchar(48 + x);    else    _print(x / 10), _print(x % 10);}
void _print(const ll &x){   if(x < 10)  putchar(48 + x);    else    _print(x / 10), _print(x % 10);}
void print(const int &x){   if(x < 0)   putchar('-'), _print(-x);   else    _print(x);}
void print(const ll &x){    if(x < 0)   putchar('-'), _print(-x);   else    _print(x);}
void println(const int &x){ print(x);   putchar('\n');}
void println(const ll &x){  print(x);   putchar('\n');}
int check(ll n,ll k,ll d1,ll d2){
    if(n%3)return 0;
    ll t=n/3;
    ll tmp=k-d1-2*d2;
    ll a1,a2,a3;
    if(tmp>=0 && tmp%3==0){
        a1=tmp/3;
        a2=a1+d2;
        a3=a2+d1;
        if(a3<=t&&a3>=0&&a2<=t&&a2>=0&&a1>=0&&a1<=t)return 1;
    }
    tmp=k-d1-d2;
    if(tmp>=0&&tmp%3==0){
        a2=tmp/3;
        a1=a2+d2;
        a3=a2+d1;
        if(a3<=t&&a3>=0&&a2<=t&&a2>=0&&a1>=0&&a1<=t)return 1;
    }
    tmp=k-2*d1-d2;
    if(tmp>=0&&tmp%3==0){
        a3=tmp/3;
        a2=a3+d1;
        a1=a2+d2;
        if(a3<=t&&a3>=0&&a2<=t&&a2>=0&&a1>=0&&a1<=t)return 1;
    }
    tmp=k+d1+d2;
    if(tmp>=0 &&tmp%3==0){
        a2=tmp/3;
        a3=a2-d1;
        a1=a2-d2;
        if(a3<=t&&a3>=0&&a2<=t&&a2>=0&&a1>=0&&a1<=t)return 1;
    }
    return 0;
}

        
int main(){
    //freopen("data.in","r",stdin);
    
    int tc;
    read(tc);
    ll n,k,d1,d2;
    while(tc--){
        read(n);read(k);read(d1);read(d2);
        if(check(n,k,d1,d2))printf("yes\n");
        else printf("no\n");
    }
    return 0;
}