#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,j,k) for(int i=j;i<=k;++i)
#define g(i,j,k) for(int i=j;i>=k;--i)
int n,m,s,l;
const int N=210,V=202,W=40404,K=1e9,inf=1e17;
inline void Max(int&x,int y){if(x<y)x=y;}
int t[N],a[N],b[N],rd[N],ans;
vector<int>p[N],q[N],r;queue<int>Q;
int f1[N][N*N],g1[N][N*N],h[N],f[N][N][N];
inline void clac(){
	f(x,0,n)f(i,0,V)f(j,0,V)f[x][i][j]=(i||j)*-inf;
	for(int x:r)f(i,0,V)f(j,0,V){
		int A=i,B=j,C=f[x][i][j];if(!i)Max(ans,C+h[x]);
		#define dp for(int y:p[x])Max(f[y][A][B],C);
		if(t[x]==0){
			dp
		}if(t[x]==1){
			f(w,a[x],(i?a[x]:V)){
				A=i+w-a[x];B=max(j,w);C=f[x][i][j]+w*b[x];dp
			}
		}if(t[x]==2){
			if(i>=a[x]){A-=a[x];dp}dp
		}if(t[x]==3){
			C+=a[x]*j;dp
		}if(t[x]==4){
			C+=a[x];dp
		}
	}
}
signed main(){
	cin>>n>>m;
	f(i,1,n){
		cin>>t[i];
		if(t[i])cin>>a[i];
		if(t[i]==1)cin>>b[i];
	}
	f(i,1,m){
		cin>>s>>l;
		p[s].push_back(l);
		q[l].push_back(s);
	}
	f(i,1,n)rd[i]=0;r.clear();
	f(x,1,n)for(int y:q[x])++rd[y];
	f(x,1,n)if(!rd[x])Q.push(x);
	for(int x;Q.size();Q.pop()){
		r.push_back(x=Q.front());
		for(int y:q[x])if(!(--rd[y]))Q.push(y);
	}
	f(x,0,n)f(i,0,W)f1[x][i]=-inf;f1[n][0]=0;
	for(int x:r)f(i,0,W){
		int A=i+(t[x]==2)*a[x],B=f1[x][i]+(t[x]==3)*a[x];
		int C=g1[x][i]+(t[x]==1)*a[x]*b[x]+(t[x]==4)*a[x];
		for(int y:q[x]){
			if(f1[y][A]<B)f1[y][A]=B,g1[y][A]=C;
			if(f1[y][A]==B)Max(g1[y][A],C);
		}
	}
	f(x,1,n)f(i,0,W)if(t[x]==1&&f1[x][i]>=0)Max(h[x],(a[x]+i)*(b[x]+f1[x][i])*K+g1[x][i]);
	reverse(r.begin(),r.end());
	clac();
	f(x,1,n){
		if(t[x]<2)swap(a[x],b[x]);
		if(t[x]&2)t[x]^=1;
	}
	clac();
	cout<<ans;
	return 0;
}