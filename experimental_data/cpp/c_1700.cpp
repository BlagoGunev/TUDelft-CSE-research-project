#pragma once



#include <stack>

#include <iostream>

#include <functional>

#include <algorithm>

#include <iterator>

#include <iomanip>

#include <chrono>

#include <cmath>

#include <list>

#include <set>

#include <map>

#include <queue>

#include <random>

#include <sstream>

#include <memory.h>

#include <string>

#include <deque>

#include <unordered_map>





#define even % 2 == 0

#define odd % 2 == 1

#define ln '\n'

typedef long long ll;

typedef long double ld;

typedef std::pair<ll, ll> pll;

typedef std::map<ll, ll> mll;

typedef std::vector<ll> vl;

const ll template_array_size = 1e6;

const ll INF = 9223372036854775807;

const ld PI = acosl(-1.0);

const ll MOD = 1e9 + 7;

//ll a[template_array_size];

//ll b[template_array_size];

//ll c[template_array_size];



using namespace std;





//bool visited[400005];

const ll N = 4*1e5+100;



//vector<pair<ll, ll>> edges[500005];

//vector<ll> edges[N];



//bool visited[1005][1005];





ll n;

ll arr[300005];



void solve() {

    cin >> n;

    for (int i = 0; i < n; ++i) {

        cin >> arr[i];

    }



    ll pref = 0, suf = 0;

    ll mn = arr[0];



    for (int i = 1; i < n; ++i) {

        ll x = arr[i] - suf;



        if (x >= mn) {

            suf += (x - mn);

        } else {

            pref += (mn - x);

            mn = x;

        }

    }



    cout << abs(mn) + pref + suf << ln;

}







int main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0); cout.tie(0);



    //    freopen("input.txt","r",stdin);

    //    freopen("output.txt","w",stdout);



    //    srand(time(NULL));

    int T = 1;

    cin >> T;

    while (T--) {

        solve();

    }

    return 0;

}