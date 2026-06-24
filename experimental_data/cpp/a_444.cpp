#include<cstdio>
#include<iostream>
#include<algorithm>
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i=a;i<=b;++i)
#include<vector>
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
typedef long long LL;
#define X first
#define Y second
#define N 505
int c[N][N],a[N],n,m;
int main() {
    read(n,m);
    rep(i,1,n) read(a[i]);
    int x,y,z;
    rep(i,1,m) read(x,y,z),c[x][y]=c[y][x]=z;
    double ans=0;
    rep(i,1,n) 
        rep(j,i+1,n) if (c[i][j]) ans=max(ans,(double)(a[i]+a[j])/(c[i][j]));
    printf("%.20lf\n",ans);
    return 0;
}