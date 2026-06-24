// Problem: A. Создание слов
// Contest: Codeforces - Codeforces Round 952 (Div. 4)
// URL: https://codeforces.com/contest/1985/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                  Solution
//                    Webbly, 27.01.2023
//
//
//                    Arsen ne katai
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include<bits/stdc++.h>

/**
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <time.h>
*/
//#pragma GCC optimize("O3")
//#pragma GCC optimize("fast-loops")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
/**
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC target("avx")
*/
#define ll long long
#define kebzaro ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define flush cout.flush()

using namespace std;

const ll mod = (ll)1e9 + 7, mod3 = 998244353, inf = (ll)2e15, P = 31;

void judge(string name){
	if (name.size()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + "out").c_str(), "w", stdout);
	}
}

ll rnd(){
    ll x = rand();

    return rand() ^ x;
}

ll binpow (ll a, ll b){
    ll ans = 1;
    while(b){
        if (b & 1){
            ans *= a;

            ans %= mod;
        }

        b >>= 1;
        a *= a;

        a %= mod;
    }
    return ans;
}
ll gcd(ll a, ll b){
    return (b ? gcd(b, a % b) : a);
}
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

struct tr{
    ll four, seven, inc, dec;
};

struct T{
    ll l, r, val, ind;
};

ll n, m, k, a[500005], b[500005], p[500005];

string s, t;

void sarsen(){
    cin >> s >> t;
    
    swap(s[0], t[0]);
    
    cout << s << ' ' << t << '\n';
}

int main(){
    kebzaro

    judge("");

    ll TT = 1, tests = 1;

    cin >> TT;

    while(TT--){
        //cout << "Case " << tests << ": ";

        sarsen();

        //tests++;
    }

    return 0;
}
/**



*/