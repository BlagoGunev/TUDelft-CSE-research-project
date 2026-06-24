#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define X first
#define Y second
#define endl '\n'
#define gcd __gcd
#define lcm(x,y) ((x)*(y)/gcd(x,y))
#define smin(x,y) (x=min(x,y))
#define smax(x,y) (x=max(x,y))
#define sgcd(x,y) (x=gcd(x,y))
#define slcm(x,y) (x=lcm(x,y))
#define obt __builtin_popcount
#define pb push_back
#define pob pop_back
#define mkp make_pair
#define rsort(x,y) sort(x,y),reverse(x,y);
#define dbg(x) cerr<<#x<<": "<<x<<endl
using namespace std;
const ld INF=1LL<<60,EPS=1LL>>60;
template<class T> T pw(T a,ll b){return b?pw(a*a,b/2)*(b%2?a:(T)1):1;}
ll in(){char c;bool g=false;while(c=getchar(),c<'0'||c>'9')if(c=='-')g=true;else g=false;ll x=0;while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}return g?-x:x;}
void out(ll x){ll len=0,data[20];while(x){data[len++]=x%10;x/=10;}if(!len)data[len++]=0;if(data[0]!=abs(data[0]))putchar('-');while(len--)putchar(abs(data[len])+48);putchar('\n');}
void out(string s){ll len=0;while(len++<s.size())putchar(s[len-1]);putchar('\n');}
int main()
{
    int n=in(),a=in(),b=in(),t=in();
    string s="";
    for(int i=0;i<n;i++){char c=getchar();s+=c;}
    s=s+s;
    int j=1,sum1=-2*a,sum2=-a,ans=0;
    for(int i=1;i<=n;i++)
    {
        while(j-i<n && min(sum1+(j>n?1:2)*a+1+b*(s[j]=='w'),sum2+(j>n?2:1)*a+1+b*(s[j]=='w'))<=t)sum1+=(j>n?1:2)*a+1+b*(s[j]=='w'),sum2+=(j>n?2:1)*a+1+b*(s[j]=='w'),j++;
        if(j>n)smax(ans,j-i);
        sum1-=2*a+1+b*(s[i]=='w');
        sum2-=a+1+b*(s[i]=='w');
    }
    cout<<ans<<endl;
    return 0;
}