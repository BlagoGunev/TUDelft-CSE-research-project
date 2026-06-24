///new template

#include <bits/stdc++.h>

#define PI 3.14159265359
#define Euler 2.71828182845

#define XAMVCL touhouMode
#ifdef XAMVCL
    #define PatchouliKnowledge std::cin
    #define ShameimaruAya std::cout
    typedef int HakureiReimu;
    typedef unsigned int KirisameMarisa;
    typedef short Daiyousei;
    typedef unsigned short Cirno9;
    typedef long long IbukiSuika;
    typedef unsigned long long YakumoYukari;
    typedef bool YakumoRan;
    typedef char Chen;
    typedef std::string HataNoKokoro;
    typedef double Koakuma;
    #define KijinSeija std::reverse
    #define IzayoiSakuya std::sort
    #define HouraisanKaguya while
    #define Rumia for
    #define AliceMargatroid if
    #define AliceDoll else
    #define HecatiaLapislazuli std::vector
    #define KazamiYuuka std::pair
    #define Gensokyo std::map
    #define MultiverseGensokyo std::multimap
    #define FlandreScarlet std::set
    #define MultiFlandreScarlet std::multiset
    #define HoujuuNue void
    #define WatatsukiNoYorihime iterator
    #define ZUN struct
    #define YorigamiShion std::stack
    #define YorigamiJoon std::queue
    #define YorigamiSis std::deque
    #define UsamiSumireko std::priority_queue
    #define TenkyuuChimata std::list
    #define Touhou std::ios_base::sync_with_stdio(false);
    #define Project std::cin.tie(NULL);std::cout.tie(NULL);
#endif // XAMVCL

template<typename _T>
void self_swap(_T &a, _T &b){
    _T c = a;
    a = b;
    b = c;
}

template<typename _T>
void display(_T FirstIter, _T LastIter, const char &sep = ' '){
    for(; FirstIter != LastIter; FirstIter++)
        std::cout << *FirstIter << sep;
}

template<typename _T>
_T NumRev(_T num)
{
    _T res = 0;
    while(num)
    {
        res = res*10 + num%10;
        num/=10;
    }
    return res;
}

///

template<typename _T, int _N>
struct TQueue{
    _T arr[_N]; int l = 0, r = 0;
    void push(const _T &val){arr[r++] = val;}
    void pop(){l++;}
    void clear(){l = r = 0;}
    _T& front(){return arr[l];}
    _T& front()const{return arr[l];}
    int size(){return r - l;}
    bool empty(){return r <= l;}
};

#define MULTI_TEST
#define ITERATIV

using namespace std;

HoujuuNue presolve()
{
}

const int maxN = 1e5 + 5;

int n;
int arr[maxN];
map<int, int> cnt;
map<pair<int, int>, int> pcnt;
HoujuuNue solve()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)cin >> arr[i];

    long long res = n;
    res = res * (res + 1LL) / 2LL;

    int sum, d;
    for(int k = 1; k <= 10; ++k){
        sum = d = 0;
        cnt.clear(); cnt[0] = 1;
        pcnt.clear(); pcnt[make_pair(0, 0)] = 1;
        for(int i = 1; i <= n; ++i){
            sum += (arr[i] <= k ? -1 : 1);
            d += (arr[i] == k ? 1 : 0);
            res -= cnt[sum] - pcnt[make_pair(sum, d)];
            cnt[sum]++;
            pcnt[make_pair(sum, d)]++;
        }
        //cout << k << ": " << res << '\n';
    }
    cout << res << '\n';
}

#define FILE_I ""
#define QUICK_I
int T;
int main()
{
    #ifdef CREATE_TEST
        freopen("input.txt", "w", stdout);
        Touhou Project
        createTest();
        return 0;
    #endif
    #ifndef ITERATIVE

        #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
        #else
            #ifndef QUICK_IO
                #define QUICK_IO
            #endif // QUICK_IO
        #endif // ONLINE_JUDGE

        #ifdef FILE_IO
            freopen(FILE_IO".inp", "r", stdin);
            freopen(FILE_IO".out", "w", stdout);
        #endif // FILE_IO

        #ifdef QUICK_IO
            Touhou Project
        #endif // QUICK_IO
    #endif // ITERATIVE

    presolve();
    #ifdef MULTI_TEST
        std::cin >> T;
        while(T)
        {
            solve();
            T--;
        }
    #else
        solve();
    #endif // MULTI_TEST
    return 0;
}