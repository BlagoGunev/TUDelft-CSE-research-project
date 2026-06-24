#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <algorithm>
// #include <sstream>
// #include <fstream>
// #include <math.h>
// #include <thread>
// #include <chrono>
// #include <memory>
// #include <exception>

#include <string>
#include <array>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

using LL = long long;
using VI = vector<int>;
using VC = vector<char>;
using VL = vector<LL>;
using Coord = std::pair<int, int>;

#define YES cout << "YES\n"
#define NO cout << "NO\n"

const int MAX_N = 52;
int n;
int a[MAX_N];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (a[n-1] == a[0]) {
        NO;
        return;
    }
    YES;
    cout << a[n-1] << " " << a[0] << " ";
    for (int i = n-2; i > 0; i--) {
        cout << a[i] << " ";
    }   cout << endl;
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;    // no. test cases
    while (t--)
        solve();
    return 0;
}