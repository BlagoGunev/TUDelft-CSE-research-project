#include <bits/stdc++.h>



using namespace std;



using i64=long long;

using u64=unsigned long long;

using db=double;

using pii=pair<int,int>;

using vi=vector<int>;



template<typename T>

inline T read(){

    T x=0,f=0;char ch=getchar();

    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();

    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();

    return f?-x:x;

}



#define rdi read<int>

#define rdi64 read<i64>

#define fi first

#define se second

#define pb push_back



const int N=5e5+10;



int n,res[N];



int p[N],pc,v[N];

void init(){

    v[1]=1;

    for(int i=2;i<=n;i++){

        if(!v[i]) v[i]=i,p[++pc]=i;

        for(int j=1;j<=pc;j++){

            if(p[j]>v[i]||p[j]>n/i) break;

            v[p[j]*i]=p[j];

        }

    }

}



int main(){

#ifdef LOCAL

    freopen("1.in","r",stdin);

    freopen("1.out","w",stdout);

#endif

    n=rdi();init();

    memset(res,0x3f,sizeof(res));

    static int mx[N];

    for(int i=1;i<=n;i++) mx[i/v[i]]++;

    for(int i=1;i<=n;i++) mx[i]+=mx[i-1],res[mx[i]]=min(res[mx[i]],i);

    for(int i=n;i>=2;i--) res[i]=min(res[i],res[i+1]);

    for(int i=2;i<=n;i++) cout<<res[i]<<' ';

    return 0;

}