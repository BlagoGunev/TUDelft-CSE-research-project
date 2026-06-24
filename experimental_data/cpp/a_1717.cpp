// The code snippet of Rain Sure

#pragma GCC optimize(2)

#pragma GCC optimize(3)

#include<iostream>

#include<cstring>

#include<algorithm>

#include<vector>

#include<queue>

#include<set>

#include<map>

#include<unordered_map>

#include<unordered_set>

using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);

#define x first

#define y second

#define int long long

#define endl '\n' 

const int inf = 1e9 + 10;

const int maxn = 100010, M = 2000010;

const int mod = 1e9 + 7;

typedef pair<int,int> PII;

typedef long long LL;

typedef unsigned long long ULL;

typedef long double LD;

int h[maxn], e[M], w[M], ne[M], idx;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int cnt;

void add(int a, int b, int c)

{

    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;

}

void add(int a, int b)

{

    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;

}

int qmi(int a,int b){int res=1%mod; a%=mod;while(b) { if(b&1) res=res*a%mod; a=a*a%mod;b>>=1;}return res;}

int gcd(int a,int b) { return b?gcd(b,a%b):a;}

// head

signed main()

{

    IOS;

    int _; cin >> _;

    while(_ -- ) {

        int n; cin >> n;

        int res = n;

        res += n / 2 * 2;

        res += n / 3 * 2;

        cout << res << "\n";

    }

    return 0;

}