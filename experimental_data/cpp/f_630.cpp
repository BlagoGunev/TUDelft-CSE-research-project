#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <bitset>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#define PI acos(-1.0)
#define eps 1e-8
#define inf 0x3f3f3f3f
#define sqr(x) (x)*(x)
#define debug(x) cout<<"--- "<<x<<" ---"<<endl
typedef unsigned long long ll;
using namespace std;

int main()
{
    ll n;
    while (~scanf("%llu", &n))
    {
        ll a = n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4) / 5;
        ll b = n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4) / 5 * (n - 5) / 6;
        ll c = n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4) / 5 * (n - 5) / 6 * (n - 6) / 7;
        printf("%llu\n", a + b + c);
    }
    return 0;
}