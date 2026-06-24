/*

 * File created on 02/02/2023 at 19:12:31.

 * Link to problem: 

 * Description: 

 * Time complexity: O()

 * Space complexity: O()

 * Status: ---

 * Copyright: Ⓒ 2023 Francois Vogel

*/



#include <bits/stdc++.h>



#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace __gnu_pbds;



#define pii pair<int, int>

#define f first

#define s second



#define vi vector<int>

#define all(x) x.begin(), x.end()

#define sz(x) (int)((x).size())

#define pb push_back

#define ins insert

#define cls clear



#define int ll

#define ll long long

#define ld long double



typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;



const int siz = 3e5+40;



int sieve [siz];



signed main() {

    cin.tie(0);

    ios_base::sync_with_stdio(0);



    for (int i = 0; i < siz; i++) sieve[i] = i;

    for (int i = 2; i < siz; i++) if (sieve[i] == i) for (int j = 2*i; j < siz; j += i) if (sieve[j] == j) sieve[j] = i;



    int n;

    cin >> n;

    int b [n];

    for (int i = 0; i < n; i++) cin >> b[i];

    int maxElem = 0;

    for (int i = 0; i < n; i++) maxElem = max(maxElem, b[i]);

    int S, T;

    cin >> S >> T;

    S--; T--;

    swap(S, T);

    map<int, int> primes;

    for (int i = 2; i <= maxElem; i++) if (sieve[i] == i) primes[i] = sz(primes);

    vi graph [n+sz(primes)];

    for (int i = 0; i < n; i++) {

        vi primeDivs;

        int x = b[i];

        while (x >= 2) {

            int smallestPrimeDivisor = sieve[x];

            while (x%smallestPrimeDivisor == 0) x /= smallestPrimeDivisor;

            primeDivs.pb(smallestPrimeDivisor);

        }

        for (int j : primeDivs) {

            int idx = primes[j];

            graph[i].pb(n+idx);

            graph[n+idx].pb(i);

        }

    }

    int dist [n+sz(primes)];

    for (int i = 0; i < n+sz(primes); i++) dist[i] = -1;

    int from [n+sz(primes)];

    queue<int> q;

    q.push(S);

    dist[S] = 0;

    while (!q.empty()) {

        int x = q.front();

        q.pop();

        for (int y : graph[x]) {

            if (dist[y] == -1) {

                dist[y] = dist[x]+1;

                from[y] = x;

                q.push(y);

            }

        }

    }

    if (dist[T] == -1) {

        cout << -1;

        return 0;

    }

    cout << dist[T]/2+1 << '\n';

    int x = T;

    while (x != S) {

        cout << x+1 << ' ';

        x = from[x];

        x = from[x]; // do this twice to skip prime

    }

    cout << S+1 << '\n';



    cout.flush();

    int d = 0;

    d++;

}