#include<bits/stdc++.h>
using namespace std;

#define re register

template<typename T>
inline void read(T &x){
	re char ch=getchar();re bool f=false;x=0;
	while(!isdigit(ch)){if(ch=='-'){f=true;}ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	x=f?-x:x; return ;
}

template<typename T>
inline void write(T x){
	if(x<0){putchar('-');x=-x;}
	if(x>=10){write(x/10);}
	putchar(x%10+'0');
}

int const N=1e7+50;
bool isprime[N];
int prime[N],primecnt=0,f[N],g[N];
void Euler(int up){
	memset(isprime,false,sizeof(isprime));
	isprime[0]=isprime[1]=true;g[1]=1;f[1]=1;
	for(int i=2;i<=up;i++){
		if(!isprime[i]){
			prime[++primecnt]=i;
			g[i]=i+1;f[i]=i+1;
		}
		for(int j=1;j<=primecnt&&prime[j]*i<=up;j++){
			isprime[prime[j]*i]=true;
			if(i%prime[j]){
				f[prime[j]*i]=f[i]*f[prime[j]];
				g[prime[j]*i]=1+prime[j];
			}
			else{
				g[prime[j]*i]=g[i]*prime[j]+1;
				f[prime[j]*i]=f[i]/g[i]*g[prime[j]*i];
				break;
			}
		}
	}
}

int tong[N];

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int up=1e7+3;
	Euler(up);
	for(int i=1;i<=up;i++){
		if(f[i]>up) continue;
		if(!tong[f[i]]) tong[f[i]]=i;
	}
	int t; read(t);
	while(t--){
		int c; read(c);
		if(!tong[c]){
			puts("-1");
		}
		else{
			write(tong[c]);
			puts("");
		}
	}
	return 0;
}