/*

                ____________    ______________       __

               / _________  /\ /_____   _____/\     / /\

              / /\       / /  \\    /  /\    \ \   / /  \

             / /  \_____/ /   / \__/  /  \____\/  / /   /

            / /   /    / /   /    /  /   /       / /   /

           / /   /    / /   /    /  /   /       / /   /

          / /   /    / /   /    /  /   /       / /   /

         / /___/____/ /   /    /  /   /       / /___/________

        /____________/   /    /__/   /       /______________/\

        \            \  /     \  \  /        \              \ \

         \____________\/       \__\/          \______________\/

           ___       ___               ___    __________

          /  /\     /  /\             /  /\  /_______  /\

         /  /__\___/  /  \           /  /  \ \      /  /  \

        /____    ____/   /          /  /   /  \____/  /   /

        \   /   /\   \  /          /  /   /       /  /   /

         \_/   /  \___\/ ___      /  /   /       /  /   /

          /   /   /     /  /\    /  /   /       /  /   /

         /   /   /     /  /__\__/  /   /       /  /___/____

        /___/   /     /___________/   /       /___________/\

        \   \  /      \           \  /        \           \ \

         \___\/        \___________\/          \___________\/

       

          A FAN OF FIZZYDAVID

           

*/

 

#include<bits/stdc++.h>

 

#define HEAP priority_queue

#define rep(i,n) for(int i=0;i<(n);i++)

#define per(i,n) for(int i=(n)-1;i>=0;i--)

#define forn(i,l,r) for(int i=(l);i<=(r);i++)

#define nrof(i,r,l) for(int i=(r);i>=(l);i--)

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define mp make_pair

#define pb push_back

#define X first

#define Y second

#define eps 1e-20

#define pi 3.1415926535897932384626433832795

#define orz int

#define yjz main

#define fizzydavid return

#define ak 0

#define la ;

#define debug puts("OK");

#define SZ(x) (int)x.size()

#define ALL(x) x.begin(),x.end()

 

using namespace std;

 

typedef long long LL;

typedef double flt;

typedef vector<int> vi;

typedef pair<int,int> pii;

 

const int iinf=1e9+7;

const LL linf=1ll<<60;

const flt dinf=1e10;



void scf(int &x)

{

	bool f=0; x=0; char c=getchar();

	while((c<'0' || c>'9') && c!='-') c=getchar();

	if(c=='-') { f=1; c=getchar(); }

	while(c>='0' && c<='9') { x=x*10+c-'0';   c=getchar(); }

	if(f) x=-x; return;

}



void scf(int &x,int &y) { scf(x); return scf(y); }



void scf(int &x,int &y,int &z) { scf(x); scf(y); return scf(z); }



//---------------------------head----------------------------



const int _pow[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

const int beg[]={1990,1991,1992,1993,1994,1995,1996,1997,1998,1989};



char str[20];



orz yjz()

{

	int T; scf(T);

	while(T--)

	{

		scanf("%s",str);

		int i=(int)strlen(str)-2,cnt=1,num=str[i+1]-'0',ans=beg[num]+10;

		while(str[i]>='0' && str[i]<='9')

		{

			num+=_pow[cnt]*(str[i]-'0');

			while((ans%_pow[cnt+1])!=num) ans+=_pow[cnt];

			i--; cnt++;

			ans+=_pow[cnt];

		}

		ans-=_pow[cnt];

		printf("%d\n",ans);

	}

	fizzydavid ak la

}