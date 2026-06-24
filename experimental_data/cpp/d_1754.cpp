#include <iostream>

#include <cstdio>

#include <fstream>

#include <iomanip>

#include <algorithm>

#include <cmath>

#include <deque>

#include <vector>

#include <queue>

#include <string>

#include <cstring>

#include <map>

#include <stack>

#include<list>

#include <set>

#include <ctime>

#include<unordered_map>

#include <bitset>

#include<random>

#include<regex>

#include <chrono>

#include <random>



using namespace std;

typedef long long ll;

#define  int  long long 

#define endl "\n"

#define pb push_back

#define pr pair<int,int>

#define all(a) a.begin(),a.end()

#define fr first

#define se second

#define mk make_pair

#define lowbit(x) x&(-x)

const int N = 5e5 + 57;

const int mod = 998244353;

const int maxx = 2e3 + 7;





int a[N];

int vis[N];

int mi=1e9;

int ma;



inline void solve()

{

    int n, x;

    cin >> n >> x;

    for (int i = 1; i <= n; i++) {

        int v;

        cin >> v;

        a[v]++;

    }

    for (int i = 1; i <x; i++)

    {

        if (a[i] % (i + 1) != 0) {

            cout << "No" << endl;

            return;

        }

        a[i + 1] += a[i] / (i + 1);

    }

    cout << "Yes" << endl;

}







signed main() {

    cin.sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    solve();

}

/*

1

7 7

0 1 0 1 0 1 0

1 7

3 6

2 5

1 4

4 7

2 6

2 7

*/