#include <bits/stdc++.h>

using namespace std;

typedef double db;

//#define int long long

#define fi first

#define se second

#define mk make_pair

#define pb emplace_back

#define poly vector<int>

#define Bt(a) bitset<a>

#define bc __builtin_popcount

#define pc putchar

#define ci const int&

char sss;

const int mod = 998244353;

const db eps = 1e-10;

inline int Max(ci x, ci y) {return x > y ? x : y;}

inline int Min(ci x, ci y) {return x < y ? x : y;}

inline db Max(db x, db y) {return x - y > eps ? x : y;}

inline db Min(db x, db y) {return x - y < eps ? x : y;}

inline int Add(ci x, ci y, ci M = mod) {return (x + y) >= M ? (x + y - M) : (x + y);}

inline int Mul(ci x, ci y, ci M = mod) {return 1ll * x * y % M;}

inline int Dec(ci x, ci y, ci M = mod) {return (x - y) < 0 ? (x - y + M) : (x - y);}

typedef pair<int, int> pii;

inline int Abs(int x) {return x < 0 ? -x : x;}

//char buf[1<<21],*p1=buf,*p2=buf;

//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)

char Obuf[105000],*O=Obuf;//Siz shoule be the size of Out File

int pst[30],ptop;

inline void Fprint(){fwrite(Obuf,1,O-Obuf,stdout);}

inline void Fwrite(int x){

  if(x==0){*O++='0';if(O-Obuf>100000)Fprint(),O=Obuf;return;}

  if(x<0)*O++='-',x=-x;ptop=0;

  while(x)pst[++ptop]=x%10,x/=10;

  while(ptop)*O++=pst[ptop--]+'0';

  if(O-Obuf>100000)Fprint(),O=Obuf;

}

inline int read() {

    int s = 0, w = 1;

    char ch = getchar();

    while (!isdigit(ch)) {if (ch == '-') w = -1;ch = getchar();}

    while (isdigit(ch)) {s = s * 10 + ch - '0';ch = getchar();}

    return s * w;

}

inline void write(int x) {

    if (x < 0)putchar('-'), x = -x;

    if (x > 9)write(x / 10);

	pc(x % 10 + '0');

}

inline int qpow(int x, int y) {

    int res = 1;

    while (y) {if (y & 1)res = Mul(res, x);x = Mul(x, x);y >>= 1;}

    return res;

}

inline void cadd(int &x, int y) {x += y;}

inline void cmul(int &x, int y) {x *= y;}

inline void cmax(int &x, int y) {x = Max(x, y);}

inline void cmin(int &x, int y) {x = Min(x, y);}



const int N = 1 << 24;

const int SN = 31, SM = 25;

namespace Refined_heart{

	int f[SN][SM][SM][SM][SM][2][2];

	int n, m, x[5], y[5]; 

	int dfs(int now, int zx, int fx, int zy, int fy, int okx, int oky) {

		if(now == 30) {

			if(zx || fx || zy || fy) return 0;

			if(okx || oky) return 0;

			if(zx != fx || zy != fy) return 0;

			return 1;

		}

		int &res = f[now][zx][fx][zy][fy][okx][oky];

		if(~res) return res;

		res = 0;

		for(int i = 0; i < (1 << n); ++i) {

			int nzx = zx, nzy = zy, nfx = fx, nfy = fy;

			int ox = okx, oy = oky;

			for(int k = 0; k < n; ++k) {

				if(!(i >> k & 1)) continue;

				if(x[k] > 0) nzx += x[k];

				else nfx += -x[k];

				if(y[k] > 0) nzy += y[k];

				else nfy += -y[k];

			}

			int dzx = nzx & 1, dzy = nzy & 1;

			int dfx = nfx & 1, dfy = nfy & 1;

			if(dzx != dfx) continue;

			if(dzy != dfy) continue;

			if(dzx > (m >> now & 1)) ox = 1;

			if(dzy > (m >> now & 1)) oy = 1;

			if(dzx < (m >> now & 1)) ox = 0;

			if(dzy < (m >> now & 1)) oy = 0;

			int jzx = nzx >> 1, jfx = nfx >> 1;

			int jzy = nzy >> 1, jfy = nfy >> 1;

			int nxtv = dfs(now + 1, jzx, jfx, jzy, jfy, ox, oy);

			res = Add(res, nxtv);

//			if(nxtv > 0) {

//				cout << "state = " << i << '\n';

//			}

		}

		return res;

	}

	void solve(){

		n = read(); m = read();

		for(int i = 0; i < n; ++i) {

			x[i] = read(); y[i] = read();

		}

		memset(f, -1, sizeof f);

		cout << Dec(dfs(0, 0, 0, 0, 0, 0, 0), 1) << '\n';

	}

}

char ttt;

signed main(){

	cerr << "Memory = " << 1.0 * abs(&ttt - &sss) / 1024 / 1024 << " MB\n";

//   	freopen("in.txt","r",stdin);

	Refined_heart::solve();

	return cerr << "Time = " << 1.0 * clock() / CLOCKS_PER_SEC << '\n', 0;

}