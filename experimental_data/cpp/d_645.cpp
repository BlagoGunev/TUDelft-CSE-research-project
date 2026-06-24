/*

._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._

	ABHINANDAN AGARWAL

	MNNIT ALLAHABAD

	CSE

._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._

*/

#include<bits/stdc++.h>

using namespace std;

#define pc putchar

#define gc getchar

typedef long long ll;

typedef unsigned long long llu;

#define mp make_pair

#define pb push_back

#define sc(x) scanf("%d",&x);

#define fl(i,n) for (i=0;i<n;i++)

#define fle(i,n) for (i=1;i<=n;i++)

#define fla(i,a,n) for (i=a;i<n;i++)

#define mem(a,i) memset(a,i,sizeof(a))

#define fi first

#define se second

#define pii pair<int,int> 

#define piii pair<int,pair<int,int> >

#define wl(n) while (n--)



int fs()

{

	int x=0;

	char c;

	c=getchar();

	while (c<'0'||c>'9')

		c=getchar();

	while ('0'<=c&&c<='9')

	{

		x=(x<<3)+(x<<1)+c-'0';

		c=getchar();

	}

	return x; 

}

void pps(const char *s)

{

	int i;

	for (i=0;s[i]!='\0';i++)

	{

		putchar(s[i]);

	}

}

void _ppd(int a)

{

	if (a==0)

		return ;

	_ppd(a/10);

	putchar(a%10+'0');

}

void ppd(int a) // Printing integer using utchar unlocked!

{

	if (a==0)

	{

		pc('0');

		return;

	}

	if (a<0)

	{

		pc('-');

		a=-a;

	}

	_ppd(a);

}

void _pplld(ll a)

{

	if (a==0)

		return ;

	_pplld(a/10);

	pc(a%10+'0');

}

void pplld(ll a)

{

	if (a==0)

	{

		pc('0');

		return ;

	}

	if (a<0)

	{

		pc('-');

		a=-a;

	}

	_pplld(a);

}

int ggs(char *s) // String inputting

{

	int x=0;

	char c=gc();

	while (!('a'<=c&&c<='z')&&c!=-1) // change conditions to whatever strings can input !

		c=gc();

	while ('a'<=c&&c<='z')

	{

		s[x++]=c;

		c=gc();

	}

	s[x]='\0';

	return x;

}



int fsn()

{

	int x=0;

	char c;

	c=getchar();

	while (!('0'<=c&&c<='9'||c=='-'))

		c=getchar();

	int neg=0;

	if (c=='-'){

		neg=1;

		c=getchar();

	}

	while ('0'<=c&&c<='9')

	{

		x=(x<<3)+(x<<1)+c-'0';

		c=getchar();

	}

	return (neg==0?x:-x); 

}

//------------------------------------------------------------------------------------

vector<pii>gr[100010];

int in[100010]={0},n,m,ans=0;

// Shortest Fucking code.. 

int topo()

{

	int i,j,cnt=0,el,z,cc=0;

	for(i=1;i<=n;i++)

		if (in[i]==0)

		{	cnt++;el=i;}

	if (cnt!=1)

		return 0;



	while(cnt>0)

	{

		if (cnt>1)

			return 0;

		z=gr[el].size();int c=el;

		cnt--;cc++;

		fla(i,0,z)

			if ((--in[gr[c][i].fi])==0)

			{

				ans=max(ans,gr[c][i].se);

				cnt++;

				el=gr[c][i].fi;

			}

		

	}



	return cc==n;

}

int main()

{

	int i,j,x,y;

	n=fs();m=fs();	

	fla(i,0,m)

	{

		x=fs();y=fs();

		gr[x].pb(mp(y,i+1));

		in[y]++;

	}

	if (!topo())

	{

		pps("-1\n");

		return 0;

	}

	ppd(ans);pc('\n');

	//printf("%d\n",ans);

	return 0;



}