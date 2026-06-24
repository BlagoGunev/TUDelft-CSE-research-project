#include <unordered_map>

#include <algorithm>

#include <iostream>

#include <fstream>

#include <utility>

#include <iomanip>

#include <string>

#include <math.h>

#include <vector>

#include <cmath>

#include <ctime>

#include <queue>

#include <stack>

#include <map>

#include <set>

#define F first

#define S second

#define PB push_back

#define PPB pop_back

#define MP make_pair

#define LL long long

#define INF (int)1e9 + 7

#define sz(a) (int)a.size()

#define PII pair <int, int>

#define ULL unsigned long long

using namespace std;



LL ans;

int n, x, cur = 1, l[51], r[51];



int main () {

    cin >> n >> x;

    for (int i = 1;i <= n; i++)

        cin >> l[i] >> r[i];

    for (int i = 1;i <= n; i++) {

        ans += (l[i] - cur) % x + r[i] - l[i] + 1;

        cur = r[i] + 1;

    }

    cout << ans;

    return 0;

}