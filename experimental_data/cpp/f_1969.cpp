//这回只花了114514min就打完了。
//真好。记得多手造几组。ACM拍什么拍。 
#include "bits/stdc++.h"
using namespace std;
template<class T1, class T2> istream &operator>>(istream &cin, pair<T1, T2> &a) { return cin>>a.first>>a.second; }
template<class T1> istream &operator>>(istream &cin, vector<T1> &a) { for (auto &x:a) cin>>x; return cin; }
template<class T1> istream &operator>>(istream &cin, valarray<T1> &a) { for (auto &x:a) cin>>x; return cin; }
template<class T1, class T2> ostream &operator<<(ostream &cout, const pair<T1, T2> &a) { return cout<<a.first<<' '<<a.second; }
template<class T1, class T2> ostream &operator<<(ostream &cout, const vector<pair<T1, T2>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<class T1> ostream &operator<<(ostream &cout, const vector<T1> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<class T1> ostream &operator<<(ostream &cout, const valarray<T1> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<class T1> ostream &operator<<(ostream &cout, const vector<valarray<T1>> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<'\n'<<a[i]; return cout; }
template<class T1> ostream &operator<<(ostream &cout, const vector<vector<T1>> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<'\n'<<a[i]; return cout; }
template<class T1, class T2> bool cmin(T1 &x, const T2 &y) { if (y<x) { x=y; return 1; } return 0; }
template<class T1, class T2> bool cmax(T1 &x, const T2 &y) { if (x<y) { x=y; return 1; } return 0; }
template<class T1> vector<T1> range(T1 l, T1 r, T1 step=1) { assert(step>0); int n=(r-l+step-1)/step, i; vector<T1> res(n); for (i=0; i<n; i++) res[i]=l+step*i; return res; }
template<class T1> basic_string<T1> operator*(const basic_string<T1> &s, int m) { auto r=s; m*=s.size(); r.resize(m); for (int i=s.size(); i<m; i++) r[i]=r[i-s.size()]; return r; }
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned ui;
typedef long double db;
typedef long long ll;
typedef __int128 lll;
istream &operator>>(istream &cin, lll &x) { x=0; static string s; cin>>s; for (char c:s) x=x*10+(c-'0'); return cin; }
ostream &operator<<(ostream &cout, lll x) { static char s[60]; int tp=1; s[0]='0'+(x%10); while (x/=10) s[tp++]='0'+(x%10); while (tp--) cout<<s[tp]; return cout; }
#define all(x) (x).begin(),(x).end()
mt19937_64 rnd(345);
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(15);
	int n, m, i, j, k, l, r=0;
	cin>>n>>m;
	vector<int> a(n), cnt(m);
	for (int &x:a) cin>>x, --x;
	vector<int> f(n+1, -1);
	vector<ll> s(n), hs(m);
	generate(all(hs), rnd);
	for (i=0; i+1<n; i++) s[i+1]=s[i]^hs[a[i]];
	for (i=0; i<m; i++) ++cnt[a[i]];
	while (i<n)
	{
		int y=max_element(all(cnt))-cnt.begin();
		if (cnt[y]==1) break;
		cnt[y]-=2;
		++r;
		++cnt[a[i]]; ++cnt[a[i+1]];
		i+=2;
	}
	f[i]=r;
	if (i==n)
	{
		for (int x:cnt) r+=x>>1;
	}
	unordered_map<ll, vector<int>> pos;
	for (j=n-1; j>=0; j--) pos[s[j]].push_back(j);
	for (; i<n; i+=2) if (f[i]>=0)
	{
		vector<int> c(m, 1);
		for (j=i; j<n; j++) ++c[a[j]];
		int tot=0;
		int t=f[i];
		for (int x:c) tot+=x>>1;
		for (j=0; j<m; j++) for (k=j+1; k<m; k++)
		{
			ll ss=s[i]^hs[j]^hs[k];
			auto it=pos.find(ss);
			if (it==pos.end())
			{
				cmax(r, t+tot-(c[j]%2==0)-(c[k]%2==0));
				continue;
			}
			auto &v=it->second;
			while (v.size()&&v.back()<i+2) v.pop_back();
			int l=v.size()?v.back():n;
			cmax(f[l], t+(l-i)/2-1);
			if (l==n) cmax(r, t+tot-(c[j]%2==0)-(c[k]%2==0));
		}
	}
	cout<<r<<endl;
}