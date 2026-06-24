#include <bits/stdc++.h>
#include<string.h>
using namespace std;

#define din(var) scanf("%d",&var)
#define dout(var) printf("%d\n",var)
#define dinll(var) scanf("%lld",&var)
#define doutll(var) printf("%lld\n",var)
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define aLL(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mem(a, b) memset(a, b, sizeof(a))
typedef vector<int> VI;
typedef long double LD;
typedef long long LL;
typedef vector<long long> VIL;
typedef pair<int, int> PII;

inline LL Mmax(LL x, LL y){return x > y ? x : y;}
inline LL Mmin(LL x, LL y){return x < y ? x : y;}
inline int Mmax(int x, int y){return x > y ? x : y;}
inline int Mmin(int x, int y){return x < y ? x : y;}
inline double Mmax(double x, double y){
    if(x-y >= 1e-6) return x;
    return y;
}

template <class T>
inline bool scan_d(T &ret)
{
    char c;
    int sgn;
    if(c=getchar(),c==EOF) return 0; //EOF
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}

const double PI = acos(-1.0);
const double eps = 1e-5;
const LL mod = 1e9+9;
const int N = 100010;

void extgcd(LL a,LL b,LL& d,LL& x,LL& y){
    if(!b){ d=a; x=1; y=0;}
    else{ extgcd(b,a%b,d,y,x); y-=x*(a/b); }
}

LL inverse(LL a){
    LL n = mod;
    LL d,x,y;
    extgcd(a,n,d,x,y);
    //if(d!=1) printf("??");
    return d==1?(x+n)%n:-1;
}

LL pow_mod(LL x,LL y){
    LL res=1;
    while(y){
        if(y&1) res=(res*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return res;
}

LL dengbi(LL a1, LL q, LL len){
    LL x = inverse(q - 1);
    x = x * (pow_mod(q, len) - 1) % mod;
    x = x * a1 % mod;
    return x;
}

char s[N];
int main()
{
    LL n,a,b,k;
    scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&k);
    scanf("%s",s);
    LL tmp=inverse(a)*b%mod,ans,cheng=1LL,da=0,yu;
//        printf("%I64d\n",tmp);

    for(int i=0; i<k; i++){
        if(i==0) ans = pow_mod(a, n);
        //printf("%I64d\n",ans);
        if(s[i]=='-') da = ((da-ans)%mod+mod)%mod;
        else da = (da+ans)%mod;
        ans = (ans*tmp)%mod;
        cheng = (cheng*tmp)%mod;
        if(i+1==(n+1)%k) yu = da;
    }

    if((n+1)/k==0) printf("%I64d\n",yu);
    else{
//        ans = da;
//        for(int i=1; i<(n+1)/k; i++){
//            yu = yu*cheng%mod;
//            da = da*cheng%mod;
//            ans = (ans+da)%mod;
//        }
        if(cheng == 1){
            ans = da * ((n+1)/k) % mod;
        }
        else ans = dengbi(da, cheng, (n+1)/k);
        yu = pow_mod(cheng, (n+1)/k-1) * yu % mod;

        if((n+1)%k==0) yu = 0;
        else yu = yu * cheng % mod;

        printf("%I64d\n",(ans+yu)%mod);
    }
    return 0;
}
/*
4 1 5 2
--
101 97 23 3
-++-
993151195
125 2335 2 4
--++
12805340

*/
//#include <bits/stdc++.h>
//#include<string.h>
//using namespace std;
//
//#define din(var) scanf("%d",&var)
//#define dout(var) printf("%d\n",var)
//#define dinll(var) scanf("%lld",&var)
//#define doutll(var) printf("%lld\n",var)
//#define rep(i,a,n) for (int i=a;i<n;i++)
//#define per(i,a,n) for (int i=n-1;i>=a;i--)
//#define pb push_back
//#define mp make_pair
//#define aLL(x) (x).begin(),(x).end()
//#define fi first
//#define se second
//#define mem(a, b) memset(a, b, sizeof(a))
//typedef vector<int> VI;
//typedef long double LD;
//typedef long long LL;
//typedef vector<long long> VIL;
//typedef pair<int, int> PII;
//
//inline LL Mmax(LL x, LL y){return x > y ? x : y;}
//inline LL Mmin(LL x, LL y){return x < y ? x : y;}
//inline int Mmax(int x, int y){return x > y ? x : y;}
//inline int Mmin(int x, int y){return x < y ? x : y;}
//inline double Mmax(double x, double y){
//    if(x-y >= 1e-6) return x;
//    return y;
//}
//
//template <class T>
//inline bool scan_d(T &ret)
//{
//    char c;
//    int sgn;
//    if(c=getchar(),c==EOF) return 0; //EOF
//    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
//    sgn=(c=='-')?-1:1;
//    ret=(c=='-')?0:(c-'0');
//    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
//    ret*=sgn;
//    return 1;
//}
//
//const double PI = acos(-1.0);
//const double eps = 1e-5;
//const int INF=1e18;
//const LL mod = 1e9+9;
//const int N = 100010;
//
//void extgcd(LL a,LL b,LL& d,LL& x,LL& y){
//    if(!b){ d=a; x=1; y=0;}
//    else{ extgcd(b,a%b,d,y,x); y-=x*(a/b); }
//}
//
//LL inverse(LL a){
//    LL n = mod;
//    LL d,x,y;
//    extgcd(a,n,d,x,y);
//    //if(d!=1) printf("??");
//    return d==1?(x+n)%n:-1;
//}
//
//LL pow_mod(LL x,LL y){
//    LL res=1;
//    while(y){
//        if(y&1) res=(res*x)%mod;
//        x=(x*x)%mod;
//        y>>=1;
//    }
//    return res;
//}
//
//char s[N];
//int main()
//{
//    LL n,a,b;
//    int k;
//    scanf("%I64d%I64d%I64d%d",&n,&a,&b,&k);
//    scanf("%s",s);
//    LL tmp=inverse(a)*b%mod,ans,cheng=1LL,da=0,yu;
////        printf("%I64d\n",tmp);
//
//    for(int i=0; i<k; i++){
//        if(i==0) ans = pow_mod(a,n);
//        //printf("%I64d\n",ans);
//        if(s[i]=='-') da = ((da-ans)%mod+mod)%mod;
//        else da = (da+ans)%mod;
//        ans = (ans*tmp)%mod;
//        cheng = (cheng*tmp)%mod;
//        if(i+1==(n+1)%k) yu = da;
//    }
//
//    if((n+1)/k==0) printf("%I64d\n",yu);
//    else{
//        ans = da;
//        for(int i=1; i<(n+1)/k; i++){
//            yu = yu*cheng%mod;
//            da = da*cheng%mod;
//            ans = (ans+da)%mod;
//        }
//
//        if((n+1)%k==0) yu=0;
//        else yu = yu*cheng%mod;
//        printf("%I64d\n",(ans+yu)%mod);
//    }
//    return 0;
//}