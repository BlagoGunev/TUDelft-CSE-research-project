#include <algorithm>

#include <iostream>

#include <vector>

#include <fstream>

#include <string>

#include <deque>

#include <iomanip>

#include <tuple>

#include <cmath>

#include <map>

#include <set>

#include <unordered_map>

#include <unordered_set>

#include <cstdlib>

#include <cassert>

#include <random>

#include <ctime>



using namespace std;



typedef long long ll;

typedef long double ld;



const int inf = 1e9;



ll gcd(ll a, ll b) {

    if (b == 0) return a;

    return gcd(b, a % b);

}



ll sum(ll n) {

    ll ans = 0;

    while (n) {

        ans += n % 10;

        n /= 10;

    }

    return ans;

}



void solve() {

    ll n;

    cin >> n;

    while (gcd(n, sum(n)) <= 1) n++;

    cout << n << '\n';

}



int main() {

    //freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);



    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    

    int t;

    cin >> t;

    for (int i = 0; i < t; i++) solve();

}