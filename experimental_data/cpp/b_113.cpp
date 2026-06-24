#include<bits/stdc++.h>

using namespace std;

#define pc putchar_unlocked

#define gc getchar_unlocked

typedef long long ll;

typedef unsigned long long llu;

#define mp make_pair

#define pb push_back

#define sc(x) scanf("%d",&x)

#define sc2(x,y) scanf("%d%d",&x,&y)

#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define scl(x) scanf("%lld",&x)

#define scl2(x,y) scanf("%lld%lld",&x,&y)

#define scl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

#define scstr(x) scanf("%s",x)

#define pd(x) printf("%d",x)

#define pstr(x) printf("%s",x)

#define newl() printf("\n")

#define fl(i,n) for (i=0;i<n;i++)

#define fle(i,n) for (i=1;i<=n;i++)

#define fla(i,a,n) for (i=a;i<n;i++)

#define mem(a,i) memset(a,i,sizeof(a))

#define fi first

#define se second

typedef pair<int,int> pii;

typedef pair<int,pair<int,int> > piii ;

typedef pair<ll,ll> pll;

typedef pair<ll,int> pli;

#define gcd __gcd

#define wl(n) while (n--)

#define debug(x) cout<<"debug->"<<#x<<"::"<<x<<endl

#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n"

#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n"

#define tr(container, it)  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 

#define all(v) v.begin(),v.end()

#define tatt(cont) typeof(cont.begin())

const double eps=0.000000000000001 ;

#define MOD 1000000007

typedef long double LF;

typedef double lF;

#define hihihaha ((double)CLOCKS_PER_SEC)

//-------------



const int lolwa=3*2010; //   LIMITS are to be set here --------------------------------------------------------------- >

char s[lolwa];

struct node

{

	int r[2],p;

}L[lolwa];

int P[32][lolwa],sttp;

bool cmp(node,node);

void maksort(node *,int);

int rnk[lolwa]; // Note always needed

int lcp(int x,int y,int stp,int l)

{

	int k,ret=0;

	if (x==y)

		return l-x;

	for (k=stp-1;k>=0&&x<l&&y<l;k--)

	{

		if (P[k][x]==P[k][y])

		{

			x+=1<<k;y+=1<<k;ret+=1<<k;

		}

	}

	return ret;

	

}

void buildit(char *s,int l)

{

	if (l==-1)

	{

		l=strlen(s);

	}

	int i,j;

	for (i=0;i<l;i++)

	{

		P[0][i]=s[i];

	}

	int stp=1,cnt=1;

	for (;(cnt>>1)<l;cnt<<=1,stp++)

	{

		for (i=0;i<l;i++)

		{

			L[i].r[0]=P[stp-1][i];

			L[i].r[1]=(i+cnt<l?P[stp-1][(i+cnt)]:-1);

			L[i].p=i;

		}

		maksort(L,l); // O(n) sorting

		//sort(L,L+l,cmp); // n logn sorting 

		for (i=0;i<l;i++)

		{

			P[stp][L[i].p]=((i>0&&L[i-1].r[0]==L[i].r[0]&&L[i-1].r[1]==L[i].r[1])?P[stp][L[i-1].p]:i);

		}

		

	}

	sttp=stp;

	for (i=0;i<l;i++)

	{

		rnk[P[stp-1][i]]=i;

	}



}

int l1,l2,lm,l;

char sm[2010],s1[2010],s2[2010];

int pre[2010];

int *makeprefix(char *s,int n)

{

	int *a=pre;

	a[1]=0;

	int i,k=0;

	for (i=2;i<=n;i++)

	{

		while (k>0&&s[k+1]!=s[i])

			k=a[k];

		if (s[k+1]==s[i])

			k++;

		a[i]=k;

		

	}

	return a;

}

int itna[3*2010];

void doit(char *hay,char *s,int l1,int l) // l1 is of hay and l is that of pattern

{

	int i,k=0;

		for (i=1;i<=l1;i++)

			{

				while (k>0&&s[k+1]!=hay[i])

					k=pre[k];

				if (s[k+1]==hay[i])

					k++;

				if(k==l){

					//printf("%d\n",i-l);

					//cerr<<"match found !\n";

					itna[i-1]++;

					k=pre[k];

				}

		

			}

	for (i=l1-1;i>=0;i--)

		itna[i]=itna[i+1]+itna[i];

}

int mx[3*2010];

int main()

{

	int i,j;

	scstr(sm);

	scstr(s1);

	scstr(s2);

	lm=strlen(sm);

	l1=strlen(s1);

	l2=strlen(s2);

	strcpy(s,s1);

	strcat(s,"#");

	strcat(s,sm);

	l=strlen(s);

	//cerr<<s<<endl;

	buildit(s,l);

	makeprefix(s2-1,l2);

	int yo=l1+1;

	doit(s-1,s2-1,l,l2);

	ll ans=0;

	int yesyes=max(l1,l2);

	/*for (i=0;i<l;i++)

	{

		cerr<<i<<" : "<<itna[i]<<endl;

	}*/

	for (i=0;i<l;i++)

	{

		if (rnk[i]<yo)

			continue;

		//cerr<<"got to rank :"<<i<<" having index "<<rnk[i]<<endl;

		for (j=i+1;j<l;j++)

			if (rnk[j]>=yo)

				break;

		int hala=lcp(rnk[i],0,sttp,l);

		assert(hala<=l1); // because of "#" symbol! 

		if (hala>=l1)

		{

			int added=max(yesyes-1,mx[i]);

			//cerr<<"added evaluated as "<<added<<endl;

			if (rnk[i]+added<l)

			{

				ans+=itna[rnk[i]+added];

			}

		}

		if (j<l)

			mx[j]=max(mx[j],lcp(rnk[i],rnk[j],sttp,l));

		i=j-1;



	}

	printf("%lld\n",ans);

	return 0;

}

bool cmp(node a,node b)

{

	if (a.r[0]==b.r[0])

		return a.r[1]<b.r[1];

	return a.r[0]<b.r[0];

}

int rad_[lolwa]={0};

node L_[lolwa];



void maksort(node *L,int l)

{

	int i,j;

	int *rad=((int *)rad_)+1;

	

	for (j=1;j>=0;j--)

	{

		memset(rad_,0,sizeof(rad_)); //   ---------- Change the size in case of TLE! 

		int maxi=0;

		for (i=0;i<l;i++)

		{

			rad[L[i].r[j]]++;

			if (L[i].r[j]>maxi)

				maxi=L[i].r[j];

		}

		for (i=0;i<=maxi;i++)

			rad[i]=rad[i-1]+rad[i];

		for (i=l-1;i>=0;i--)

		{

			L_[--rad[L[i].r[j]]]=L[i];

		}

		for (i=0;i<l;i++)

			L[i]=L_[i];

	}

}