#include <set>

#include <map>

#include <cmath>

#include <cstdio>

#include <vector>

#include <cstring>

#include <iostream>

#include <algorithm>



using namespace std;



#define pb push_back

#define mp make_pair

#define x first

#define y second



typedef long long ll;

typedef pair<int,int> pii;

typedef vector<int> vi;

typedef vector<pii> vpii;



template <class T>

void read(T &x)

{

	char ch;

	for (ch=getchar();(ch<'0'||ch>'9')&&ch!='-';) ch=getchar();

	x=0;int t=1;if (ch=='-') {ch=getchar();t=-1;}

	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';

	x*=t;

}



int m,a[100010],c[100010];



inline int lowbit(int x) {return x&(-x);}



void change(int x,int y)

{

	while (x<=m)

	{

		c[x]+=y;x+=lowbit(x);

	}

}



int query(int x)

{

	int s=0;

	while (x)

	{

		s+=c[x];x-=lowbit(x);

	}

	return s;

}



int main()

{

	#ifndef ONLINE_JUDGE

		freopen("input.txt","r",stdin);

		freopen("output.txt","w",stdout);

	#endif

	int n,q;read(n);read(q);m=n;

	for (int i=1;i<=n;i++) a[i]=1;

	memset(c+1,0,n*sizeof(int));

	for (int i=1;i<=n;i++) change(i,1);

	int k=0;bool rev=0;

	while (q--)

	{

		int op,l,r;read(op);read(l);

		if (op==1)

		{

			if (rev) {l=n-l;rev^=1;}

			if (l>n/2)

			{

				for (int i=l+1;i<=n;i++)

				{

					a[k+2*l+1-i]+=a[k+i];

					change(k+2*l+1-i,a[k+i]);

				}

				rev^=1;

				n-=(n-l);

			}

			else

			{

				for (int i=1;i<=l;i++)

				{

					a[k+2*l+1-i]+=a[k+i];

					change(k+2*l+1-i,a[k+i]);

				}

				k+=l;

				n-=l;

			}

		}

		else

		{

			read(r);

			if (rev) {l=n-l;r=n-r;swap(l,r);}

			printf("%d\n",query(k+r)-query(k+l));

		}

	}				

	return 0;

}