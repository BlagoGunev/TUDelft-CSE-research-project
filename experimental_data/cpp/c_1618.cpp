#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS

/*--------------Define--------------*/
#define MOD 1000000007
#define INF 1000000000
#define cn const
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define sz size()
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))


/*--------------Include--------------*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <fstream>
#include <ostream>
#include <deque>
#include <iomanip>
#include <map>
#include <set>
#include <stack>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>
#include <sstream>

#define endl '\n'


using namespace std;


using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vs = vector<string>;
using vpii = vector<pii>;


template<typename T>
constexpr T sqr(const T& x)
{
    return x * x;
}

template<typename T>
bool rMin(T& v, const T& rval)
{
    if (rval < v) {
        v = rval;
        return true;
    }
    return false;
}

template<typename T>
bool rMax(T& v, const T& rval)
{
    if (v < rval) {
        v = rval;
        return true;
    }
    return false;
}

ll Ev(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return Ev(b, a % b);
}


void solve(vector<ll>& a, int n)
{
    ll gcd1 = a[0];
    for (int i = 2; i < n; i += 2)
    {
        gcd1 = Ev(gcd1, a[i]);
    }

    bool f1 = true;

    for (int i = 1; i < n; i += 2)
    {
        if (a[i] % gcd1 == 0)
        {
            f1 = false;
            break;
        }
    }

    if (f1)
    {
        cout << gcd1 << endl;
        return;
    }

    ll gcd2 = a[1];
    for (int i = 3; i < n; i += 2)
    {
        gcd2 = Ev(gcd2, a[i]);
    }

    bool f2 = true;

    for (int i = 0; i < n; i += 2)
    {
        if (a[i] % gcd2 == 0)
        {
            f2 = false;
            break;
        }
    }

    if (f2)
    {
        cout << gcd2 << endl;
        return;
    }

    cout << 0 << endl;
}



int main()
{
#ifdef _DEBUG
    freopen("Input.txt", "r", stdin);
#endif // _DEBUG


    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
    {
        int n;

        cin >> n;

        vector<ll> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solve(a, n);
    }



#ifdef _DEBUG
    cin.get();
#endif // _DEBUG

    return 0;
}