#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define st first
#define nd second
#define make(a,b) make_pair(a,b)

typedef pair<int,int> pun;
typedef long long ll;

map <int,int> d;
set < pun > kol;

int l[N], c[N];


int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",l+i);
	for (int i=0;i<n;i++) scanf("%d",c+i);
	for (int i=0;i<n;i++)
	{
		int x = d[l[i]];
		if ( x == 0 )
		{
			d[l[i]] = c[i];
			kol.insert( make(c[i],l[i]) );
		}
		else if ( x > c[i] )
		{
			kol.erase( make(x,l[i]) );
			d[l[i]] = c[i];
			kol.insert( make(c[i],l[i]) );
		}
	}
	int x,y,a,b;
	while( !kol.empty() )
	{
		x = kol.begin()->nd;
		if ( x == 1 ) break;
		y = kol.begin()->st;
		kol.erase( kol.begin() );
		for (int i=1;i<=n;i++)
		{
			a = __gcd(x,l[i]);
			b = d[a];
			if ( b==0 || (b > y+c[i]) )
			{
				kol.erase(make(b,a));
				d[a] = y+c[i];
				kol.insert(make(y+c[i],a));
			}
		}
	}
	if ( d[1] == 0 ) printf("-1");
	else printf("%d\n",d[1]);
}