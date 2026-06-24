#include <bits/stdc++.h>
using namespace std;

//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define ff first
#define ss second

typedef long long int ll;
typedef long double ld;
typedef short int sh;

inline void readI(int *i)
{
	register int t=0;
	register char z=getchar();
	int znak=1;
	if (z=='-')
	{
		znak=-1;
	}
	while ((z<'0') || ('9'<z))
	{
		z=getchar();
		if (z=='-')
		{
			znak=-1;
		}
	}
	while (('0'<=z) && (z<='9'))
	{
		t=(t<<3)+(t<<1)+z-'0';
		z=getchar();
	}
	*i=(t*znak);
}
inline void readUI(int *i)
{
	register int t=0;
	register char z=getchar();
	while ((z<'0') || ('9'<z))
	{
		z=getchar();
	}
	while (('0'<=z) && (z<='9'))
	{
		t=(t<<3)+(t<<1)+z-'0';
		z=getchar();
	}
	*i=t;
}
inline void readL(ll *l)
{
	register ll t=0;
	register char z=getchar();
	int znak=1;
	if (z=='-')
	{
		znak*=-1;
	}
	while ((z<'0') || ('9'<z))
	{
		z=getchar();
		if (z=='-')
		{
			znak=-1;
		}
	}
	while (('0'<=z) && (z<='9'))
	{
		t=(t<<3)+(t<<1)+z-'0';
		z=getchar();
	}
	*l=(t*znak);
}
inline void readUL(ll *l)
{
	register ll t=0;
	register char z=getchar();
	while ((z<'0') || ('9'<z))
	{
		z=getchar();
	}
	while (('0'<=z) && (z<='9'))
	{
		t=(t<<3)+(t<<1)+z-'0';
		z=getchar();
	}
	*l=t;
}
inline void writeI(int i)
{
	if (i==0)
	{
		putchar(48);
	}
	else
	{
		if (i<0)
		{
		   i*=-1;
		   putchar(45);
		}
		int _tab[12];
		int wsk=0;
		while (i>0)
		{
			++wsk;
			_tab[wsk]=(i%10)+48;
			i/=10;
		}
		for (int j=wsk; j>=1; --j)
		{
			putchar(_tab[j]);
		}
	}
}
inline void writeL(ll l)
{
	if (l==0)
	{
		putchar(48);
	}
	else
	{
		if (l<0)
		{
		   l*=-1;
		   putchar(45);
		}
		int _tab[21];
		int wsk=0;
		while (l>0)
		{
			++wsk;
			_tab[wsk]=(l%10)+48;
			l/=10;
		}
		for (int j=wsk; j>=1; --j)
		{
			putchar(_tab[j]);
		}
	}
}
inline void writeS(string s)
{
	int l=s.length();
	for (int i=0; i<l; ++i)
	{
		putchar(s[i]);
	}
}
inline void writeC(char c)
{
	putchar(c);
}
inline void space()
{
	putchar(32);
}
inline void endl()
{
	putchar(10);
}

#define debug if(1)
#define debug2 if(1)
#define debug3 if(1)
#define debug4 if(1)
#define MAXN 3*(int)(1e5)+5

int n, m, k, a, b, c, ile;
vector <pair <int, pair <ll, int> > > v[MAXN];
vector <int> odp;
priority_queue <pair <ll, pair <int, int> > > q;
ll d[MAXN];
ll INF=(1e18);
bitset <MAXN> odw;

void dixtra()
{
	while (q.empty()==false)
	{
		ll x=q.top().ff;
		x*=-1;
		ll y=q.top().ss.ff;
		ll z=q.top().ss.ss;
		q.pop();
		if (odw[y]==false)
		{
			odw[y]=true;
			int l=v[y].size();
			d[y]=x;
			if (y!=1)
			{
				odp.eb(z);
				++ile;
			}
			if (ile==k)
			{
				return;
			}
			for (int i=0; i<l; ++i)
			{
				if (odw[v[y][i].ff]==false)
				{
					if (d[y]+v[y][i].ss.ff<d[v[y][i].ff])
					{
						d[v[y][i].ff]=d[y]+v[y][i].ss.ff;
						q.push(mp(-d[v[y][i].ff], mp(v[y][i].ff, v[y][i].ss.ss)));
					}
				}
			}
		}
	}
}
int main()
{
	readI(&n);
	readI(&m);
	readI(&k);
	for (int i=1; i<=n; ++i)
	{
		d[i]=INF;
	}
	for (int i=1; i<=m; ++i)
	{
		readI(&a);
		readI(&b);
		readI(&c);
		v[a].eb(mp(b, mp(c, i)));
		v[b].eb(mp(a, mp(c, i)));
	}
	if (k<0)
	{
		puts ("0");
		return 0;
	}
	q.push(mp(0, mp(1, 0)));
	dixtra();
	int l=odp.size();
	printf ("%d\n", l);
	for (int i=0; i<l; ++i)
	{
		printf ("%d ", odp[i]);
	}
	return 0;
}
/*
*/