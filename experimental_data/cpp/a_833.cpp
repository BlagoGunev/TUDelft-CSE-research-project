#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#define fi first
#define se second
#define pb push_back

using namespace std;


typedef long long ll;
typedef unsigned int U;
typedef unsigned long long Ull;

const int N=100010,P=1e9+7;

inline char nc(){
  static char buf[100000],*p1=buf,*p2=buf;
  return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}

inline void rea(int &x){
  char c=nc(); x=0; int f=1;
  for(;c>'9'||c<'0';f=c=='-'?-f:f,c=nc());for(;c>='0'&&c<='9';x=x*10+f*(c-'0'),c=nc());
}

inline void rea(ll &x){
  char c=nc(); x=0; int f=1;
  for(;c>'9'||c<'0';f=c=='-'?-f:f,c=nc());for(;c>='0'&&c<='9';x=x*10+f*(c-'0'),c=nc());
}

inline void openf(){
  //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
}

int n,a,b;

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int main(){openf();
  rea(n);
  while(n--){
    rea(a); rea(b);
    if(a==1 && b==1){
      puts("Yes"); continue;
    }
    ll c=1LL*a*b,p=(ll)(pow(c,1.0/3.0)+1e-6);
    if(p*p*p==c && a%p==0 && b%p==0) puts("Yes");
    else puts("No");
  }
  return 0;
}