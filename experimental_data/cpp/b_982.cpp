#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <functional>
#include <list>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <bitset>
#include <unordered_map>

using namespace std;

#define pi 3.14159265358979323846
#define pb push_back
#define mp make_pair
#define endl "\n"
#define pll pair<ll, ll>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define repo(i,n) for(int i = 1; i < n; ++i)
#define y second
#define x first

typedef unsigned long long ull;
typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

bool isprime(ll p) {
    if (p < 2) return false;
    if (p == 2) return true;
    if (p % 2 == 0) return false;

    double limit = sqrt(p);

    for (ll i = 3; i <= limit; i += 2) {
        if ((p % i) == 0) return false;
    }

    return true;
}

ll fac(ll n) {
    ll an = 1;
    while (n > 1)
    {
        an *= n;
        n--;
    }
    return an;
}

ll kor(ll n, ll st) {
    ll res = 1;
    while (st) {
        if (st & 1)
            res *= n;
        n *= n;
        st >>= 1;
    }
    return res;
}

#define NMAX 1000000009
#define N 5000

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>> w(n);
    rep(i, n) {
        cin >> w[i].first;
        w[i].second = i;
    }
    sort(w.begin(), w.end());
    string s;
    cin >> s;
    stack<int> gr;
    int ls = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '0'){
            gr.push(ls);
            cout << w[ls].second + 1 << " ";
            ls++;
        }
        else{
            int place = gr.top();
            cout << w[place].second + 1 << " ";
            gr.pop();
        }
    }
    return 0;
}