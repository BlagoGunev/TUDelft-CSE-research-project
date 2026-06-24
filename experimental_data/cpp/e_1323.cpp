//#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;

/*测量运行时间

#include <windows.h>

DWORD star_time = GetTickCount();

DWORD end_time = GetTickCount();

cout << (end_time - star_time) << "ms." << endl;

*/

typedef long long ll;

typedef pair<int,int> PII;

typedef double db;

#define pb push_back

#define fi first

#define SZ(x) ((int)(x).size())

#define se second

#define int128 __int128

#define endl '\n'

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

template <class T>

inline bool in(T &ret) 

{

	char c;T sgn;

	if(c=getchar(),c==EOF) return 0; 

	while(c!='-'&&(c<'0'||c>'9')) c=getchar();

	sgn=(c=='-')?-1:1;

	ret=(c=='-')?0:(c-'0');

	while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');

	ret*=sgn;

	return 1;

}

template <class T>

inline void out(T x)

{

    if(x<0)

	{

        putchar('-');

        x=-x;

    }

    if(x>9)

    out(x/10);

    putchar(x%10+'0');

}



const int N = 5e5 + 100;

vector<int> g[N];

ll c[N];



int main()

{

	IOS;

	int T = 1;

	cin >> T;

	while(T -- ) {

		int n, m;cin >> n >> m;

		for(int i = 1;i <= n;i ++ ) {

			cin >> c[i];

			g[i].clear();

		}

		for(int i = 0;i < m;i ++ ) {

			int u, v;cin >> u >> v;

			g[v].pb(u); // 维护每一个右半部分点的集合

		}

		// 这里是用map进行hash向量，但是得保证有序, 当然也可以直接hash这个序列的

		

		for(int i = 1;i <= n;i ++ ) if(SZ(g[i])) sort(g[i].begin(), g[i].end());

		map<vector<int>, ll> mp;

		for(int i = 1;i <= n;i ++ ) if(SZ(g[i])) mp[g[i]] += c[i];

		ll ans = 0;

		for(auto [x, y] : mp) ans = __gcd(ans, y);

		cout << ans << endl;

	}

	return 0;

}