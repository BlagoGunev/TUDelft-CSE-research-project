#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
template <typename T>
class fenwick {
public:
    vector<T> fenw;
    int n;
    
    fenwick(int _n) : n(_n) {
        fenw.resize(n);
    }
    
    void modify(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x |= (x + 1);
        }
    }
    
    T get(int x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
    
    T get(int l, int r) {
        T ret = get(r);
        if (l>0) ret -= get(l-1);
        return ret;
    }
};
const int A = 500500;
fenwick<int> fen(A);
set<pi> s;
multiset<pi> del;
multiset<pi> add;

void go() {
    vpi pr;
    for(auto x : del) if(add.find(x) != add.end()) {
        pr.pb(x);
        add.erase(add.find(x));
    }
    for(auto x  : pr) del.erase(del.find(x));
    printf("%d\n", del.size());
    for(auto x : del) printf("%d %d\n", x.first, x.second);
    printf("%d\n", add.size());
    for(auto x : add) printf("%d %d\n", x.first, x.second);
    add.clear();
    del.clear();
}

int get(int k) {
    return fen.get(k, k);
}

void kill0(int l, int r, int num) {
    if(num == 0) return;
    s.erase(mp(l,r));
    del.insert(mp(l,r));
    if(get(l) == 0) {
        if(l<r) {
            add.insert(mp(l+1,r));
            s.insert(mp(l+1,r));
            kill0(l+1,r,num-1);
        }
        return;
    }
    int fl = l;
    int fr = r;
    while(fr - fl > 1) {
        int fm = (fl+fr)/2;
        int tot = fm - l + 1;
        int o = fen.get(l, fm);
        int z = tot - o;
        if(o-z >= 0) fl = fm;
        else fr = fm;
    }
    add.insert(mp(l, fl));
    s.insert(mp(l, fl));
    if(fr < r) {
        add.insert(mp(fr+1, r));
        s.insert(mp(fr+1, r));
        kill0(fr+1,r,num-1);
    }
}

void add0(int l, int r, int num) {
    if(num == 0) return;
    auto it = s.lower_bound(mp(r+1, r+1));
    del.insert(mp(l,r));
    if(it != s.end() && it->first == r+1) {
        int r2 = it->second;
        del.insert(*it);
        add.insert(mp(l, r2));
        s.erase(it);
        s.erase(mp(l,r));
        s.insert(mp(l,r2));
        add0(l,r2,num);
    }
    else {
        add.insert(mp(l,r+1));
        s.erase(mp(l,r));
        s.insert(mp(l,r+1));
        add0(l,r+1,num-1);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    while(n--) {
        int k;
        read(k);
        if(fen.get(k, k) == 1) {
            auto it = s.lower_bound(mp(k+1, k+1));
            it--;
            fen.modify(k, -1);
            kill0(it->first, it->second, 2);
        }
        else {
            auto it = s.lower_bound(mp(k+1, k+1));
            fen.modify(k, 1);
            if(it == s.begin()) {
                s.insert(mp(k,k));
                add.insert(mp(k,k));
                add0(k, k, 1);
            }
            else {
                it--;
                if(it->second < k) {
                    s.insert(mp(k,k));
                    add.insert(mp(k,k));
                    add0(k, k, 1);
                }
                else {
                    add0(it->first, it->second, 2);
                }
            }
        }
        go();
    }
    
    
    
    
}