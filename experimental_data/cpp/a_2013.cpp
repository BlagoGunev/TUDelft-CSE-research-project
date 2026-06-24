#include <cstdlib>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <climits>
using namespace std;

using ll = long long;
using db = long double;
using str = string; // yay python!

template <typename T>
using ve = vector<T>;
template <typename T, unsigned sz>
using ar = array<T, sz>;
using ii = pair<int, int>;

#define A(x) begin(x), end(x)
#define ShinLena cin.tie(nullptr)->sync_with_stdio(false);
#define N 200005



int main()
{
    ShinLena;
    int t;
    cin >> t;
    while (t--) {
      int n,x,y;cin>>n>>x>>y;
      x=min(x,y);
      cout<<(n+x-1)/x<<'\n';
    }
    return 0;
}