#include <bits/stdc++.h>

// using namespace std;

#define DEBUG(...) fprintf(stderr,__VA_ARGS__)

#define rep(i , l , r) for(int i = (l) , ___ = (r) ; i <= ___ ; ++i )
#define per(i , r , l) for(int i = (r) , ___ = (l) ; i >= ___ ; --i )

// using LL = long long;
// using uLL = unsigned long long;
typedef long long LL;
typedef unsigned long long uLL;

const int Mod = 998244353; 

template<typename T>inline bool chkmin(T &x , const T &y) { return x > y ? (x = y , 1) : 0; }
template<typename T>inline bool chkmax(T &x , const T &y) { return x < y ? (x = y , 1) : 0; }

template<typename T>inline T sq(const T &x) { return x * x; }
template<typename T>inline T add(T x , const T &y) { x += y; return x > Mod ? x - Mod : x; }
template<typename T>inline T sub(T x , const T &y) { x -= y; return x < 0 ? x + Mod : x;}
template<typename T>inline T mul(const T &x , const T &y) { return 1ll * x * y % Mod; }

template<typename T>inline T read(T &f)
{
    f = 0; int x = 1 ; char c = getchar();
    while(!isdigit(c)) x = (c == '-' ? -1 : 1) , c = getchar();
    while(isdigit(c)) (f *= 10) += c & 15 , c = getchar();
    return f = x * f;
}
// template<typename T , typename ... Args>inline void read(T &x , Args&& ... y) { read(x) , read(y...); }

const int N = 400000 + 5;

int n , m , q , x , y , fa[N];

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main()
{
    read(n) , read(m) , read(q);
    rep(i , 1 , n+m) fa[i] = i;
    rep(i , 1 , q)
    {
        read(x) , read(y);
        y += n;
        x = find(x) , y = find(y);
        if(x == y) continue;
        fa[x] = y;
    }
    int Ans = 0;
    rep(i , 1 , n+m) if(fa[i] == i) Ans++;
    printf("%d\n" , Ans-1);
    return 0;
}