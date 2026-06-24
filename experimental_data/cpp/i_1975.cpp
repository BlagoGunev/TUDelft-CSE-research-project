#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=242;
const int MOD=1e9+7;
int S[N][N];
long long inv[N];
long long f[N][N][N],d[N][N];
int ss[N];
int a[N];
bool hav[N];
long long C[N*2][N*2];
long long qpow(long long x,long long y,long long mod){
	if(!y)return 1%mod;
	if(y==1)return x%mod;
	long long kp=qpow(x,y/2,mod);
	if(y&1)return kp*kp%mod*x%mod;
	return kp*kp%mod; 
}
signed main(){
	//freopen("1.txt","r",stdin);
	//int tim1=clock();
	for(int i=1;i<=240;i++)inv[i]=qpow(i,MOD-2,MOD);
	C[0][0]=1;
	for(int i=1;i<=240;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
	int T;
	cin>>T;
	while(T--){
		int n;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		string s;
		cin>>s;
		int cnt=0,sumc=0;
		for(int i=0;i<n;i++){
			hav[i+1]=s[i]-'0';
			ss[i+1]=ss[i]+hav[i+1];
		}
		for(int i=1;i<=n;i++)cnt+=hav[i],sumc+=hav[i]*a[i];
		if(a[n]<=1){
			if(cnt==n)cout<<1<<"\n";
			else cout<<0<<"\n";
			continue;
		}
		if(!cnt){
			cout<<0<<"\n";
			continue;
		}
		if(a[1]>0){
			cout<<1<<"\n";
			continue;
		}
		if(sumc==0){
			cout<<0<<"\n";
			continue;
		}
		for(int l=1;l<=n;l++){
				for(int sum=n;sum>=0;sum--){
					for(int c=0;c<=n;c++)f[l][sum][c]=0;
				}
		}
		for(int l=n;l>=1;l--){
			if(a[l]<=0)continue;
			for(int sum=l-1;sum>=0;sum--){
				for(int r=0;r<=n;r++){
					for(int c=0;c<=n;c++)S[r][c]=0;
				}
				S[n][a[l]]=1;
				for(int r=n;r>=l;r--){
					for(int c=n;c>=a[l];c--){
						if(sum+c>r)continue;
						if(l==r&&c==1){
							S[r-1][c]=(S[r-1][c]*1ll+(r-sum-c)*inv[r-sum]%MOD*S[r][c])%MOD;
							for(int x=a[r];x<=r-c;x++){
								S[r-1][c-1+x]=S[r-1][c-1+x]*1ll*qpow((MOD+1-c*inv[r-sum]%MOD*S[r][c]%MOD)%MOD,MOD-2,MOD)%MOD;
							}
						}
						else{
							int ccc=c*inv[r-sum]%MOD*S[r][c]%MOD;
							for(int x=a[r];x<=r-c;x++){
								S[r-1][c-1+x]=(S[r-1][c-1+x]*1ll+f[r][sum+c-1][x]*ccc)%MOD;
							}
							S[r-1][c]=(S[r-1][c]*1ll+(r-sum-c)*inv[r-sum]%MOD*S[r][c])%MOD;
						}
					}
				}
				for(int c=a[l];c<=n;c++){
					f[l][sum][c]=S[l-1][c];
					//if(f[l][sum][c])cout<<l<<" "<<sum<<" "<<c<<":"<<f[l][sum][c]<<"\n"; 
				}
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=0;j<=i-1;j++){
				for(int k=0;k<=i-1;k++){
					if(f[i][j][k])cout<<i<<" "<<j<<" "<<k<<":"<<f[i][j][k]<<"\n"; 
				}
			}
		}*/
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++)d[i][j]=0;
		}
		for(int i=n;i>=1;i--){
			if(hav[i]){
				d[cnt][i]=1;
				break;
			}
		}
		long long ans=0;
		for(int x=n;x>=1;x--){
			if(a[x]==0){
				for(int sum=x;sum>=0;sum--){
					ans+=d[sum][x];
					ans%=MOD; 
				}
				break;
			}
			for(int sum=x;sum>=ss[x];sum--){
				//have
				long long prob;
				if(hav[x])prob=1;
				else{
					prob=(sum-ss[x])*inv[(x-ss[x])]%MOD;
				}
				for(int t=a[x];t<=n;t++){
					if(sum+t>x)break;
					d[sum-1+t][x-1]=(d[sum-1+t][x-1]+d[sum][x]*prob%MOD*f[x][sum-1][t])%MOD;
				}
				if(sum<=x-1)d[sum][x-1]=(d[sum][x-1]+d[sum][x]*(MOD+1-prob))%MOD;
			}
		}
		cout<<(MOD+1-ans)%MOD<<"\n";
	}
	//int tim2=clock();
	//cout<<tim2-tim1<<"\n";
	return 0; 
}