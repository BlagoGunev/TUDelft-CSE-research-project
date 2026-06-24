#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <stack>
#include <sstream>

typedef long long int64;
typedef long long li;
typedef long double ld;

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forb(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fr first
#define sc second
#define in insert
#define mp make_pair
#define pb push_back

const li INF = 1000000007;

int main ()
{
    int n;
    cin >> n;
    vector<vector<int> > t(2);
    li sum = 0;
    forn(i, n)
    {
        int tmp;
        cin >> tmp;
        t[tmp % 2].pb(-tmp);
        sum += tmp;
    }
    sort(t[0].begin(), t[0].end());
    sort(t[1].begin(), t[1].end());
    n = min(t[0].size(), t[1].size());
    forn(i, n)
    {
        sum += t[0][i] + t[1][i];
    }
    if (t[0].size() != t[1].size())
    {
        if (t[0].size() > t[1].size())
            sum += t[0][n];
        else
            sum += t[1][n];
    }
    cout << sum;
    return 0;
}