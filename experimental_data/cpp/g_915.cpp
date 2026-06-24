#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE=10000020;
const int mod=1000000007;
int bufpos;
char buf[MAXSIZE];
#define NEG 0
void init(){
    #ifdef LOCAL
        freopen("915G.txt","r",stdin);
    #endif
    buf[fread(buf,1,MAXSIZE,stdin)]='\0';
    bufpos=0;
}
#if NEG
int readint(){
    bool isneg;
    int val=0;
    for(;!isdigit(buf[bufpos]) && buf[bufpos]!='-';bufpos++);
    bufpos+=(isneg=buf[bufpos]=='-');
    for(;isdigit(buf[bufpos]);bufpos++)
        val=val*10+buf[bufpos]-'0';
    return isneg?-val:val;
}
#else
int readint(){
    int val=0;
    for(;!isdigit(buf[bufpos]);bufpos++);
    for(;isdigit(buf[bufpos]);bufpos++)
        val=val*10+buf[bufpos]-'0';
    return val;
}
#endif
char readchar(){
    for(;isspace(buf[bufpos]);bufpos++);
    return buf[bufpos++];
}
int readstr(char* s){
    int cur=0;
    for(;isspace(buf[bufpos]);bufpos++);
    for(;!isspace(buf[bufpos]);bufpos++)
        s[cur++]=buf[bufpos];
    s[cur]='\0';
    return cur;
}
ll power(ll x,ll y){
    ll ans=1;
    while(y){
        if (y&1)
            ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
int u[2000002];
ll pw[2000002];
bool ntprime[2000002];
int primes[2000002],cur;
void sieve(int n,int m){
    pw[1]=u[1]=ntprime[1]=1;
    for(int i=2;i<=n;i++){
        if (!ntprime[i]){
            primes[++cur]=i;
            u[i]=-1;
            pw[i]=power(i,m);
        }
        for(int j=1;j<=cur;j++){
            if (i*primes[j]>n)
                break;
            ntprime[i*primes[j]]=1;
            pw[i*primes[j]]=pw[i]*pw[primes[j]]%mod;
            if (i%primes[j]==0){
                // u[i*primes[j]]=0;
                break;
            }
            u[i*primes[j]]=-u[i];
        }
    }
}
ll ans[3000002];
int main(){
    init();
    int n=readint(),k=readint();
    sieve(k,n);
    for(int i=1;i<=k;i++){
        if (!u[i])
            continue;
        // printf("u[%d]=%d\n",i,u[i]);
        for(int j=i,now=1;j<=k;j+=i,now++){
            ans[j]+=u[i]*pw[now];
            ans[j+i]-=u[i]*pw[now];
        }
    }
    ll sum=0;
    for(int i=1;i<=k;i++){
        ans[i]=(ans[i]+ans[i-1])%mod;
        if (ans[i]<0)
            ans[i]+=mod;
        // printf("ans[%d]=%lld\n",i,ans[i]);
        sum+=ans[i]^i;
    }
    printf("%lld",sum%mod);
}