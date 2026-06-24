#include<map>
#include<set>
#include<ctime>
#include<queue>
#include<cmath>
#include<bitset>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mp(x,y) make_pair(x,y)
#define qmin(x,y) (x=min(x,y))
#define qmax(x,y) (x=max(x,y))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline int read(){
	int ans=0,fh=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') fh=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		ans=(ans<<1)+(ans<<3)+ch-'0',ch=getchar();
	return ans*fh;
}
const int maxn=2e5+100,P=998244353;
int n,a[maxn],len,s[maxn];
ll k,f[maxn],g[maxn],cnt;
ll Ans=1;
inline void ycl(){
	f[2]=0,g[2]=1;
	for(int i=3;i<=n;i++){
		f[i]=g[i-1]*(k-1)%P;
		g[i]=g[i-1]*(k-2)%P+f[i-1];
		g[i]%=P;
	}
}
inline void work(){
	int las=1;
	for(int i=1;i<=len;i++){
		if(s[i]!=-1){
			if(las==i){
				las++;
				continue;
			}
			if(las==1){
				Ans=Ans*((k-1)%P*g[i]%P+f[i])%P;
				Ans%=P;
			}
			else{
				if(s[las-1]==s[i])
					Ans=Ans*f[i-las+2]%P;
				else Ans=Ans*g[i-las+2]%P;
			}
			las=i+1;
		}
	}
	if(las!=len+1){
		if(las==1){
			if(len>1) Ans=Ans*(1ll*k*f[len]%P+1ll*k*(k-1)%P*g[len]%P)%P;
			else Ans=Ans*k%P;
		}
		else{
			Ans=Ans*((k-1)%P*g[len-las+2]%P+f[len-las+2])%P;
			Ans%=P;
		}
	}
}
int main(){
//	freopen("nh.in","r",stdin);
	//freopen("zhy.out","w",stdout);
	n=read(),k=read(),ycl();
	if(n==1){
		printf("%I64d\n",k);
		return 0;
	}
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i+2<=n;i++){
		if(a[i]==-1) continue;
		if(a[i]==a[i+2]){
			printf("0\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i+=2) s[++len]=a[i];
	work();
	len=0;
	for(int i=2;i<=n;i+=2) s[++len]=a[i];
	work();
	printf("%I64d\n",Ans);
	return 0;
}