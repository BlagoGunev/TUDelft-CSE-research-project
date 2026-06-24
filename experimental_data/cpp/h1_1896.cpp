#include<bits/stdc++.h>
using namespace std;
const int P=998244353,N=(1<<8)+5;
int n,ln,rv[N],ans;
char s[N],t[N];
int A[N],B[N],f[N][N][N],g[N][N];
inline void Add(int &x,int y){
	if((x+=y)>=P)x-=P;
}
void solve(char *s){
	for(int i=0;i<ln;++i){
		f[i][0][0]=(s[i]!='1');
		f[i][1][0]=(s[i]!='0');
	}
	for(int mid=1;mid<ln;mid<<=1){
		for(int j=0,R=mid<<1;j<ln;j+=R){
			int l=j,r=j+mid;
			for(int cl=0;cl<=mid;++cl)for(int sl=0;sl<mid;++sl)if(f[l][cl][sl]){
				for(int cr=0;cr<=mid;++cr)for(int sr=0;sr<mid;++sr)if(f[r][cr][sr]){
					//printf("?%d %d %d %d %d %d\n",cl,sl,f[l][cl][sl],cr,sr,f[r][cr][sr]);
					Add(g[cl+cr][(sl&sr)|(cl==cr)*mid],1ll*f[l][cl][sl]*f[r][cr][sr]%P);
				}
			}
			for(int c=0;c<=R;++c)for(int s=0;s<R;++s)f[l][c][s]=g[c][s],g[c][s]=0;
			//printf("?%d %d\n",l,r);
		}
	}
}
int main(){
	scanf("%d",&n);
	ln=1<<n+1;
	for(int i=0;i<ln;++i)rv[i]=(rv[i>>1]>>1)|((i&1)<<n);
	scanf("%s%s",s,t);
	for(int i=0;i<ln;++i)if(i<rv[i])swap(s[i],s[rv[i]]),swap(t[i],t[rv[i]]);
	//printf("%s\n%s\n",s,t);
	solve(s);
	for(int S=0;S<ln;++S)A[S]=f[0][ln>>1][S];
	solve(t);
	for(int S=0;S<ln;++S)B[S]=f[0][ln>>1][S];
	//for(int S=0;S<ln;++S)printf("%d %d %d\n",S,A[S],B[S]);
	for(int S=0;S<ln;++S)for(int T=0;T<ln;++T)if((S|T)==ln-1)ans=(ans+1ll*A[S]*B[T])%P;
	printf("%d\n",ans);
	return 0;
}