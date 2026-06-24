#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>
#include <ctime>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <tuple>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define int long long

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

#define mp make_pair
#define mt make_tuple
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define all(x) x.begin(), x.end()
#define get0 get<0>
#define get1 get<1>
#define get2 get<2>

typedef long long ll;
typedef long double ld;
typedef tuple<long long, long long, long long> tlll;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int INF = 1e9 + 7;
const int SZ = 1e5 + 1;

int f(int n)
{
    vector<int> a = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341};
    if (n < a.size())
        return a[n];
    else
        return a[12] + 49 * (n - 12);
}

int32_t main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /*
    int p = 0;
    for (int i = 1; i < 20; i++)
    {
        unordered_set<int> s;
        for (int k = 0; k <= i; k++)
        {
            for (int j = 0; j <= i; j++)
            {
                for (int l = 0; l <= i; l++)
                {
                    for (int m = 0; m <= i; m++)
                    {
                        if (k + j + l + m == i)
                            s.insert(50 * k + 10 * j + 5 * l + m);
                    }
                }
            }
        }
        cout << i << ' ' << s.size() << ' ' << f(i) << endl;;
    }
    */
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}