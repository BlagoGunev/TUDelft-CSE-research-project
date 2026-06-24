#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <cmath>
#include <stack>
using namespace std;
#define LL long long //__int64

template<class T> inline T mod(T n,T m) {return (n%m+m)%m;}
template<class T> inline void checkmin(T &a,const T b){if (b<a) a=b;}
template<class T> inline void checkmax(T &a,const T b){if (b>a) a=b;}
template<class T, class C> inline void checkmin(T &a, const T b, C c){if (c(b,a)) a = b;}
template<class T, class C> inline void checkmax(T &a, const T b, C c){if (c(a,b)) a = b;}
template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a, b), max(c, d));}
template<class T> inline T gcd(T a,T b) {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> T Abs(T x) {return x > 0 ? x : -x;}
int bigmod(LL B,LL P,LL M)
  { LL R=1; while(P>0)   {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (int)R;}
LL mulmod(LL a,LL b,LL c)
  { LL x = 0,y=a%c; while(b>0){ if(b%2 == 1){x=(x+y)%c;} y=(y*2)%c;b/= 2;}return x%c;}
template<class T> inline T pow(T a, LL b){
    T c(1); while (b){
        if (b&1) c *= a;
        a *= a, b >>= 1;
    }
    return c;
}
template <class T>
bool scan_d(T &ret){
    char c; int sgn; T bit=0.1;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&c!='.'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    if(c==' '||c=='\n'){ ret*=sgn; return 1; }
    while(c=getchar(),c>='0'&&c<='9') ret+=(c-'0')*bit,bit/=10;
    ret*=sgn;
    return 1;
}
template<class T> inline bool isprime(T n){if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
bool IsVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
bool isLetter(char c){return (c>='A' && c<='Z') || (c>='a' && c<='z');}
bool isDigit(char c){return c>='0' && c<='9';}

const int maxn = 200111;
int a[maxn];
void solve(){
    a[0] = a[1] = 1;
    a[2] = 0;
    for(int i = 2; i < maxn; i++){
        if(a[i]!=1){
            for(int j = i+i; j < maxn; j+=i){
                a[j] = 1;
            }
        }
    }
}

int check(int n){
    for(int i = n; i < 100111; i++){
        if(a[i] == 0) return i-n;
    }
}

int main(){
    solve();
    int mp[511][511];
    int n, m;
    scan_d(n);
    scan_d(m);
    bool f1 = true;
    for(int i = 0; i < n; i++){
        bool f2 = true;
        for(int j = 0; j < m; j++){
            scan_d(mp[i][j]);
            if(a[mp[i][j]]) f2 = false;
        }
        if(f2) f1 = false;
    }
    if(!f1){
        printf("%d\n", 0);
        return 0;
    }
    int minn = 1<<30;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < m; j++){
            if(mp[i][j]) cnt += check(mp[i][j]);
        }
        checkmin(minn, cnt);
    }
    for(int i = 0; i < m; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(mp[j][i]) cnt += check(mp[j][i]);
        }
        checkmin(minn, cnt);
    }
    printf("%d\n", minn);
    return 0;
}