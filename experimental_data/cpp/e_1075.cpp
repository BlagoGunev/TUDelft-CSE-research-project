#include <bits/stdc++.h>
using namespace std;

//#define getc getc_unlocked
//#define putc putc_unlocked
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
	int t=0;
	register char z='a';
	int znak=1;
	z=getc(stdin);
	if (z=='-')
	{
		znak=-1;
	}
	while ((z<'0') || ('9'<z))
	{
		z=getc(stdin);
		if (z=='-')
		{
			znak=-1;
		}
	}
	while (('0'<=z) && (z<='9'))
	{
		t=(t<<3)+(t<<1)+z-'0';
		z=getc(stdin);
	}
	*i=(t*znak);
}
inline void readUI(int *i)
{
	int t=0;
	register char z='a';
	z=getc(stdin);
	while ((z<'0') || ('9'<z))
	{
		z=getc(stdin);
	}
	while (('0'<=z) && (z<='9'))
	{
		t=(t<<3)+(t<<1)+z-'0';
		z=getc(stdin);
	}
	*i=t;
}
inline void readL(ll *l)
{
	ll t=0;
	register char z='a';
	int znak=1;
	z=getc(stdin);
	if (z=='-')
	{
		znak*=-1;
	}
	while ((z<'0') || ('9'<z))
	{
		z=getc(stdin);
		if (z=='-')
		{
			znak=-1;
		}
	}
	while (('0'<=z) && (z<='9'))
	{
		t=(t<<3)+(t<<1)+z-'0';
		z=getc(stdin);
	}
	*l=(t*znak);
}
inline void readUL(ll *l)
{
	ll t=0;
	register char z='a';
	z=getc(stdin);
	while ((z<'0') || ('9'<z))
	{
		z=getc(stdin);
	}
	while (('0'<=z) && (z<='9'))
	{
		t=(t<<3)+(t<<1)+z-'0';
		z=getc(stdin);
	}
	*l=t;
}
inline void writeI(int i)
{
	if (i==0)
	{
		putc(48, stdout);
	}
	else
	{
		if (i<0)
		{
		   i*=-1;
		   putc(45, stdout);
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
			putc(_tab[j], stdout);
		}
	}
}
inline void writeL(ll l)
{
	if (l==0)
	{
		putc(48, stdout);
	}
	else
	{
		if (l<0)
		{
		   l*=-1;
		   putc(45, stdout);
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
			putc(_tab[j], stdout);
		}
	}
}
inline void writeS(string s)
{
	int l=s.length();
	for (int i=0; i<l; ++i)
	{
		putc(s[i], stdout);
	}
}
inline void writeC(char c)
{
	putc(c, stdout);
}
inline void space()
{
	putc(32, stdout);
}
inline void endl()
{
	putc(10, stdout);
}

#define debug if(1)
#define debug2 if(1)
#define debug3 if(1)
#define debug4 if(1)
#define MAXN 300005

int n;
ll lewo, prawo, dol, gora, wyn4, wynik;
pair <ll, ll> tab[MAXN];

int main()
{
	readI(&n);
	lewo=dol=1000696969;
	gora=prawo=-1000696969;
	for (int i=1; i<=n; ++i)
	{
		readL(&tab[i].ff);
		readL(&tab[i].ss);
		lewo=min(lewo, tab[i].ff);
		prawo=max(prawo, tab[i].ff);
		gora=max(gora, tab[i].ss);
		dol=min(dol, tab[i].ss);
	}
	wyn4=((gora-dol)<<1)+((prawo-lewo)<<1);
	for (int i=1; i<=n; ++i)
	{
		ll pion, poziom;
		if (gora-tab[i].ss<tab[i].ss-dol)
		{
			pion=tab[i].ss-dol;
		}
		else
		{
			pion=gora-tab[i].ss;
		}
		if (prawo-tab[i].ff<tab[i].ff-lewo)
		{
			poziom=tab[i].ff-lewo;
		}
		else
		{
			poziom=prawo-tab[i].ff;
		}
		wynik=max(wynik, (pion<<1)+(poziom<<1));
	}
	writeL(wynik);
	space();
	for (int i=4; i<=n; ++i)
	{
		writeL(wyn4);
		space();
	}
	return 0;
}
/*
*/