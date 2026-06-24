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

const double eps=0.000000000000001 ;

#define MOD 1000000007

typedef long double LF;

typedef double lF;

//-------------

ll x1,x2,yy1,y2,vm,t,vx,vy,wx,wy;

LF dist(LF x,LF y)

{

	return sqrtl((LF)(x-x2)*(x-x2)+(y-y2)*(y-y2));

}

int isreach(LF tim)

{

	LF rx=x1,ry=yy1;

	rx+=vx*(min(tim,(LF)t));

	ry+=vy*(min(tim,(LF)t));

	if(tim>t)

	{

		rx+=wx*(tim-t);

		ry+=wy*(tim-t);

	}

	LF dd=dist(rx,ry);

	LF tak=dd/vm;

	if (tak<=tim||abs(tak-tim)<=0.0000000000001)

		return 1;

	else return 0;

}

int main()

{

	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",&x1,&yy1,&x2,&y2,&vm,&t,&vx,&vy,&wx,&wy);

	LF st=0,en=1000000000,ad=0.0000001,mid;

	while (en-st>=ad)

	{

		mid=(st+en)/2.0;

		//printf("%LF %LF %LF\n",st,en,mid);

		if (isreach(mid))

		{

			en=mid;

		}

		else st=mid+ad;

	}

	printf("%.25lf\n",(double)st);



	return 0;



}