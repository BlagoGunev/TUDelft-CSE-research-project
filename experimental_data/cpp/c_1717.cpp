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

    int n, i;

    cin >> n;

    vector<int> as(n), bs(n);

    for (i = 0; i < n; i++) cin >> as[i];

    for (i = 0; i < n; i++) cin >> bs[i];

    for (i = 1; i < n; i++) {

        if (as[i - 1] != bs[i - 1] && bs[i - 1] - 1 > bs[i] || as[i - 1] > bs[i - 1]) {

            no return;

        }

    }

    if (as[n - 1] != bs[n - 1] && bs[0] + 1 < bs[n - 1] || as[n - 1] > bs[n - 1]) no

    else yes

}



int main() {

    std::ios::sync_with_stdio(false);

    std::cin.tie(nullptr);

    cout << setprecision(15);

    int t;

    cin >> t;

    while (t--) solve();

}