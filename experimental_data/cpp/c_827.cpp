#include <cstdio>
#include <vector>
#include <map>
#include <array>
#include <functional>
#include <iterator>
#include <utility>
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

#define _M_VARGS_NUM_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N
#define _M_VARGS_NUM(...) _M_VARGS_NUM_IMPL(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define _W1(_1) (#_1[0] == '"' || #_1[0] == '\''? WT("", _1, ""): WT('[', #_1, '=', _1, ']'))
#define _W2(_1, _2) (_W1(_1), _W1(_2))
#define _W3(_1, _2, _3) (_W1(_1), _W2(_2, _3))
#define _W4(_1, _2, _3, _4) (_W1(_1), _W3(_2, _3, _4))
#define _W5(_1, _2, _3, _4, _5) (_W1(_1), _W4(_2, _3, _4, _5))
#define _W6(_1, _2, _3, _4, _5, _6) (_W1(_1), _W5(_2, _3, _4, _5, _6))
#define _W7(_1, _2, _3, _4, _5, _6, _7) (_W1(_1), _W6(_2, _3, _4, _5, _6, _7))
#define _W8(_1, _2, _3, _4, _5, _6, _7, _8) (_W1(_1), _W7(_2, _3, _4, _5, _6, _7, _8))
#define _WW_IMPL2(num, ...) _W ## num(__VA_ARGS__)
#define _WW_IMPL(num, ...) _WW_IMPL2(num, __VA_ARGS__)
#define WW(...) (std::printf("(%03d) ", __LINE__), _WW_IMPL(_M_VARGS_NUM(__VA_ARGS__), __VA_ARGS__), WTL(""))




struct Range
{   
    struct It {   int num, step; int operator*(){return num;} void operator++(){num += step;} bool operator!=(const It& other){return num != other.num;} };
    Range(int ee):b(0),e(ee){}
    Range(int bb, int ee):b(bb), e(ee){}
    It begin(){return {b, (b < e? 1: -1)};}
    It end(){return {e, 0};}
    int b, e;
};

template<typename T> inline T& UMAX(T& x, T y){if(x < y)x = y; return x;}
template<typename T> inline T& UMIN(T& x, T y){if(y < x)x = y; return x;}
template<typename T, typename... Args> struct ArithmiticPromotion { typedef decltype(T() + typename ArithmiticPromotion<Args...>::type()) type; };
template<typename T, typename U> struct ArithmiticPromotion<T, U> { typedef decltype(T() + U()) type; };
template<typename T> struct ArithmiticPromotion<T, T> { typedef T type; };
template<typename T> struct ArithmiticPromotion<T> { typedef T type; };
template<typename T, typename U> typename ArithmiticPromotion<T, U>::type MAX(T a, U b) { return a < b? b: a; }
template<typename T, typename... Args> typename ArithmiticPromotion<T, Args...>::type MAX(T a, Args... args) { return MAX(a, MAX(args...)); }
template<typename T, typename U> typename ArithmiticPromotion<T, U>::type MIN(T a, U b) { return a < b? a: b; }
template<typename T, typename... Args> typename ArithmiticPromotion<T, Args...>::type MIN(T a, Args... args) { return MIN(a, MIN(args...)); }




#ifdef _MSC_VER
#include <intrin.h>
inline int CLZ(int n){unsigned long ret; _BitScanForward(&ret, n); return ret;}
//inline int CLZ(long long int n){unsigned long ret; _BitScanForward64(&ret, n); return ret;}
inline int CTZ(int n){unsigned long ret; _BitScanReverse( &ret, n); return 31 - ret;} 
//inline int CTZ(long long int n){unsigned long ret; _BitScanReverse64( &ret, n); return 63 - ret;} 
inline int POPCNT(int n){return __popcnt(n);}
//inline int POPCNT(long long int n){return __popcnt64(n);}
#endif

#ifdef __GNUC__
inline int CLZ(int n){return __builtin_clz(n);}
inline int CLZLL(long long int n){return __builtin_clzll(n);}
inline int CTZ(int n){return __builtin_ctz(n);}
inline int CTZLL(long long int n){return __builtin_ctzll(n);}
inline int POPCNT(int n){return __builtin_popcount(n);}
inline int POPCNTLL(long long int n){return __builtin_popcountll(n);}
#endif





//#include "mylib/Buffer.cpp"

namespace XX
{
    template<typename T>//, typename U = DefaultUpdater<T>, typename A = DefaultAggregator<T>>
    class BinaryIndexedTree
    {
        public:


        BinaryIndexedTree(){}
        BinaryIndexedTree(int size)
            :_data(size + 1, 0)
        {}

        BinaryIndexedTree(int size, const T& val)
            :_data(size + 1, val)
        {}

        int lower_bound(T value)
        {
            if(!value)
                return 0;

            T cur = T();
            int cur_mask = 0;
            for(int mask = 1 << (31 - CLZ((int)_data.size() - 1)); mask; mask >>= 1)
                if((cur_mask | mask) < _data.size() && cur + _data[cur_mask | mask] < value)
                    cur += _data[cur_mask |= mask];
            return cur_mask + (cur < value) - 1;
        }

        int lower_bound(int l, T value)
        {
            if(!value)
                return l;

            T v = query(l - 1);
            return lower_bound(value + query(l - 1));
        }
        template<typename U>
        void update(int idx, U updater)
        {
            idx++;
            while(idx < _data.size())
            {
                updater(_data[idx]);
                idx += idx & -idx;
            }
        }

        void update(int idx, const T& val)
        {
            idx++;
            while(idx < _data.size())
            {
                _data[idx] += val;
                idx += idx & -idx;
            }
        }


        
        template<typename F>
        void query(int idx, F agt)
        {
            idx++;
            while(idx > 0) { agt(_data[idx]); idx -= idx & -idx; }
        }

        template<typename F>
        void query(int l, int r, F agt)
        {
            while(r > 0) { agt(_data[r], 1); r -= r & -r; }
            while(l > 0) { agt(_data[l], -1); l -= l & -l; }
        }

        T query(int idx)
        {
            idx++;
            T ret = T();
            while(idx > 0) { ret += _data[idx]; idx -= idx & -idx; }
            return ret;
        }

        T query(int l, int r)
        {
            T ret = T();
            while(r > 0) { ret += _data[r]; r -= r & -r; }
            while(l > 0) { ret -= _data[l]; l -= l & -l; }
            return ret;
        }
        private:
        std::vector<T> _data;
    };
}








//alias
//bit operation => CLZ,CTZ,POPCNT
template<typename T>
using BIT = XX::BinaryIndexedTree<T>;  //query(idx,[aggregator]) update(idx,value|[updater])  lower_bound(value)
using RG = Range;
//RD[L],RDV[L],WT[L],WTV[L] for i/o
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

typedef long long int ll;

BIT<int> bit[4][11][11];
char S[100009];

int c2i(char c)
{
    switch(c)
    {
        case 'A': return 0;
        case 'T': return 1;
        case 'G': return 2;
        default: return 3;
    }
}

int main()
{
    RD(S);
    int N = strlen(S);

    for(int c: RG(4))
        for(int l: RG(1, 11))
            for(int m: RG(l))
                bit[c][l][m] = BIT<int>((N + l - 1)/ l);


    for(int i: RG(N))
    {
        S[i] = c2i(S[i]);
        for(int l: RG(1, 11))
            bit[S[i]][l][i % l].update(i / l, 1);
    }

    int Q;
    RD(Q);
    while(Q--)
    {
        int t;
        RD(t);
        if(t == 1)
        {
            int i;
            char c;
            RD(i, c);
            c = c2i(c);
            i--;
            if(S[i] == c)continue;

            for(int l: RG(1, 11))
            {
                bit[S[i]][l][i % l].update(i / l, -1);
                bit[c][l][i % l].update(i / l, 1);
            }
            S[i] = c;
        }
        else
        {
            int l, r;
            char buf[32];
            RD(l, r, buf);
            l--, r--;
            int len = strlen(buf);
            int ans = 0;
            for(int i: RG(len))
            {
                if(l + i > r)break;
                int m = (l + i) % len;
                ans += bit[c2i(buf[i])][len][m].query((l + i) / len, (r - (l + i)) / len + (l + i) / len + 1);
            }

            WTL(ans);
        }
    }
}