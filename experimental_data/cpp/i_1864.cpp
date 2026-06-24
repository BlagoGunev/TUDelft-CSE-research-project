//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1007;
const int vax=nax*nax;

int n, q;

int k;
int ojf[vax];

int blok[nax][nax];

int s;
int spo[nax][nax];
int rozmiar[vax];

int r;
pii ujscie[vax];//ktore ujscie i ile razy je widzi
pii pozycja[vax];
pii przedzial[vax];

vi kandy;

int fin(int v)
{
	if (v!=ojf[v])
		ojf[v]=fin(ojf[v]);
	return ojf[v];
}

void uni(int a, int b)
{
	ojf[fin(a)]=fin(b);
}

int wsp_to_int(pii v)
{
	return v.first*(n+1)+v.second;
}

int wsp_to_int(int a, int b)
{
	return a*(n+1)+b;
}

pii int_to_wsp(int v)
{
	return {v/(n+1), v%(n+1)};
}

//~ set<pii> krawedzie;

vector<pii> graf[nax][nax];

pair<pii,pii> pola_dla_krawedzi(pii a, pii b)
{
	if (a>b)
		swap(a, b);
	if (a.second+1==b.second)
		return {b, {b.first+1, b.second}};
	if (a.first+1==b.first)
		return {b, {b.first, b.second+1}};
	assert(0);
}

template <typename T> void usun(vector<T> &wek, T v)
{
	//~ debug() << "z " << wek << " mam usunac " << v;
	for (int i=0; i<(int)wek.size(); i++)
	{
		if (wek[i]==v)
		{
			swap(wek[i], wek.back());
			wek.pop_back();
			return;
		}
	}
	assert(0);
}

template <typename T> bool zawiera(const vector<T> &wek, T v)
{
	for (int i=0; i<(int)wek.size(); i++)
	{
		if (wek[i]==v)
		{
			return true;
		}
	}
	return false;
}

int czas;
int bylo[nax][nax];

void edge(pii a, pii b)
{
	graf[a.first][a.second].push_back(b);
	graf[b.first][b.second].push_back(a);
}

vector<pii> lacz(pii a, pii b)
{
	if (a>b)
		swap(a, b);
	auto wez=pola_dla_krawedzi(a, b);
	if (!zawiera(graf[wez.first.first][wez.first.second], wez.second))
		return {};
	//~ krawedzie.insert({wsp_to_int(a), wsp_to_int(b)});
	int aa=wsp_to_int(a);
	int bb=wsp_to_int(b);
	//~ debug() << "dla pul " << wez;
	usun(graf[wez.first.first][wez.first.second], wez.second);
	usun(graf[wez.second.first][wez.second.second], wez.first);
	if (fin(aa)!=fin(bb))
	{
		uni(aa, bb);
		return {};
	}
	uni(aa, bb);
	
	queue<pii> kol[2];
	vector<pii> ret[2];
	kol[0].push(wez.first);
	kol[1].push(wez.second);
	czas++;
	bylo[wez.first.first][wez.first.second]=czas;
	bylo[wez.second.first][wez.second.second]=czas;
	for (int h=0; 1; h^=1)
	{
		if (kol[h].empty())
			return ret[h];
		pii v=kol[h].front();
		kol[h].pop();
		ret[h].push_back(v);
		for (pii i : graf[v.first][v.second])
		{
			if (bylo[i.first][i.second]<czas)
			{
				bylo[i.first][i.second]=czas;
				kol[h].push(i);
			}
		}
	}
}

int rx[]={-1, 1, 0, 0};
int ry[]={0, 0, -1, 1};

int solve(int a, int b)
{
	//~ debug() << "solve " << imie(a) << imie(b);
	vector<pii> rogi;
	rogi.push_back({a-1, b-1});
	rogi.push_back({a-1, b});
	rogi.push_back({a, b});
	rogi.push_back({a, b-1});
	for (int h=0; h<4; h++)
	{
		pii x=rogi[h];
		pii y=rogi[(h+1)%4];
		int kto=spo[a][b];
		auto wez=lacz(x, y);
		if (!wez.empty())
		{
			debug() << imie(wez);
			s++;
			rozmiar[s]=0;
			ujscie[s]={ujscie[kto].first, 0};
			for (pii i : wez)
			{
				rozmiar[kto]--;
				rozmiar[s]++;
				spo[i.first][i.second]=s;
				for (int j=0; j<4; j++)
				{
					pii u={i.first+rx[j], i.second+ry[j]};
					if (u==pozycja[ujscie[s].first])
					{
						ujscie[s].second++;
						ujscie[kto].second--;
					}
				}
			}
		}
	}
	//~ debug() << "po laczeniu:";
	//~ for (int i=1; i<=n; i++)
		//~ debug() << range(spo[i]+1, spo[i]+1+n);
	int ja=spo[a][b];
	blok[a][b]=1;
	vi dook;
	for (int j=0; j<4; j++)
	{
		pii u={a+rx[j], b+ry[j]};
		if (!blok[u.first][u.second] && !zawiera(dook, spo[u.first][u.second]))
			dook.push_back(spo[u.first][u.second]);
	}
	//~ debug() << imie(ja) << " " << imie(dook);
	int jest_kandy=0;
	if (zawiera(kandy, ja))
		jest_kandy=ja;
	for (int i : dook)
		if (zawiera(kandy, i))
			jest_kandy=i;
	
	//~ debug() << imie(jest_kandy) << imie(kandy);
	if (jest_kandy && (int)kandy.size()>1)
	{
		usun(kandy, jest_kandy);
		if ((int)kandy.size()==1)
		{
			int kto=kandy[0];
			ujscie[kto]={0, 0};
		}
		jest_kandy=0;
	}
	
	if (!jest_kandy)
	{
		int uj=ujscie[spo[a][b]].first;
		vi musze;
		for (int i : dook)
			if (ujscie[i].second==0)
				musze.push_back(i);
		if (!musze.empty())
		{
			r++;
			pozycja[r]={a, b};
			int roz=0;
			for (int i : musze)
			{
				roz+=rozmiar[i];
				ujscie[i]={r, 0};
			}
			for (int j=0; j<4; j++)
			{
				pii u={a+rx[j], b+ry[j]};
				if (!blok[u.first][u.second] && zawiera(musze, spo[u.first][u.second]))
					ujscie[spo[u.first][u.second]].second++;
			}
			przedzial[r]={przedzial[uj].second-roz+1, przedzial[uj].second};
			przedzial[uj].second-=roz+1;
			return przedzial[r].first-1;
		}
		przedzial[uj].second--;
		return przedzial[uj].second+1;
	}
	
	int mini=0;
	int sroz=0;
	for (int i : dook)
	{
		mini=max(mini, rozmiar[i]);
		sroz+=rozmiar[i];
	}
	
	assert(przedzial[0].second==sroz+1);
	
	int uj=ujscie[spo[a][b]].first;
	
	debug() << imie(spo[a][b]);
	debug() << imie(uj) << imie(przedzial[uj]);
	
	if ((int)dook.size()<=1)
	{
		przedzial[uj].second--;
		return przedzial[uj].second+1;
	}
	
	int przeznaczam=sroz-mini;
	
	
	debug() << imie(sroz) << imie(mini);
	
	r++;
	pozycja[r]={a, b};
	int zwroc=przedzial[uj].second-przeznaczam;
	przedzial[r]={przedzial[uj].second-przeznaczam+1, przedzial[uj].second};
	for (int i : dook)
		ujscie[i]={r, 0};
	for (int j=0; j<4; j++)
	{
		pii u={a+rx[j], b+ry[j]};
		if (!blok[u.first][u.second] && zawiera(dook, spo[u.first][u.second]))
			ujscie[spo[u.first][u.second]].second++;
	}
	przedzial[0].second-=przeznaczam+1;
	for (int i : dook)
		assert(ujscie[i].second);
	kandy.clear();
	for (int i : dook)
		if (rozmiar[i]==mini)
			kandy.push_back(i);
	if ((int)kandy.size()==1)
		ujscie[kandy[0]]={0, 0};
	return zwroc;
}

void test()
{
	scanf("%d%d", &n, &q);
	k=(n+1)*(n+1);
	for (int i=0; i<k; i++)
		ojf[i]=i;
	//~ krawedzie.clear();
	for (int i=0; i<n; i++)
	{
		//~ krawedzie.insert({wsp_to_int(0, i), wsp_to_int(0, i+1)});
		//~ krawedzie.insert({wsp_to_int(n, i), wsp_to_int(n, i+1)});
		//~ krawedzie.insert({wsp_to_int(i, 0), wsp_to_int(i+1, 0)});
		//~ krawedzie.insert({wsp_to_int(i, n), wsp_to_int(i+1, n)});
		uni(wsp_to_int(0, i), wsp_to_int(0, i+1));
		uni(wsp_to_int(n, i), wsp_to_int(n, i+1));
		uni(wsp_to_int(i, 0), wsp_to_int(i+1, 0));
		uni(wsp_to_int(i, n), wsp_to_int(i+1, n));
	}
	//~ for (pii i : krawedzie)
		//~ uni(i.first, i.second);
	
	for (int i=0; i<=n+1; i++)
		for (int j=0; j<=n+1; j++)
			blok[i][j]=1;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			blok[i][j]=0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			graf[i][j].clear();
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (j+1<=n)
				edge({i, j}, {i, j+1});
			if (i+1<=n)
				edge({i, j}, {i+1, j});
		}
	}
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			bylo[i][j]=0;
	czas=0;
	
	s=1;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			spo[i][j]=1;
	rozmiar[s]=n*n;
	r=0;
	ujscie[s]={0, 0};
	przedzial[0]={1, n*n};
	
	kandy={1};
	
	int last=0;
	while(q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a^=last;
		b^=last;
		last=solve(a, b);
		//~ printf("%d\n", last);
		//~ fflush(stdout);
		printf("%d ", last);
	}
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}