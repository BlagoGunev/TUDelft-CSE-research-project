#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

#define INPUT "input.txt"
#define OUTPUT "output.txt"

#ifndef HOME
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
#define FILES freopen(INPUT,"r",stdin); freopen(OUTPUT,"w",stdout);
#define debug(...)
#define __DEBUG if (0) {
#define DEBUG__ }
#define cerr if (0) cerr
#else //HOME
#define FASTIO
#define debug(...) printf("$"); printf(__VA_ARGS__)
#define cerr cerr << '$'
#define __DEBUG
#define DEBUG__
#endif // HOME

#define YN(ans) cout << ((ans) ? "YES" : "NO") << endl

#define forn(i,n)    for (int (i) = 0; (i)<(int)(n); ++(i))
#define fornd(i,n)   for (int (i) = (int)(n-1); (i) >= 0; --(i))
#define forkn(i,k,n) for (int (i) = (int)(k); (i)<(int)(n); ++(i))
#define forv(i,container)    for (auto (i) : (container))
#define itout(container)    cout << "\n$"; for (auto _it : (container)) cout << _it << ' ';

typedef long double ld;
typedef long long ll;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;

typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<ld> vld;
typedef vector<pld> vpld;

typedef vector<vi> graph;
typedef vector<vpii> wgraph;

#define MAXN 520400
#define MAXM ll(1e16)
#define INF 2000000000
#define INFLL 2000000000000000000LL
#define MOD 1000000007
#define HASHMOD 793877113
#define SQRT 320
#define ALPH 26
#define PI 3.141592653589
#define EPS 1e-9

string s[MAXN];
int len[MAXN];

int main()
{
    FASTIO

    int n;
    cin >> n;

    forn(i,n)
    {
        cin.ignore(1,'#');
        getline(cin,s[i]);
    }
    len[n-1] = s[n-1].size();
    for (int i = n-2; i >= 0; --i)
    {
        bool ans = 0;
        len[i] = s[i].size();
        forn(j,min(len[i], len[i+1]))
        {
            if (s[i][j] == s[i+1][j])
                continue;
            if (s[i][j] < s[i+1][j])
            {
                len[i] = s[i].size();
                ans = 1;
                break;
            }
            if (s[i][j] > s[i+1][j])
            {
                len[i] = j;
                ans = 1;
                break;
            }
        }
        if (!ans)
            len[i] = min(len[i], len[i+1]);
    }
    forn(i,n)
    {
        cout << '#';
        forn(j,len[i])
            cout << s[i][j];
        cout << endl;
    }
}