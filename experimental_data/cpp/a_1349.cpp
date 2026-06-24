#include <iostream>

#include <vector>

#include <set>

#include <unordered_map>

#include <unordered_set>

#include <map>

#include <stack>

#include <queue>

#include <deque>

#include <algorithm>

#include <numeric>

#include <math.h>

#include <cstring>

#include <time.h>

#include <chrono>

#include <random>

#include <ctime>

#include <iomanip>

using namespace std;

#define gc getchar_unlocked

#define fo(i, n) for (i = 0; i < n; i++)

#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)

#define ll long long

#define deb(x) cout << #x << "=" << x << endl

#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

#define pb push_back

#define mp make_pair

#define ff second

#define ss first

#define all(x) x.begin(), x.end()

#define clr(x) memset(x, 0, sizeof(x))

#define sortall(x) sort(all(x))

#define tr(it, arr) for (auto it = arr.begin(); it != arr.end(); it++)

#define PI 3.1415926535897932384626

typedef pair<int, int> pii;

typedef pair<ll, ll> pl;

typedef vector<int> vi;

typedef vector<ll> vl;

typedef vector<pii> vpii;

typedef vector<pl> vpl;

typedef vector<vi> vvi;

typedef vector<vl> vvl;

const double pi = 3.141592653589793238;

const ll mod = 1e9+7;

bool comp2(pair<ll, ll> &arr, pair<ll, ll> &b)

{

    if(arr.first == b.first) return arr.second<b.second;

    return arr.first<b.first;

};



template<typename T> void read(T i, T n, vector<T> &arr)

{

    for (T j = i; j < n; j++)

        cin >> arr[j];

}



void solve()

{

    ll n;

    cin>>n;

    vl arr(n);

    read(0ll, n, arr);

    vl suffix(n);

    suffix[n-1] = arr[n-1];

    for(int i = n-2; i>=0; i--) suffix[i] = __gcd(arr[i], suffix[i+1]);

    ll ans = (arr[0] * suffix[1]) / __gcd(arr[0], suffix[1]);

    // deb(ans);

    for(int i = 2; i < n - 1; i++) {

        ans = __gcd(ans, (arr[i] * suffix[i+1]) / __gcd(arr[i], suffix[i+1]));

    }

    cout<<ans<<endl;

}



int main()

{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t=1;

    // cin >> t;

    while (t--)

    {

        solve();

    }

    return 0;

}