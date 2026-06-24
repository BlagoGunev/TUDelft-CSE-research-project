#include<bits/stdc++.h>

#define Cn const

#define CI Cn int&

#define N 200000

#define DB double

using namespace std;

namespace FastIO

{

	#define FS 100000

	#define Tp template<typename Ty>

	#define Ts template<typename Ty,typename... Ar>

	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)

	char oc,FI[FS],*FA=FI,*FB=FI;

	Tp void read(Ty& x) {x=0;while(!isdigit(oc=tc()));while(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}

	Ts void read(Ty& x,Ar&... y) {read(x),read(y...);}

}using namespace FastIO;

int n,X,Y,a[N+5];

class SegmentTree

{

	private:

		#define PT int l=1,int r=n,int o=1

		#define LT l,u,o<<1

		#define RT u+1,r,o<<1|1

		#define PU(o) (V[o]=V[o<<1]+V[o<<1|1])

		struct Data

		{

			DB a[3][3];

			friend Data operator + (Data A,Data B)

			{

				int x,y,p,q;Data t;for(x=0;x<=2;++x) for(y=0;y<=2;++y)

				for(t.a[x][y]=0,p=0;p<=2;++p) for(q=0;q<=2-p;++q) t.a[x][y]=max(t.a[x][y],A.a[x][p]+B.a[q][y]);return t;

			}

		}V[N<<2];

		Data G(int L,int R,PT)

		{

			if(L==l&&r==R) return V[o];int u=l+r>>1;return R<=u?G(L,R,LT):(L>u?G(L,R,RT):G(L,u,LT)+G(u+1,R,RT));

		}

	public:

		void Bd(PT)

		{

			if(l==r) return (void)(V[o].a[1][1]=1.0*a[l]/(X+Y),V[o].a[2][2]=1.0*a[l]/X);

			int u=l+r>>1;Bd(LT),Bd(RT),PU(o);

		}

		void U(int x,int v,PT)

		{

			if(l==r) return (void)(V[o].a[1][1]=1.0*v/(X+Y),V[o].a[2][2]=1.0*v/X);

			int u=l+r>>1;x<=u?U(x,v,LT):U(x,v,RT),PU(o);

		}

		DB Q(int L,int R)

		{

			Data t=G(L,R);int i,j;DB ans=0;for(i=0;i<=2;++i) for(j=0;j<=2;++j) ans=max(ans,t.a[i][j]);return ans;

		}

}S;

int main()

{

	int Qt,i,op,x,y;for(read(n,Qt,X,Y),X<Y&&(swap(X,Y),0),i=1;i<=n;++i) read(a[i]);S.Bd();

	while(Qt--) read(op,x,y),op==1?(S.U(x,y),0):printf("%.10lf\n",S.Q(x,y));return 0;

}