/*
 
Sviatoslav Bidzilia 2020
CF: anakib1
 
*/
 
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <map>
#include <chrono>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <ctime>
#include <stack>
#include <functional>
#include <set>
#include <list>
#include <deque>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <stdarg.h>
#include <utility>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define all(a) a.begin(), a.end()
#define SORT(a) sort(all(a))
#define pii pair<int, int>
#define tii triple<int, int, int>
#define sz(x) (int)(x.size())
#define e 1e-7
#define PI acos(-1)
#define inf 1e17
#define vi vector<int>
#define F first
#define S second
#define rng(x) for(int _ = 0; _ < (x); _++)
#define rngi(i, x) for(int i = 0; i < (x); i++)
#define rngsi(s, i, x) for(int i = (s); i <(x); i++)
#define int long long
 
template<typename A, typename B, typename C>
struct triple
{
    A X;
    B Y;
    C Z;
    triple(A a = 0, B b = 0, C c = 0) :X(a), Y(b), Z(c) {}
};
template<typename A, typename B, typename C>
triple<A, B, C> make_triple(A a = 0, B b = 0, C c = 0)
{
    return triple<A, B, C>(a, b, c);
}
template<typename A, typename B, typename C>
bool operator<(const triple<A, B, C>& a, const triple<A, B, C>& b)
{
    if (a.X != b.X)
        return a.X < b.X;
    if (a.Y != b.Y)
        return a.Y < b.Y;
    return a.Z < b.Z;
}
template<typename T, typename SS>
ostream& operator<<(ostream& ofs, const pair<T, SS>& p)
{
    ofs << "( " << p.F << " , " << p.S << " )";
    return ofs;
}
template<typename T>
void print(T a)
{
    for (auto i : a)
        cout << i << ' ';
    cout << '\n';
}
template<typename T>
T max(T a, T b, T c)
{
    return max(a, max(b, c));
}
template<typename T>
T min(T a, T b, T c)
{
    return min(a, min(b, c));
}
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
signed main()
{
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    srand(time(NULL));
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    rng(t){
        int a, b; cin >> a >> b;
        int d = max(2 * a, b);
        d = min(d, max(2 * b, a));
        cout << d * d << '\n';
    }
    
}
//check corner case (interactives!)
//check n=1 or n=2
//check size of arrays
//more asserts
//scanf printf
//read everything normaly