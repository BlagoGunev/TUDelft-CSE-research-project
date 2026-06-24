#include <bits/stdc++.h>

using namespace std;

#define pf pop_front

#define pb push_back

#define FOR(i,begin,end) for (LL i=begin;i<=end;i++)

#define rep(i,t) for (LL i=0;i<t;i++)

#define pii pair<LL,LL>

#define X first

#define Y second

typedef long long LL;

typedef unsigned long long int ulli;

const LL maxN=5e1+7,N=5e1+7,inf=1e9+7,MOD=1e9+7,Mod=1e9+6;

LL k,x,n,m,e[maxN],s[maxN],dp[maxN][6],cnt,ln,lm,cs[maxN],ce[maxN],help,pos,len;

string str;

char ss,se,es,ee;

void print(char a,char b,LL x,LL y)

{

	LL count=0;

	if(x==1)

		cout<<a<<"\n";

	else

	{

		if(a=='A')

		{

			if(y)

				cout<<"AC",count=2;

			else

				cout<<a,count=1;

			FOR(i,1,y-1)

				cout<<"AC",count+=2;

			FOR(i,count+1,x-1)

				cout<<"B";

			cout<<b<<"\n";

		}

		else

		{

			if(b=='C')

			{

				str.clear();

				if(y)

					str+="CA",count=2;

				else

					str+="C",count=1;

				FOR(i,1,y-1)

					str+="CA",count+=2;

				FOR(i,count+1,x-1)

					str+="B";

				str+=a;

				reverse(str.begin(),str.end());

				cout<<str<<"\n";

			}

			else

			{

				cout<<a;

				count=1;

				FOR(i,1,y)

					count+=2,cout<<"AC";

				FOR(i,count+1,x-1)

					cout<<"B";

				cout<<b<<"\n";

			}

		}

	}

}

int main()

{

	cin>>k>>x>>n>>m;

	if(!x)

	{

		FOR(i,1,n)

			cout<<"B";

		cout<<"\n";

		FOR(i,1,m)

			cout<<"B";

		return cout<<"\n",0;

	}

	e[1]=s[1]=1;

	s[2]=e[2]=2;

	cs[1]=1;

	ce[2]=1;

	FOR(i,2,k)

		e[i]=2;

	FOR(i,3,k)

	{

		FOR(j,1,4)

			dp[i][j]=dp[i-1][j]+dp[i-2][j];

		cs[i]=cs[i-1]+cs[i-2];

		ce[i]=ce[i-1]+ce[i-2];

		s[i]=(i%2)?s[1]:s[2];

		if(e[i-2]==1)

		{

			if(s[i-1]==1)

				dp[i][1]++;

			else

				dp[i][2]++;

		}

		else

		{

			if(s[i-1]==1)

				dp[i][3]++;

			else

				dp[i][4]++;

		}

	}

	rep(i,3)

	{

		rep(j,3)

		{

			rep(l,3)

			{

				rep(t,3)

				{

					ss=se=es=ee='A';ss+=i;se+=j;es+=l;ee+=t;ln=n-2;lm=m-2;

					if(n==1)

						ss=se;

					if(m==1)

						es=ee;

					cnt=0;

					if(se=='A' && es=='C')

						cnt+=dp[k][2];//1 2

					if(se=='A' && ss=='C')

						cnt+=dp[k][1];//1 1

					if(ee=='A' && ss=='C')

						cnt+=dp[k][3];//2 1

					if(ee=='A' && es=='C')

						cnt+=dp[k][4];//2 2

					if(se=='C' || ss=='A')

						ln++;

					if(es=='A' || ee=='C')

						lm++;

					if(n==2 && ss=='A' && se=='C')

						cnt+=cs[k];

					if(m==2 && es=='A' && ee=='C')

						cnt+=ce[k];

					ln/=2;

					lm/=2;

					rep(xx,ln+1)

					{

						help=(xx*cs[k])+cnt;

						if(x>=help)

						{

							if(!((x-help)%ce[k]) || x==help)

							{

								pos=(x-help)/ce[k];

								if(pos<=lm)

								{

									print(ss,se,n,xx);

									print(es,ee,m,pos);

									return cout<<"\n",0;

								}

							}

						}

					}

				}

			}

		}

	}

	return cout<<"Happy new year!\n",0;

}