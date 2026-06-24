#include <algorithm>

#include <array>

#include <cmath>

#include <cstring>

#include <chrono>

#include <iostream>

#include <iomanip> 

#include <queue>

#include <map>

#include <numeric>

#include <random>

#include <set>

#include <stack>

#include <string>

#include <utility>

#include <vector>



#define endl '\n'

#define all(x) x.begin(), x.end()

#define fora(a, b, c) for (int i = a; i < b; i += c)

#define forr(a, b, c) for (int i = a; i >= b; i -= c)

#define yes cout << "YES" << endl;

#define no cout << "NO" << endl;

#define cout0 cout << 0 << endl;

#define cout1 cout << -1 << endl;



typedef long long ll;

#define pi std::pair<int, int>

#define pll std::pair<ll, ll>

typedef std::vector<bool> vb;

typedef std::vector<vb> vvb;

typedef std::vector<int> vi;

typedef std::vector<vi> vvi;

typedef std::vector<pi> vpi;

typedef std::vector<ll> vll;

typedef std::vector<pll> vpll;

typedef std::vector<vll> vvll;

typedef std::vector<std::string> vs;

typedef std::vector<vs> vvs;



using namespace std;



void solve() {

    int n, r, k, c, i, j;

    cin >> n >> k >> r >> c;

    r--, c--;

    vvb as(n, vb(n));

    int limit = n / k;

    for (i = 0; i < limit; i++, (c += k) %= n) {

        for (j = 0; j < n; j++) {

            as[r][c] = true;

            (r += 1) %= n;

            (c += 1) %= n;

        }

    }

    for (i = 0; i < n; i++) {

        for (j = 0; j < n; j++) {

            if (as[i][j]) cout << "X";

            else cout << ".";

        }

        cout << endl;

    }

}



int main() {

    std::ios::sync_with_stdio(false);

    std::cin.tie(nullptr);

    cout << setprecision(15);

    int t;

    cin >> t;

    while (t--) solve();

}