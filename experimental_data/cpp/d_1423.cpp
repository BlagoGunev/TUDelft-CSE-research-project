/*
$$$$$$$\                      $$\           $$$$$$$\
$$  __$$\                     \__|          $$  __$$\
$$ |  $$ | $$$$$$\   $$$$$$\  $$\  $$$$$$$\ $$ |  $$ | $$$$$$\   $$$$$$\   $$$$$$$\ $$$$$$\
$$$$$$$\ |$$  __$$\ $$  __$$\ $$ |$$  _____|$$$$$$$\ | \____$$\ $$  __$$\ $$  _____|\____$$\
$$  __$$\ $$ /  $$ |$$ |  \__|$$ |\$$$$$$\  $$  __$$\  $$$$$$$ |$$ |  \__|$$ /      $$$$$$$ |
$$ |  $$ |$$ |  $$ |$$ |      $$ | \____$$\ $$ |  $$ |$$  __$$ |$$ |      $$ |     $$  __$$ |
$$$$$$$  |\$$$$$$  |$$ |      $$ |$$$$$$$  |$$$$$$$  |\$$$$$$$ |$$ |      \$$$$$$$\\$$$$$$$ |
\_______/  \______/ \__|      \__|\_______/ \_______/  \_______|\__|       \_______|\_______|
*/
#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define INS insert
#define LB lower_bound
#define UB upper_bound
#define pii pair <int,int>
#define pll pair <long long, long long>
#define X first
#define Y second
#define _ << " " <<
#define sz(x) (int)x.size()
#define all(a) (a).begin(),(a).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, a, b) for (int i = (a); i > (b); --i)
#define FORA(i, x) for (auto &i : x)
#define REP(i, n) FOR(i, 0, n)
#define BITS(x) __builtin_popcount(x)
#define SQ(a) (a) * (a)
#define TRACE(x) cout << #x " = " << (x) << '\n';
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define umap unordered_map

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <pii> vpi;
typedef vector <ll> vll;
typedef vector <pll> vpl;
typedef vector <double> vd;
typedef vector <ld> vld;
typedef vector<string> vs;
//((float) t)/CLOCKS_PER_SEC

const int MOD = 1e9 + 7;
const double PI = acos(-1);
const int INF = 1e9 + 10;
const ll INFL = 1e18 + 10;
const int ABC = 30;
const int dx[] = {-1, 1, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0};
const int dox[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int doy[] = {0, 0, -1, 1, -1, 1, -1, 1};

inline int sum(int a, int b){
	if (a + b < 0)
		return (a + b + MOD) % MOD;
	return (a + b) % MOD;
}

inline void add(int &a, int b){
	a = sum(a, b);
}

inline int mul(ll a, ll b){
	return ((a % MOD) * ((ll)b % MOD)) % MOD;
}

inline int sub(int a, int b){
	return (a - b + MOD) % MOD;
}

inline int fast_pot(ll pot, ll n){
	ll ret = 1;
	while (n){
		if (n & 1LL)
			ret = (ret * pot) % MOD;
		pot = (pot * pot) % MOD;
		n >>= 1LL;
	}
	return ret;
}

inline int divide(int a, int b){
	return mul(a, fast_pot(b, MOD - 2));
}

ll lcm(ll a, ll b){
	return abs(a * b) / __gcd(a, b);
}

inline double ccw(pii A, pii B, pii C){
	return (A.X * B.Y) - (A.Y * B.X) + (B.X * C.Y) - (B.Y * C.X) + (C.X * A.Y) - (C.Y * A.X);
}

inline int CCW(pii A, pii B, pii C){
	double val = ccw(A, B, C);
	double eps = max(max(abs(A.X), abs(A.Y)), max(max(abs(B.X), abs(B.Y)), max(abs(C.X), abs(C.Y)))) / 1e9;
	if (val <= -eps)
		return -1;
	if (val >= eps)
		return 1;
	return 0;
}

void to_upper(string &x){
	REP(i, sz(x))
		x[i] = toupper(x[i]);
}

void to_lower(string &x){
	REP(i, sz(x))
		x[i] = tolower(x[i]);
}

string its(ll x){
	if (x == 0)
		return "0";
	string ret = "";
	while (x > 0){
		ret += (x % 10) + '0';
		x /= 10;
	}
	reverse(all(ret));
	return ret;
}

ll sti(string s){
	ll ret = 0;
	REP(i, sz(s)){
		ret *= 10;
		ret += (s[i] - '0');
	}
	return ret;
}

const int N = 205;
const int D = 2e6 + 10;

int n, m, k, t, w, W[D], f[N], sx, sy;
char mat[N][N];
vi shop[N][N];
bool bio[25][N][N][N];

struct state{
	int x, y;
	int last_shop, k;

}; 

bool ok(int x, int y){
	if (x < 0 || y < 0 || x >= n || y >= m)
		return 0;
	if (mat[x][y] == 'L')
		return 0;
	return 1;
}

int bfs(){
	queue <state> q;
	state tmp;
	tmp.x = sx, tmp.y = sy, tmp.last_shop = 0, tmp.k = k;
	q.push(tmp);
	while (sz(q)){
		tmp = q.front(); q.pop();
		int x = tmp.x, y = tmp.y, last_shop = tmp.last_shop, curr_k = tmp.k;
		int t = f[last_shop] + (k - curr_k);
		if (mat[x][y] == 'P')
			return t;
		if (mat[x][y] == 'L')
			continue;
		if (bio[last_shop][x][y][curr_k])
			continue;
		bio[last_shop][x][y][curr_k] = 1;
		FORA(shop_id, shop[x][y]){
			if (t == f[shop_id]){
				curr_k = k;
				last_shop = shop_id;
			}
		}
		if (curr_k == 0)
			continue;
		tmp.last_shop = last_shop;
		tmp.k = curr_k - 1;
		tmp.x += dx[W[t]];
		tmp.y += dy[W[t]];
		if (ok(tmp.x, tmp.y))
			q.push(tmp);
		REP(i, 4){
			int nx = x + dx[i] + dx[W[t]], ny = y + dy[i] + dy[W[t]];
			if ((ok(x + dx[i], y + dy[i]) && ok(nx, ny)) || (ok(x + dx[W[t]], y + dy[W[t]]) && ok(nx, ny))){
				tmp.x = nx, tmp.y = ny, tmp.last_shop = last_shop, tmp.k = curr_k - 1;
				if (!bio[last_shop][nx][ny][curr_k - 1])
					q.push(tmp);
			}
		}
	}
	return -1;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k >> t >> w;
	REP(i, n){
		REP(j, m){
			cin >> mat[i][j];
			if (mat[i][j] == 'M')
				sx = i, sy = j;
		}
	}

	map <char, int> smjer = {{'S', 1}, {'N', 0}, {'W', 2}, {'E', 3}, {'C', 4}};

	REP(i, w){
		char x; cin >> x;
		W[i] = smjer[x];
	}

	f[0] = 0;
	FOR(i, 1, t + 1){
		int x, y; cin >> x >> y;
		shop[x][y].PB(i);
		cin >> f[i];
	}

	cout << bfs() << '\n';
	
	return 0;
}