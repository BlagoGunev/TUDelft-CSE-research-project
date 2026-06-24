#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define repi(i, a, b) for(int i=(a); i>(b); i--)
#define db(x) (cerr << #x << ": " << (x) << '\n')
#define sync ios_base::sync_with_stdio(false), cin.tie(NULL)
#define iceil(n, x) ((n + x - 1) / x)
#define ll long long
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define sz size()
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vi>
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define si(a) scanf("%d", &a)
#define sll(a) scanf("%lld", &a)
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC
#define PI acos(-1.0)
#define EPS 1e-9
#define mod 1000000007
#define MOD 1000000007
#define N 1005
using namespace std;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;

//All indexing is 0-based
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
			 tree_order_statistics_node_update> ordered_set;
//methods: find_by_order(k); & order_of_key(k);

inline int add(int a, int b, int p = mod){ ll c = a + b; if(c >= p) c -= p; return c;}
inline int sub(int a, int b, int p = mod){ int c = a - b; if(c < 0) c += p; return c;}
inline int mul(int a, int b, int p = mod){ return (a * 1ll * b) % p;}

char grid[N][N];
int C[N][N], R[N][N];

int dp[4][N][N]; //L, R, U, D

int mx[] = {0, 0, 1, -1};
int my[] = {-1, 1, 0, 0};

vi x, y, s;

main()
{	
	sync;
	#ifndef ONLINE_JUDGE
		freopen("/home/tarun/Desktop/input.txt", "r", stdin);
//		freopen("/home/tarun/Desktop/output.txt", "w", stdout);
	#endif
	
	clock_t clk = clock();
	cerr << "I will return...\n";
	
	int n, m; cin >> n >> m;
	rep(i, 0, n) rep(j, 0, m) cin >> grid[i][j];

	rep(i, 0, n) {
		rep(j, 0, m) {
			if(grid[i][j] == '.') continue;
			dp[0][i][j] = 1;
			dp[2][i][j] = 1;
			if(i) dp[2][i][j] += dp[2][i-1][j];
			if(j) dp[0][i][j] += dp[0][i][j-1];
		}
	}

	repi(i, n-1, -1) {
		repi(j, m-1, -1) {
			if(grid[i][j] == '.') continue;
			dp[3][i][j] = 1;
			dp[1][i][j] = 1;
			if(i < n - 1) dp[3][i][j] += dp[3][i + 1][j];
			if(j < m - 1) dp[1][i][j] += dp[1][i][j + 1];
		}
	}

	rep(i, 0, n) {
		rep(j, 0, m){
			if(grid[i][j] == '.') continue;
			int mn = 1000;
			rep(k, 0, 4) {
				int tmp = 0;
				/*int r = i, c = j;
				while(r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == '*') {
					r = r + mx[k], c += my[k];
					tmp ++;
				}
				//tmp--;*/
				tmp = dp[k][i][j];
				mn = min(mn, tmp);
			}
			if(mn == 1) continue;
			//isValid[i][j] = 1;

			x.pb(i + 1), y.pb(j + 1), s.pb(mn - 1);
			/*rep(k, 0, 4) {
				int r = i, c = j;
				rep(l, 0, mn - 1) {
					r += mx[k], c += my[k];
					isValid[r][c] = 1;
				}
			}*/
			C[max(0, i - (mn - 1))][j]++;
			C[min(n, i + (mn))][j]--;

			R[i][max(0, j - (mn - 1))]++;
			R[i][min(m, j + mn)]--;
		}
	}

	/*rep(i, 0, x.sz) {
		cout << x[i] << ' ' << y[i] << ' ' << s[i] << '\n';
	}*/


	rep(i, 0, n) rep(j, 0, m) {
		if(i) C[i][j] += C[i - 1][j];
		if(j) R[i][j] += R[i][j - 1];
	}

	rep(i, 0, n)  {
		rep(j, 0, m) {
			int t = C[i][j] + R[i][j];
			if(grid[i][j] == '*' && t <= 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << x.sz << '\n';
	rep(i, 0, x.sz) {
		cout << x[i] << ' ' << y[i] << ' ' << s[i] << '\n';
	}

	cerr << "...don't you ever hang your head.\n";
	cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << '\n';
}

//Compile using:
//g++ -o filename.exe --std=c++11 filename.cpp