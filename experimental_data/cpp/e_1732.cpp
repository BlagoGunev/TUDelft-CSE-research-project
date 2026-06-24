#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")

#pragma GCC target("avx2,fma,tune=native")

#include<bits/stdc++.h>

using namespace std;

const int BUFSIZE=5<<20;//20MB

char Buf[BUFSIZE+1],*buf=Buf;

//fread(Buf,1,BUFSIZE,stdin); add this before taking any input...

template<class T>

void scan(T&a){

    int sgn=1;

    for(a=0;*buf<'0'||*buf>'9';buf++)if(*buf=='-')sgn=-1;

    while(*buf>='0'&&*buf<='9'){a=a*10+(*buf-'0');buf++;}

    a*=sgn;

}

#define N 50100

#define B 150

#define A 50001

#define MX 50005

#define int long long

vector<int>primes;

int isc[MX+100];

void sieve(){

    isc[1]=true;

    for(int a=2;a<=MX;++a){

        if(!isc[a]){primes.push_back(a);isc[a]=a;}

        for(int b=0;b<primes.size()&&primes[b]*a<=MX;++b){

            isc[primes[b]*a]=primes[b];

            if(!(a%primes[b])){break;}

        }

    }

}

int ggcd(int x,int y){

    return (y)?ggcd(y,x%y):x;

}

unsigned int gcd(unsigned int u, unsigned int v) {

    int shift;

    if (u == 0)

        return v;

    if (v == 0)

        return u;

    shift = __builtin_ctz(u | v);

    u >>= __builtin_ctz(u);

    do {

        unsigned m;

        v >>= __builtin_ctz(v);

        v -= u;

        m = (int)v >> 31;

        u += v & m;

        v = (v + m) ^ m;

    } while (v != 0);

    return u << shift;

}

int calc(int x,int y){

    int g=gcd(x,y);

    return x*y/g/g;

}

vector<int>gr[A];

struct block{

    int sz;

    int ara[B],arb[B];

    int prec[A];

    int ans,lsv;

    int&operator[](int i){return ara[i];}

    void set_all(int x){

        ans=prec[lsv=x];

    }

    void push(){

        if(~lsv) {

            for (int a = 0; a < sz; ++a) {

                ara[a] = lsv;

            }

            lsv=-1;

        }

    }

    void recompute(){

        ans=LONG_LONG_MAX;

        for(int a=0;a<sz;++a){

            ans=min(ans,calc(ara[a],arb[a]));

        }

    }

};

void precompute(block&x){

    int*dp=x.prec;

    for(int a=1;a<A;++a){

        dp[a]=INT_MAX;

    }

    for(int a=0;a<x.sz;++a){

        dp[x.arb[a]]=1;

    }

    for(int a=A-1;a>0;--a){

        for(auto b:gr[a]){

            dp[a/b]=min(dp[a/b],dp[a]*b);

        }

    }

    for(int a=1;a<A;++a){

        for(auto b:gr[a]){

            dp[a]=min(dp[a],dp[a/b]*b);

        }

    }

}

int n,q;

int ara[N],arb[N];

block pro[N/B];

signed main(){

    //freopen("dragon3.in","r",stdin);

    fread(Buf,1,BUFSIZE,stdin);

    sieve();

    int ne=0;

    for(int a=1;a<A;++a){

        int cur=a;

        int lst=-1;

        while(cur>1){

            if(lst!=isc[cur]){

                gr[a].push_back(isc[cur]);

            }

            lst=isc[cur];

            cur/=isc[cur];

        }

    }

    scan(n),scan(q);

    for(int a=0;a<n;++a){

        scan(ara[a]);

    }

    for(int a=0;a<n;++a){

        scan(arb[a]);

    }

    for(int a=0;a<n;a+=B){

        pro[a/B].lsv=-1;

        for(int b=a;b<min(n,a+B);++b){

            pro[a/B].ara[b-a]=ara[b];

            pro[a/B].arb[b-a]=arb[b];

            ++pro[a/B].sz;

        }

        precompute(pro[a/B]);

        pro[a/B].recompute();

    }

    for(int a=0;a<q;++a){

        int t,l,r,x;

        scan(t),scan(l),scan(r);

        --l,--r;

        if(t==1){

            scan(x);

            int bl=(l/B),br=(r/B);

            if(bl==br){

                int nl=l-bl*B,nr=r-bl*B;

                pro[bl].push();

                for(int b=nl;b<=nr;++b){

                    pro[bl].ara[b]=x;

                }

                pro[bl].recompute();

            }

            else{

                for(int b=bl+1;b<br;++b){

                    pro[b].set_all(x);

                }

                pro[bl].push(),pro[br].push();

                int nl=l-bl*B,nr=r-br*B;

                for(int b=nl;b<B;++b){

                    pro[bl][b]=x;

                }

                for(int b=0;b<=nr;++b){

                    pro[br][b]=x;

                }

                pro[bl].recompute(),pro[br].recompute();

            }

        }

        else{

            int ans=LONG_LONG_MAX;

            int bl=(l/B),br=(r/B);

            if(bl==br){

                pro[bl].push();

                int nl=l-bl*B,nr=r-bl*B;

                for(int b=nl;b<=nr;++b){

                    ans=min(ans,calc(pro[bl].ara[b],pro[bl].arb[b]));

                }

            }

            else{

                for(int b=bl+1;b<br;++b){

                    ans=min(ans,pro[b].ans);

                }

                pro[bl].push(),pro[br].push();

                int nl=l-bl*B,nr=r-br*B;

                for(int b=nl;b<B;++b){

                    ans=min(ans,calc(pro[bl].ara[b],pro[bl].arb[b]));

                }

                for(int b=0;b<=nr;++b){

                    ans=min(ans,calc(pro[br].ara[b],pro[br].arb[b]));

                }

            }

            printf("%lld\n",ans);

        }

    }

    //cout<<v1<<" "<<clock()-clocker<<endl;

}



/*

Thoughts

 Two ways to deal with the given expression, prod p^(max-min) or ab/gcd^2

 x*gcd,y*gcd -> xy



Review

 Don't immediately jump to segment tree, try going through sqrt decomposition first

 Consider heavy precomputation that may be possible with such small bounds on integers

 */