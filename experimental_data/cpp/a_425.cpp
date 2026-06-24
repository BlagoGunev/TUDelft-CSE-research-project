#include<bits/stdc++.h>

using namespace std;



#define test() int t;scanf("%d",&t);for(int tno=1;tno<=t;tno++)



#define mp make_pair

#define pb push_back

#define wl(n) while(n--)

#define fi first

#define se second

#define all(c) c.begin(),c.end() //eg sort(all(v));



typedef long long ll;

typedef unsigned long long llu;

typedef double lf;

typedef vector<int> vi; 

typedef vector< vi > vvi; 

typedef pair<int,int> pii;

typedef pair<int,pair<int,int> > piii ;



#define sz(a) int((a).size())

#define ini(a) memset(a,-1,sizeof(a))





// Input Output

#define sc(n) scanf("%d",&n)

#define sc2(n,m) sc(n), sc(m)

#define scs(s) scanf("%s",s);

#define pd(n) printf("%d",n)



#define scl(n) scanf("%lld",&n)

#define scl2(n,m) scanf("%lld%lld",&n,&m)

#define pdl(n) printf("%lld",n)

#define newln printf("\n")

#define space printf(" ")



//Bitwise

#define chkbit(s, b)    (s & ((ll)1<<b))

#define setbit(s, b)    (s |= ((ll)1<<b))

#define clrbit(s, b)    (s &= ~(1<<b))



//constants

#define MOD 1000000007

#define MOD_INV 1000000006

#define MAX 100009



//Error check

#define debug() printf("here\n")

#define PV(v)       	{ for(int i=0;i<v.size();i++) printf("%d ",v[i]);printf("\n"); }

#define PA(a,st,ed)     { for(int i=st;i<=ed;i++) printf("%d ",a[i]);printf("\n"); }  

#define chk(a) cerr << endl << #a << " : " << a << endl

#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl



//-----------------------------------------------------------------------------------------------



pii a[MAX];

int cmpp(pii a,pii b)// don't know why .. when i didn't write the cmpp function .. sort was sorting correctly but the answer after 

{							// computation came 30 for the first sample ... just by adding the cmpp function it changed to 32 -_-

	if(a.fi==b.fi)

		return a.se>b.se;

	else

		return a.fi>b.fi;

}

int main()

{

	int i,j,k;

	int n;

	sc2(n,k);

	for(i=0;i<n;i++){

		int l;

		sc(l);

		a[i] = mp(l,i);

	}

	sort(a,a+n,cmpp);

	/*for(i=0;i<n;i++){

		printf("%d ",a[i].X);

	}

	newln;*/

	int ans=INT_MIN;

	for (i=0;i<n;i++)

	{

		for (j=i;j<n;j++)

		{

			int z,ele=j-i+1,sm=0,p=k;

			for (z=0;z<n&&ele>0;z++)

			{

				if (i<=a[z].se&&a[z].se<=j)

				{

					ele--;

					sm+=a[z].fi;

				}

				else if (p>0)

				{

					sm+=a[z].fi;

					p--;ele--;



				}

			}

			ans=max(ans,sm);

		}



	}

	printf("%d\n",ans);

	return 0;

}