//-----------------------------------
// Le Truong Quoc Thang
// UVA:
//-----------------------------------

#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define fr(i, a, b) for (int i = a; i <= b; i++)

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ii pair <int, int>
#define ll long long
#define INF 2000000000
#define maxE 10005
#define maxV 1005
#define maxN 1005

int c1, c2, c3, c4;
int n, m;
int a[maxN], b[maxN];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("B.INP", "r", stdin);
    freopen("B.OUT", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d %d %d %d", &c1, &c2, &c3, &c4);
    scanf("%d %d", &n, &m);
    rep(i, n) scanf("%d", &a[i]);
    rep(i, m) scanf("%d", &b[i]);
    int cost1 = 0, cost2 = 0;
    rep(i, n){
        cost1 += min(a[i]*c1, c2);
    }
    cost1 = min(cost1, c3);
    rep(i, m){
        cost2 += min(b[i]*c1, c2);
    }

    cost2 = min(cost2, c3);
    int cost = min(cost1 + cost2, c4);
    printf("%d\n", cost);

    return 0;
}