#pragma comment(linker, "/STACK:102400000,102400000")

#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

#define pii pair<int,int>

#define pb push_back

#define mp make_pair

#define all(x) x.begin(),x.end()

#define SZ(x) (int)(x.size())

#define rep(i,a,b) for(int i=a;i<b;i++)

#define per(i,a,b) for(int i=b-1;i>=a;i--)

#define inf 1000000007

#define mod 1000000007

#define x first

#define y second

#define pi acos(-1.0)

#define DBG(x) cerr<<(#x)<<"="<<x<<"\n";

//#define dprintf(...) 

#define hash _hash

#define next _next

//#define dprintf(...) fprintf(outFile,__VA_ARGS__)

 

#define FOREACH(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)

#define ull unsigned long long

#define ll long long

#define N 100010

 

template <class T,class U>inline void Max(T &a,U b){if(a<b)a=b;}

template <class T,class U>inline void Min(T &a,U b){if(a>b)a=b;}

 

//FILE* outFile;

inline void add(int &a,int b){a+=b;while(a>=mod)a-=mod;}





int pow(int a,int b){

    int ans=1;

    while(b){

        if(b&1)ans=ans*(ll)a%mod;

        a=(ll)a*a%mod;b>>=1;

    }

    return ans;

}





struct P{

    ll x,y;

    P(){x=y=0;}

    P(ll _x):x(_x){y=0;}

    P(ll _x,ll _y){x=_x,y=_y;}

    inline P conj(){return P(x,(mod-y)%mod);}

};

inline P operator +(const P&a,const P&b){return P((a.x+b.x)%mod,(a.y+b.y)%mod);}

inline P operator -(const P&a,const P&b){return P((a.x-b.x+mod)%mod,(a.y-b.y+mod)%mod);}

inline P operator *(const P&a,const P&b){return P((a.x*b.x+5*a.y*b.y)%mod,(a.x*b.y+a.y*b.x)%mod);}

inline P operator /(P a,P b){

    P tmp=b.conj();

    a=a*tmp;b=b*tmp;

    a=a*(pow((int)b.x,mod-2));

    return a;

}

inline P operator ^(P a,ll n){

    P ans(1);

    while(n){

        if(n&1)ans=ans*a;

        a=a*a;n>>=1;

    }

    return ans;

} 

const P S(0,1),A=(1+S)/2,B=(1-S)/2;

P fib(ll n){

    P ans=(A^n)-(B^n);

    return ans/S;

}

P sum(P x,ll n){

    if(x.x==1&&x.y==0)return n%mod;

    return (1-(x^n))/(1-x)*x;

}

P s[210][210],c[210][210];

P solve(int k,ll n){

    P ans=0;

    rep(i,1,k+1){

        P w=0;

        rep(j,0,i+1){

            P v=sum((A^j)*(B^(i-j)),n)*c[i][j];

            if((i-j)&1)w=w-v;else w=w+v;

        }

        w=w*((1/S)^i);

        w=w*s[k][i];

        if((k-i)&1)ans=ans-w;else ans=ans+w;

    }

    return ans;

}

int main(){

    //freopen("A.in","r",stdin);

    //freopen("A.out","w",stdout);

    int i,j,k=0,ca=0,m=0,T,K,n;

    ll l,r;

    cin>>k>>l>>r;l+=2,r+=2;

    c[0][0]=c[1][0]=c[1][1]=s[1][1]=1;

    rep(i,2,k+1){

        c[i][0]=1;

        rep(j,1,i+1)s[i][j]=s[i-1][j-1]+(i-1)*s[i-1][j],c[i][j]=c[i-1][j-1]+c[i-1][j];

    }

    P ans=solve(k,r)-solve(k,l-1);

    rep(i,1,k+1)ans=ans/i;

    printf("%d\n",ans.x);

    //cerr<<1.*clock()/CLOCKS_PER_SEC<<"s\n";

    return 0;

}