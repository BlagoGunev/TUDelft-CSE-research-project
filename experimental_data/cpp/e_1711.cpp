#include<iostream>

#include<algorithm>

#include<string.h>

using namespace std;

// #define debug(x) cout<<"[debug]"#x<<"="<<x<<endl

typedef pair<int,int> pii;

typedef long long ll;

const double eps=1e-8;

const int INF=0x3f3f3f3f;



#ifndef ONLINE_JUDGE

#define debug(...)

#include<debug>

#else

#define debug(...)

#endif

template<typename T=long long,T mod=998244353> struct Modint {

    T v;

    T modulo(T x) { return (x%mod+mod)%mod; }

    T qpow(T a,T b) {

        T res=1;

        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }

        return res;

    }

    T inv() { return qpow(v,mod-2); }



    Modint &operator+=(const Modint &x) { v=(v+x.v)%mod; return *this; }

    Modint &operator-=(const Modint &x) { v=modulo(v-x.v); return *this; }

    Modint &operator*=(const Modint &x) { v=v*x.v%mod; return *this; }

    Modint &operator/=(const Modint &x) { v=v*x.inv()%mod; return *this; }



    friend Modint operator+(Modint l,const Modint &r) { return l+=r; }

    friend Modint operator-(Modint l,const Modint &r) { return l-=r; }

    friend Modint operator*(Modint l,const Modint &r) { return l*=r; }

    friend Modint operator/(Modint l,const Modint &r) { return l/=r; }



    Modint operator- () { return *this*-1; }

    Modint operator++() { return *this+=1; }

    Modint operator--() { return *this-=1; }

    Modint &operator++(int) { auto res=*this; *this+=1; return res; }

    Modint &operator--(int) { auto res=*this; *this-=1; return res; }



    bool operator< (const Modint&x) { return v< x.v; }

    bool operator> (const Modint&x) { return v> x.v; }

    bool operator<=(const Modint&x) { return v<=x.v; }

    bool operator>=(const Modint&x) { return v>=x.v; }

    bool operator==(const Modint&x) { return v==x.v; }

    bool operator!=(const Modint&x) { return v!=x.v; }



    friend istream &operator>>(istream &is,Modint &x) { return is>>x.v; }

    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }



    Modint(T x=0): v(modulo(x)) {}

};

using Mod=Modint<>;

const int N=200005;

char s[N];

Mod dp[N][2][2][2];

int main()

{

    int n;

    scanf("%s",s+1);

    n=strlen(s+1);

    dp[0][0][0][0]=1;

    for(int i=1;i<=n;i++)

    {

        if(s[i]=='0')

        {

            dp[i][0][0][0]=dp[i-1][0][0][0];

            dp[i][1][0][0]=2*dp[i-1][1][0][0];//可以选100/000

            dp[i][0][1][0]=2*dp[i-1][0][1][0];//可以选010/000

            // dp[i][0][0][1]=(dp[i][0][0][1]+dp[i-1][0][0][1])%mod;//可以选000



            dp[i][1][1][0]=3*dp[i-1][1][1][0];//可以选000/100/010

            dp[i][1][0][1]=3*dp[i-1][1][0][1];//可以选000/100/101

            dp[i][0][1][1]=3*dp[i-1][0][1][1];//可以选000/010/011



            dp[i][1][1][1]=6*dp[i-1][1][1][1];//可以选000/100/010/101/011/111

        }

        else//n当前位为1

        {

            dp[i][0][0][0]=dp[i-1][0][0][0];//只能取111

            dp[i][1][0][0]=dp[i-1][0][0][0]+2*dp[i-1][1][0][0];

            //                     011           111/011

            dp[i][0][1][0]=dp[i-1][0][0][0]+2*dp[i-1][0][1][0];

            //                     101           111/101

            //dp[i][0][0][1]一定不存在,即存在之前，c选0，ab均选1，不可能110!

            

            dp[i][1][1][0]=dp[i-1][1][0][0]+dp[i-1][0][1][0]+3*dp[i-1][1][1][0];//没有001

            //                     101           011                 111/101/011

            dp[i][1][0][1]=dp[i-1][0][0][0]+dp[i-1][1][0][0]+2*dp[i-1][0][0][1]+3*dp[i-1][1][0][1];

            //                     010           x10->010            01x->010/011      x1x->111/010/011

            dp[i][0][1][1]=dp[i-1][0][0][0]+dp[i-1][0][1][0]+2*dp[i-1][0][0][1]+3*dp[i-1][0][1][1];

            //    1xx              100           1x0->100            10x->100/101      1xx->111/100/101



            dp[i][1][1][1]=dp[i-1][0][0][0]+2*dp[i-1][1][0][0]+2*dp[i-1][0][1][0]+dp[i-1][0][0][1]+3*dp[i-1][1][1][0]+3*dp[i-1][1][0][1]+3*dp[i-1][0][1][1]+6*dp[i-1][1][1][1];

            //                     000           x00->000/100        0x0->000/010      00x->000     xx0->000/100/010   x0x->000/100/101   0xx->000/010/011 xxx->000/111/100/101/010/011

        }

    }

    Mod now=dp[n][0][0][0]+dp[n][1][0][0]+dp[n][0][1][0]+dp[n][0][0][1]+dp[n][1][1][0]+dp[n][1][0][1]+dp[n][0][1][1]+dp[n][1][1][1];

    Mod g=0;

    for(int i=1;i<=n;i++)

    {

        g=g*2;

        if(s[i]=='1') g+=1;

    }

    Mod res=(g+1)*(g+1)*(g+1)-(3*now-3*(g+1)*(g+1)+(g+1));



    printf("%lld\n",res);

}