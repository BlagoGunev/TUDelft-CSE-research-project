#include<cstdio>

#include<cstring>

#include<algorithm>

#define int long long 

using namespace std;

inline int read(){int x=0,f=1,ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();} while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} return x*f;}

inline void write(int x){if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10); putchar(x%10+'0');}

inline void writeln(int x){write(x); puts("");}

const int N=1005,mod=1e9+7;

int n,l,r,z,C[N][N];

inline void init(){

	n=read(); l=read(); r=read(); z=read();

}

int f[65][N];

inline void upd(int &x,int v){

	x=(x+v)%mod;

}

inline int calc(int x){

	memset(f,0,sizeof f);

	f[61][0]=1;

	for (int i=60;i>=0;i--){

		for (int j=0;j<=n;j++){

			int sum=2*j+(x>>i&1);

			for (int k=(z>>i&1);k<=n&&k<=sum;k+=2){

				upd(f[i][min(sum-k,n)],f[i+1][j]*C[n][k]%mod);

			}

		}

	}

	int ans=0;

	for (int i=0;i<=n;i++) upd(ans,f[0][i]);

	return ans;

}

inline void solve(){

	C[0][0]=1;

	for (int i=1;i<=n;i++){

		C[i][0]=1; 

		for (int j=1;j<=i;j++) {

			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;

		}

	}

	writeln((calc(r)-calc(l-1)+mod)%mod); 

}

signed main(){

	init(); solve();

	return 0;

}