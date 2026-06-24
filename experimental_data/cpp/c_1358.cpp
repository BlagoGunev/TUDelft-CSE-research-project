#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read(){
	ll num=0,neg=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
	while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
	return num*neg;
}

bool used[6][6][1000];
int cnt[6][6],f[6][6];


inline void dfs(int x,int y,int tmp){
	if(x>5||y>5)return;
	tmp+=f[x][y];if(!used[x][y][tmp]) used[x][y][tmp]=1,cnt[x][y]++;
	dfs(x+1,y,tmp),dfs(x,y+1,tmp);
}

ll T,sx,sy,tx,ty,delta,ans;

int main(){
	T=read();
	while(T--)
	{
		sx=read(),sy=read(),tx=read(),ty=read();
		delta=tx-sx;
		ans=1ll+(ty-sy)*delta;
		printf("%lld\n",ans);
	}return 0;
}