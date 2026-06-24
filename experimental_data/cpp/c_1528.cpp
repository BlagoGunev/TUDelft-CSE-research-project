#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }

template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}

template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }

template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }

template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }

template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.first << ' ' << p.second << ')'; }

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)

#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)

#define dbg_ok cerr<<"OK!\n"

#define ll long long

#define ld long double

#define ull unsigned long long

#define pii pair<int,int>

#define MOD 1000000007

#define zeros(x) x&(x-1)^x

#define fi first

#define se second

#define NMAX 300005

const long double PI = acos(-1);



int n, t, x, st[NMAX], fn[NMAX], ans, id_by_st[2 * NMAX], final_set[NMAX], lg;



vector<int> v[NMAX], g[NMAX];

set<int> S;



void dfs(int nod, int &nr) {

	id_by_st[nr] = nod;

	st[nod] = nr++;

	for (auto it : g[nod]){

		dfs(it, nr);

	}

	fn[nod] = nr++;

}



int get_anc(int x) {

	auto anc = S.lower_bound(st[x]);

	if (anc == S.begin())

		return 0;

	anc = prev(anc);

	if (fn[id_by_st[*anc]] < fn[x])

		return 0;

	return id_by_st[*anc];

}



int get_suc(int x) {

	auto suc = S.upper_bound(st[x]);

	if (suc == S.end())

		return 0;

	if (fn[id_by_st[*suc]] > fn[x])

		return 0;

	return id_by_st[*suc];

}



void ins(int x) {

	S.insert(st[x]);

	if (get_suc(x))

		return;

	int anc = get_anc(x);

	if (anc && final_set[anc])

		final_set[anc] = 0;

	else

		lg++;

	final_set[x] = 1;

}



void rem(int x) {

	S.erase(st[x]);

	if (final_set[x]) {

		final_set[x] = 0;

		int anc = get_anc(x);

		if (anc){

			int suc = get_suc(anc);

			if (suc)

				lg--;

			else

				final_set[anc] = 1;

		}

		else 

			lg--;

	}

}



void dfs2(int nod = 1) {

	ins(nod);

	ans = max(ans, lg);

	for (auto it : v[nod]) {

		dfs2(it);

	}

	rem(nod);

}



int main(){

  ios::sync_with_stdio(false);

  cin >> t;

  while (t--){

  	cin >> n;

  	for (int i=1;i<=n;i++){

  		v[i].clear();

  		g[i].clear();

  	}

  	for (int i=2;i<=n;i++){

  		cin >> x;

  		v[x].push_back(i);

  	}

  	for (int i=2;i<=n;i++){

  		cin >> x;

  		g[x].push_back(i);

  	}



  	lg = ans = 0;

  	int nr = 0;

  	dfs(1, nr);

   	dfs2();

  	cout << ans << '\n';

  }

  return 0;

}