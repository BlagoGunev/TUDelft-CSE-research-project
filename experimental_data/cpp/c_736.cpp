#include <cstdio>
#include <cstdlib>
#include <vector>
#include <array>
#include <functional>
#include <map>
#include <iterator>
#include <utility>
#include <algorithm>
namespace XX
{   
    template<template<typename> class Compare, typename T>
    inline T& UP(T& x, const T& y){if(Compare<T>()(y, x)) x = y; return x;}
    template<typename Compare, typename T>
    inline T& UP(T& x, const T& y, Compare comp){if(comp(y, x)) x = y; return x;}

    template<typename T> inline T& GT(T& x, const T& y){return UP<std::greater>(x, y);}
    template<typename T> inline T& LS(T& x, const T& y){return UP<std::less>(x, y);}

    template<typename T>
    struct Mapper
    {
        int operator[](const T& v) { int& ret = table[v]; if(!ret) rtable[ret = table.size()] = v; return ret - 1; }
        template<typename... Args> int operator()(Args... args) { return (*this)[T(args...)]; }
        T rev(int idx){return rtable[idx + 1];}
        std::map<T, int> table;
        std::map<int, T> rtable;
    };

    template<typename T, int S>
    struct ReferenceArray
    {
        struct It {typename std::array<T*, S>::iterator it; T& operator*(){return **it;} void operator++(){it++;} bool operator!=(const It& other){return it != other.it;} };
        int size()const{return _ptr.size();}
        It begin()const{return {_ptr.begin()};}
        It end()const{return {_ptr.end()};}
        T& operator[](int idx)const{return *_ptr[idx];}
        mutable std::array<T*, S> _ptr;
    };
    template<typename T, typename... Args> 
    ReferenceArray<T, sizeof...(Args) + 1> MAKEV(T& arg1, Args&... args) {return {&arg1, &args...};}

    struct Range
    {   
        struct It {   int num, step; int operator*(){return num;} void operator++(){num += step;} bool operator!=(const It& other){return num != other.num;} };
        Range(int ee):b(0),e(ee){}
        Range(int bb, int ee):b(bb), e(ee){}
        It begin(){return {b, (b < e? 1: -1)};}
        It end(){return {e, 0};}
        int b, e;
    };

}



template<typename T> struct ScanfSpecifier{};
#define DEF(T,V) template<> struct ScanfSpecifier<T>{static constexpr const char* value = V;};
DEF(char*,"%s")DEF(int,"%d")DEF(double,"%lf")DEF(float,"%f")DEF(char,"%c")DEF(const char*,"%s")DEF(unsigned long,"%lu")DEF(unsigned int, "%u")
#ifdef _MSC_VER
DEF(long long int,"%I64d")
#else
DEF(long long int,"%lld")
#endif
#undef DEF
template<typename T> int RD(T& arg){return std::scanf(ScanfSpecifier<T>::value, &arg);}
template<int S> int RD(char (&arg)[S]){return std::scanf("%s", arg);}
int RD(char* arg){return std::scanf("%s", arg);}
template<> int RD<char>(char& arg){return std::scanf(" %c", &arg);}
template<typename T, typename... Args> int RD(T& arg1, Args&... args) {return RD(arg1) + RD(args...);}
template<typename T> T RD(){T ret; RD(ret); return ret;}
template<typename It> void RDV(It begin, It end) { while(begin != end) RD(*begin++); }
template<typename C> void RDV(C& c) {RDV(std::begin(c), std::end(c));}
template<typename T> void WT(T arg) {std::printf(ScanfSpecifier<T>::value, arg); }
template<typename T, typename U> void WT(std::pair<T, U> arg) {std::printf("("); WT(arg.first); std::printf(", "); WT(arg.second); std::printf(")");}
template<typename... Args> void WT(Args... args) { int alc = 0; int dummy[] = {((alc++? std::printf(" "): 0), WT(args), 0)...}; }

template<typename... Args> void WTL(Args... args) { WT(args...); std::printf("\n"); }
template<typename It> void WTV(It begin, It end) { int alc = 0; while(begin != end) (alc++? std::printf(" "): 0), WT(*begin++); }
template<typename C> void WTV(const C& c) {WTV(std::begin(c), std::end(c));}
template<typename It> void WTVL(It begin, It end) { WTV(begin, end); std::printf("\n"); }
template<typename C> void WTVL(const C& c) {WTVL(std::begin(c), std::end(c));}




template<unsigned int Z>
struct ZpZ
{
    static const unsigned int P = Z;
    using U64 = unsigned long long int;
    U64 value;
    ZpZ(long long int n) {if(std::abs(n) >= P)n %= P; if(n < 0)n += P; value = n;}
    ZpZ():value(0){}
    ZpZ& operator+=(ZpZ p){if((value += p.value) >= P)value -= P; return *this;}
    ZpZ& operator-=(ZpZ p){if(value >= p.value)value -= p.value; else value += P - p.value; return *this;}
    ZpZ& operator*=(ZpZ p){value = value * p.value % P; return *this;}
    ZpZ& operator/=(ZpZ p){value = value * p.inverse().value % P; return *this;}
    bool operator==(ZpZ p){return value == p.value;}
    bool operator!=(ZpZ p){return value != p.value;}

#define DEF(op) ZpZ operator op(ZpZ r)const{return ZpZ(value) op##= r;}
DEF(+)DEF(-)DEF(*)DEF(/)
#undef DEF

    explicit operator long long int()const{return value;}
    explicit operator int()const{return value;}
    ZpZ operator-(){return P - value;}
    ZpZ inverse()
    {
        int a = value, b = P, u = 1, v = 0;
        while(b) 
        {
            int t = a / b;
            std::swap(a -= t * b, b); 
            std::swap(u -= t * v, v);
        }
        if(u < 0) u += P;
        return u;
    }
    ZpZ pow(U64 e)
    {
        U64 ret = 1, base = value;
        while(e)
        {
            if((e & 1) && ((ret *= base) >> 32))
                ret %= P;
            if((base *= base) >> 32)
                base %= P;
            e >>= 1;
        }
        return ret;
    }

};

template<unsigned int P>
void WT(ZpZ<P> arg) {WT((int)arg);}






//alias
//RD[L],RDV[L],WT[L],WTV[L] for i/o
const int MOD = 1e9 + 7;
using ZZ = ZpZ<MOD>;
ZZ min(ZZ a, ZZ b){return std::min(a.value, b.value);}
ZZ max(ZZ a, ZZ b){return std::max(a.value, b.value);}
template<typename T> T& UMAX(T& x, T y){return XX::UP<std::greater>(x, y);}
template<typename T> T& UMIN(T& x, T y){return XX::UP<std::less>(x, y);}
using XX::UP; //(x,y) comp
using RG = XX::Range;
using XX::MAKEV;
using XX::Mapper;
//template
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <functional>
using namespace std;

int N, K;
vector<int> adj[109];
ZZ dp[109][2][29];


void dfs(int u, int p)
{
    ZZ buf[2][2][29] = {};
    buf[0][0][0] = 1;
    buf[0][1][0] = 1;

    int a = 0, b = 1;
    for(int to: adj[u])
        if(to != p)
        {
            dfs(to, u);
            memset(buf[b], 0, sizeof(buf[b]));

            for(int i = 0; i < K; i++)
            {
                for(int j = 0; j < K; j++)
                    buf[b][0][max(i, j + 1)] += buf[a][0][i] * dp[to][0][j];
                for(int j = 0; j <= K; j++)
                    if(i + j + 1 <= K)
                        buf[b][1][j + 1] += buf[a][0][i] * dp[to][1][j];
                    else
                        buf[b][0][i] += buf[a][0][i] * dp[to][1][j];
            }
            for(int i = 0; i <= K; i++)
            {
                for(int j = 0; j < K; j++)
                    if(i + j + 1 <= K)
                        buf[b][1][i] += buf[a][1][i] * dp[to][0][j];
                    else
                        buf[b][0][j + 1] += buf[a][1][i] * dp[to][0][j];
                for(int j = 0; j <= K; j++)
                    buf[b][1][min(i, j + 1)] += buf[a][1][i] * dp[to][1][j];
            }

            a ^= 1;
            b ^= 1;
        }

    for(int j = 0; j < 2; j++)
    for(int i = 0; i <= K; i++)
        dp[u][j][i] = buf[a][j][i];
}

int main()
{
    RD(N, K);
    for(int i: RG(N - 1))
    {
        int u, v;
        RD(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    dfs(1, 0);

    ZZ ans = 0;
    for(int i = 0; i <= K; i++)
        ans += dp[1][1][i];

    WTL(ans);

}