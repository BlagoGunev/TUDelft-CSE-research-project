#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <fstream>
#include <unordered_map>

#define endl "\n"
#define c0 ios_base :: sync_with_stdio(0); cin.tie (0);
#define s second
#define f first
#define ll long long
#define ull unsigned ll
#define Name ""
using namespace std;

const int MaxN = 2e5 + 17;
const ll INF = 1e9 + 17;
const int MOD = 1e9 + 7;
const double eps = 1e-8;
const double pi = 3.14159265359;

string s;
vector < char > v;
inline bool check (char a)
{
    if (a != 'a' && a != 'e' && a != 'i' && a != 'o'  && a != 'u')
        return true;
    return false;
}
int main() {
    #ifdef DEBUG
        freopen (Name".in", "r", stdin);
        freopen (Name".out", "w", stdout);
    #endif
    c0
    cin >> s;
    for (int i = 0; i < s.size(); ++ i)
    {
        if (v.size() < 2)
            v.push_back (s[i]);
        else
        {
            if (v[v.size() - 1] == s[i] && v[v.size() - 1] == v[v.size() - 2])
            {
                v.push_back (s[i]);
                continue;
            }
            if (check (v[v.size() - 1]) && check (v[v.size() - 2]) && check (s[i]))
            {
                for (int j = 0; j < v.size(); ++ j)
                    cout << v[j];
                cout << ' ';
                v.clear();
            }
            v.push_back (s[i]);
        }
    }
    for (int i = 0; i < v.size(); ++ i)
        cout << v[i];
    return 0;
}