#include<bits/stdc++.h>
using namespace std;
const int N=705,P=998244353;
int n,ans,a[N],b[N],c[N],C[N][N],f[2][N][N],u[N][N],v[N][N],w[N][N];
int fadd(int x,int y){
	return (x+y>=P?x+y-P:x+y);
}
void init(){
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)	C[i][j]=fadd(C[i-1][j-1],C[i-1][j]);
	}
}
void getf(){
	u[0][0]=a[1],v[0][0]=b[1];
	for(int i=1;i<=n;i++){
		if(i==1)	f[1][1][0]=1;
		else{
			for(int j=1;j<i;j++)	for(int k=0;k<i;k++)	f[i&1][j][k]=0;
			for(int j=1;j<i;j++)	for(int k=0;k<i-1;k++){
				f[i&1][j][k]=fadd(f[i&1][j][k],1ll*f[(i-1)&1][j][k]*(k+1)%P);
				f[i&1][j+1][k+1]=fadd(f[i&1][j+1][k+1],f[(i-1)&1][j][k]);
				f[i&1][j][k+1]=fadd(f[i&1][j][k+1],1ll*f[(i-1)&1][j][k]*(i-k-2)%P);
			}
		}
		for(int j=1;j<=i;j++)	for(int k=0;k<i;k++){
			u[i][k]=fadd(u[i][k],1ll*f[i&1][j][k]*a[j+1]%P);
			v[i][k]=fadd(v[i][k],1ll*f[i&1][j][i-k-1]*b[j+1]%P);
		}
	}
}
void getw(){
	for(int i=0;i<=n;i++)	for(int j=0;j<=i;j++)	for(int k=0;k<n-j;k++)
		w[i][k]=fadd(w[i][k],1ll*u[i][j]*c[j+k+(i>0)]%P);
}
void solve(){
	for(int i=1;i<=n;i++){
		ans=0;
		for(int p=1;p<=i;p++)	for(int y=0;y<=i-p;y++)
			ans=fadd(ans,1ll*w[p-1][y]*v[i-p][y]%P*C[i-1][p-1]%P);
		cout<<ans<<" ";
	}
	cout<<endl;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)	cin>>b[i];
	for(int i=0;i<n;i++)	cin>>c[i];
	init(),getf(),getw(),solve();
	return 0;
}