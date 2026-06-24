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



int n, ans;



int main () {

    cin >> n;

    ans += n / 4;

    if (n % 2)

        cout << 0;

    else if (n % 4 == 0)

        cout << ans - 1;

    else

        cout << ans;

    return 0;

}