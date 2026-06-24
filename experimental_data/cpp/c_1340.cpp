#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

#define pii pair<int,int>

#define fi first

#define se second

#define mp make_pair

#define poly vector<ll>

#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)

#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)

#define pb push_back

inline ll read(){

	ll x=0; char ch=getchar(); bool d=1;

	for(;!isdigit(ch);ch=getchar()) if(ch=='-') d=0;

	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';

	return d?x:-x;

}

inline ull rnd(){

	return ((ull)rand()<<30^rand())<<4|rand()%4;

}

const int N=2e5+5;

int f[10005][1005],m,pos[N],G,R,n,ans=0x3f3f3f3f;

bool used[10005][1005];

deque<pii> q;

#define pf push_front

void bfs(){

	q.pb(mp(0,G)); used[0][G]=1;

	while(q.size()){

		pii nod=q.front(); q.pop_front();

		int x=nod.fi,y=nod.se;

		// cout<<x<<" "<<y<<endl;

		if(pos[x]+y>=m){

			ans=min(ans,f[x][y]*(R+G)+G-y+m-pos[x]);

		}

		if(x<n&&y>=pos[x+1]-pos[x]){

			if(y==pos[x+1]-pos[x]){

				if(!used[x+1][G]){

					f[x+1][G]=f[x][y]+1;

					used[x+1][G]=1;

					q.pb(mp(x+1,G));

				}

			}else{

				if(!used[x+1][y-pos[x+1]+pos[x]]){

					f[x+1][y-pos[x+1]+pos[x]]=f[x][y];

					used[x+1][y-pos[x+1]+pos[x]]=1;

					q.pf(mp(x+1,y-pos[x+1]+pos[x]));

				}

			}

		}

		if(x&&y>=pos[x]-pos[x-1]){

			if(y==pos[x]-pos[x-1]){

				if(!used[x-1][G]){

					f[x-1][G]=f[x][y]+1;

					used[x-1][G]=1;

					q.pb(mp(x-1,G));

				}

			}else{

				if(!used[x-1][y-pos[x]+pos[x-1]]){

					f[x-1][y-pos[x]+pos[x-1]]=f[x][y];

					used[x-1][y-pos[x]+pos[x-1]]=1;

					q.pf(mp(x-1,y-pos[x]+pos[x-1]));

				}

			}

		}

	}

}

int main(){

	m=read(); n=read();

	For(i,1,n) pos[i]=read();

	sort(pos+1,pos+n+1);

	G=read(); R=read();

	bfs(); cout<<(ans==0x3f3f3f3f?-1:ans);

}