/*

	I will chase the meteor for you, a thousand times over.

	Please wait for me, until I fade forever.

	Just 'coz GEOTCBRL.

*/

#include <bits/stdc++.h>

using namespace std;

#define fore(i,u)  for (int i = head[u] ; i ; i = nxt[i])

#define rep(i,a,b) for (int i = a , _ = b ; i <= _ ; i ++)

#define per(i,a,b) for (int i = a , _ = b ; i >= _ ; i --)

#define For(i,a,b) for (int i = a , _ = b ; i <  _ ; i ++)

#define Dwn(i,a,b) for (int i = ((int) a) - 1 , _ = (b) ; i >= _ ; i --)

#define fors(s0,s) for (int s0 = (s) , _S = s ; s0 ; s0 = (s0 - 1) & _S)

#define foreach(it,s) for (__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)



#define mp make_pair

#define pb push_back

#define pii pair<int , int>

#define fir first

#define sec second

#define MS(x,a) memset(x , (a) , sizeof (x))



#define gprintf(...) fprintf(stderr , __VA_ARGS__)

#define gout(x) std::cerr << #x << "=" << x << std::endl

#define gout1(a,i) std::cerr << #a << '[' << i << "]=" << a[i] << std::endl

#define gout2(a,i,j) std::cerr << #a << '[' << i << "][" << j << "]=" << a[i][j] << std::endl

#define garr(a,l,r,tp) rep (__it , l , r) gprintf(tp"%c" , a[__it] , " \n"[__it == _])



template <class T> inline void upmax(T&a , T b) { if (a < b) a = b ; }

template <class T> inline void upmin(T&a , T b) { if (a > b) a = b ; }



typedef long long ll;



const int maxn = 1000007;

const int maxm = 200007;

const int mod = 1000000007;

const int inf = 0x7fffffff;

const double eps = 1e-7;



typedef int arr[maxn];

typedef int adj[maxm];



inline int fcmp(double a , double b) {

	if (fabs(a - b) <= eps) return 0;

	if (a < b - eps) return -1;

	return 1;

}



inline int add(int a , int b) { return ((ll) a + b) % mod ; }

inline int mul(int a , int b) { return ((ll) a * b) % mod ; }

inline int dec(int a , int b) { return add(a , mod - b % mod) ; }

inline int Pow(int a , int b) {

	int t = 1;

	while (b) {

		if (b & 1) t = mul(t , a);

		a = mul(a , a) , b >>= 1;

	}

	return t;

}



#define gc getchar

#define idg isdigit

#define rd RD<int>

#define rdll RD<long long>

template <typename Type>

inline Type RD() {

	char c = getchar(); Type x = 0 , flag = 1;

	while (!idg(c) && c != '-') c = getchar();

	if (c == '-') flag = -1; else x = c - '0';

	while (idg(c = gc()))x = x * 10 + c - '0';

	return x * flag;

}

inline char rdch() {

	char c = gc();

	while (!isalpha(c)) c = gc();

	return c;

}

#undef idg

#undef gc



// beginning



int n , m;

arr x , y , sx , sy;



inline bool cmp_x(const int i , const int j) {

	return pii(x[i] , i) < pii(x[j] , j);

}



inline bool cmp_y(const int i , const int j) {

	return pii(y[i] , i) < pii(y[j] , j);

}



arr vis;



void input() {

	n = rd() , m = rd();

	rep (i , 1 , n) {

		x[i]  = rd() , y[i]  = rd();

		x[i] += rd() , y[i] += rd();

		sx[i] = i , sy[i] = i;

	}

	sort(sx + 1 , sx + n + 1 , cmp_x);

	sort(sy + 1 , sy + n + 1 , cmp_y);

//	garr(x , 1 , n , "%d");

//	garr(y , 1 , n , "%d");

//	garr(sx , 1 , n , "%d");

//	garr(sy , 1 , n , "%d");

}



arr used;

void solve() {

	if (m == n - 1) {

		puts("1");

		return;

	}

	int cnt = 0;

	ll ans = 0x7fffffffffffffff;

	rep (i , 1 , min(2 * m + 1 , n)) {

		int mark_i = cnt;

		used[sx[i]] ++;



		per (j , n , max(n - 2 * m , i + 1)) {

			int mark_j = cnt;

			used[sx[j]] ++;



			rep (u , 1 , min(2 * m + 1 , n)) {

				int mark_u = cnt;

				used[sy[u]] ++;



				per (v , n , max(n - 2 * m , u + 1)) {

					if (cnt == m) {

						ll tmp = 1ll * (x[sx[j]] - x[sx[i]]) * (y[sy[v]] - y[sy[u]]);

						if (!tmp) {

							if (!(x[sx[j]] - x[sx[i]])) tmp += (y[sy[v]] - y[sy[u]]) * 2;

							else tmp += (x[sx[j]] - x[sx[i]]) * 2;

							if (tmp % 4 != 0) tmp *= 2;

						}

//						gout(tmp);

						if (tmp && tmp % 4 == 0)

							upmin(ans , tmp);

					}

					cnt += (vis[sy[v]] == 0);

					++ vis[sy[v]];

					if (used[sy[v]]) break;

				}



				per (v , n , max(n - 2 * m , u + 1)) {

					-- vis[sy[v]];

					if (used[sy[v]]) break;

				}

				used[sy[u]] --;

				cnt = mark_u;

				cnt += (vis[sy[u]] == 0);

				++ vis[sy[u]];



				if (used[sy[u]]) break;

			}



			rep (u , 1 , min(2 * m + 1 , n)) {

				-- vis[sy[u]];

				if (used[sy[u]]) break;

			}

			used[sx[j]] --;

			cnt = mark_j;

			cnt += (vis[sx[j]] == 0);

			++ vis[sx[j]];

		}



		per (j , n , max(n - 2 * m , 1)) if (j <= i) break; else

			-- vis[sx[j]];

		used[sx[i]] --;

		cnt = mark_i;

		cnt += (vis[sx[i]] == 0);

		++ vis[sx[i]];

	}

//	gout(ans);

	cout << ans / 4 << endl;

}



int main() {

	#ifndef ONLINE_JUDGE

		freopen("data.txt" , "r" , stdin);

	#endif

	input();

	solve();

	return 0;

}