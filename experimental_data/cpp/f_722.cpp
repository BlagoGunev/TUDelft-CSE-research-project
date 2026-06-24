#include <bits/stdc++.h>



#define ll long long



#define pii std::pair<int,int>

#define mp std::make_pair

#define fi first

#define se second



#define SZ(x) (int)(x).size()

#define pb push_back



template<class T>inline void chkmax(T &x, const T &y) {if(x < y) x = y;}

template<class T>inline void chkmin(T &x, const T &y) {if(x > y) x = y;}



template<class T>

inline void read(T &x) {

    char c;int f = 1;x = 0;

    while(((c=getchar()) < '0' || c > '9') && c != '-');

    if(c == '-') f = -1;else x = c-'0';

    while((c=getchar()) >= '0' && c <= '9') x = x*10+c-'0';

    x *= f;

}

static int outn;

static char out[(int)2e7];

template<class T>

inline void write(T x) {

    if(x < 0) out[outn++] = '-', x = -x;

    if(x) {

        static int tmpn;

        static char tmp[20];

        tmpn = 0;

        while(x) tmp[tmpn++] = x%10+'0', x /= 10;

        while(tmpn) out[outn++] = tmp[--tmpn];

    }

    else out[outn++] = '0';

}



const int N = 1e5, M = N;

const int K = 40;



int n, m;

int k[N + 9];



int g[K + 9][K + 9];



std::vector<pii> pos[M + 9];

std::vector<pii> seg;



ll gcd(ll a, ll b) {

    return b ? gcd(b, a % b) : a;

}



int solve(const std::vector<pii> &s) {

	int l = 0, r = 0, ans = 0;

	int p[K + 9] = {0}, v[K + 9] = {0};

	memset(p, -1, sizeof p), memset(v, -1, sizeof v);

	while(r < SZ(s)) {

		for(int i = 1; i <= K; ++i)

			if(p[i] != -1) {

				int d = g[i][s[r].se];

				if(v[i] % d != s[r].fi % d) chkmax(l, p[i] + 1);

			}

		p[s[r].se] = r, v[s[r].se] = s[r].fi;

		chkmax(ans, r - l + 1), ++r;

	}

	return ans;

}



int main() {

#ifndef ONLINE_JUDGE

    freopen("F.in", "r", stdin);

    freopen("F.out", "w", stdout);

#endif



	for(int i = 1; i <= K; ++i)

		for(int j = 1; j <= K; ++j)

			g[i][j] = gcd(i, j);

    read(n), read(m);

    for(int i = 1; i <= n; ++i) {

        read(k[i]);

        for(int j = 0; j < k[i]; ++j) {

            int x;

            read(x);

            pos[x].pb(mp(i, j));

        }

    }

    for(int i = 1; i <= m; ++i) {

        int ans = 0;

        for(int j = 0; j < SZ(pos[i]); ++j) {

            int k = j;

            while(k < SZ(pos[i]) - 1 && pos[i][k + 1].fi == pos[i][k].fi + 1) ++k;

            seg.clear();

            for(int r = j; r <= k; ++r)

                seg.pb(mp(pos[i][r].se, ::k[pos[i][r].fi]));

            chkmax(ans, solve(seg));

            j = k;

        }

        printf("%d\n", ans);

    }

    return 0;

}