#include <bits/stdc++.h>
using namespace std;
#define cs const
#define re register
#define pb push_back
#define y0 sxxxxx
#define pii pair<int, int>
#define ll long long
#define fi first
#define se second
#define bg begin
namespace IO{

cs int RLEN=1<<22|1;
char ibuf[RLEN],*ib,*ob;
inline char gc(){
    (ib==ob)&&(ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
    return (ib==ob)?EOF:*ib++;
}
inline int read(){
    char ch=gc();
    int res=0;bool f=1;
    while(!isdigit(ch))f^=ch=='-',ch=gc();
    while(isdigit(ch))res=(res*10)+(ch^48),ch=gc();
    return f?res:-res;
}
inline ll readll(){
    char ch=gc();
    ll res=0;bool f=1;
    while(!isdigit(ch))f^=ch=='-',ch=gc();
    while(isdigit(ch))res=(res*10)+(ch^48),ch=gc();
    return f?res:-res;
}
inline char readchar(){
	char ch=gc();
	while(isspace(ch))ch=gc();
	return ch;
}
inline int readstring(char *s){
	int top=0;char ch=gc();
	while(isspace(ch))ch=gc();
	while(!isspace(ch)&&ch!=EOF)s[++top]=ch,ch=gc();
	s[top+1]='\0';return top;
}

}
using IO::read;
using IO::readll;
using IO::readchar;
using IO::readstring;
template <typename tp>
inline void chemx(tp &a, tp b) { (a < b) ? (a = b) : 0; }
template <typename tp>
inline void chemn(tp &a, tp b) { (a > b) ? (a = b) : 0; }

cs int mod=998244353;
inline int add(int a,int b){return (a+b)>=mod?(a+b-mod):(a+b);}
inline int dec(int a,int b){return (a<b)?(a-b+mod):(a-b);}
inline int mul(int a,int b){static ll r;r=(ll)a*b;return (r>=mod)?(r%mod):r;}
inline void Add(int &a,int b){a=(a+b)>=mod?(a+b-mod):(a+b);}
inline void Dec(int &a,int b){a=(a<b)?(a-b+mod):(a-b);}
inline void Mul(int &a,int b){static ll r;r=(ll)a*b;a=(r>=mod)?(r%mod):r;}
inline int ksm(int a,int b,int res=1){for(;b;b>>=1,Mul(a,a))(b&1)&&(Mul(res,a),1);return res;}
inline int Inv(int x){return ksm(x,mod-2);}
inline int fix(ll x){x%=mod;return (x<0)?x+mod:x;}

cs int N=200005;
int a[2][N],n;

void solve(){
    n=read();
    for(int j=0;j<2;j++)
    for(int i=1;i<=n;i++){
        a[j][i]=read();
    }
    ll ans=-1e18;
    for(int i=1;i<=n;i++){
        ll res=a[0][i]+a[1][i];
        for(int j=1;j<=n;j++)if(j!=i){
            res+=max(a[0][j],a[1][j]);
        }
        ans=max(ans,res);
    }
    cout<<ans<<'\n';
}  


int main() {
	#ifdef Stargazer
	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	#endif
  //  cout<<(&yy-&xx)/1024/1024<<'\n';
	int T=read();  
    //int T=1;
    while(T--){
        solve();
    }
}