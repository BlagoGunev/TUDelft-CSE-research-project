#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int n,k,m;
int a[100];

ll qpow(ll x, ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return ans;
}
inline ll inv(ll x){
	return qpow(x,mod-2);
}

struct mat{
	ll a[51][51];
	void init(){
		memset(a,0,sizeof(a));
		for(int i=0; i<m; i++)
			a[i][i]=1;
	}
	void print(){
		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};

mat mul(mat a, mat b){
	mat ans;
	memset(ans.a,0,sizeof(ans.a));
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			for(int k=0; k<m; k++){
				ans.a[i][j]+=a.a[i][k]*b.a[k][j];
				ans.a[i][j]%=mod;
			}
		}
	}
	return ans;
}

mat matqpow(mat x, int y){
	mat ans;
	ans.init();
	while(y){
		if(y&1) ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}

int main(){
	scanf("%d%d",&n,&k);
	ll num[2]={0,0},x=0;
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		num[a[i]]++;
	}
	m=min(num[0],num[1])+1;
	for(int i=0; i<n; i++){
		if(a[i]==1 && i<num[0]) x++;
	}
	mat mymat;
	memset(mymat.a,0,sizeof(mymat.a));
	for(int i=0; i<m; i++){
		mymat.a[i][i]=(num[0]*num[0]+num[1]*num[1]-n+2*((num[1]-i)*i+(num[0]-i)*i))%mod*inv(n*(n-1))%mod;
		if(i) mymat.a[i][i-1]=2*i*i%mod*inv(n*(n-1))%mod;
		if(i!=m-1) mymat.a[i][i+1]=2*(num[0]-i)*(num[1]-i)%mod*inv(n*(n-1))%mod;
		//cout<<(mymat.a[i][i]+mymat.a[i][i+1]+mymat.a[i][i-1])%mod<<endl;
	}
	//mymat.print();
	mymat=matqpow(mymat,k);
	cout<<mymat.a[x][0]<<endl;
	return 0;
}