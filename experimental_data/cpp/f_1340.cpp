// LUOGU_RID: 102229522
#include<bits/stdc++.h>
#define int long long
#define N 200005
#define T 405
using namespace std;
int read(){
	int w=0,h=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')h=-h;ch=getchar();}
	while(ch>='0'&&ch<='9'){w=w*10+ch-'0';ch=getchar();}
	return w*h;
}
const int base=1145141,mod=1e9+7;
int n,q,t,a[N],bel[N],Base[N];
int L[T],R[T],stk[T+5],top;bool ill[T];
vector<int>brac[2][T];int H[T][T+5],HH[T];
struct Node{int u,l,r,hs;}STK[N];
int Substr(int u,int l,int r){return(H[u][l]-H[u][r+1]*Base[r-l+1]%mod+mod)%mod;}
void Rebuild(int u){
	top=ill[u]=0;brac[0][u].clear();brac[1][u].clear();
	for(int i=L[u];i<=R[u];i++)
		if(a[i]>0)stk[++top]=a[i];
		else{
			if(top&&stk[top]+a[i])return void(ill[u]=true);
			if(!top)brac[0][u].push_back(-a[i]);
			else top--;
		}
	while(top)brac[1][u].push_back(stk[top--]);
	for(int i=0;i<=T;i++)H[u][i]=0;HH[u]=0;
	for(int i=0;i<brac[0][u].size();i++)(HH[u]+=brac[0][u][i]*Base[i]%mod)%=mod;
	for(int i=brac[1][u].size()-1;~i;i--)
		H[u][i]=(H[u][i+1]*base%mod+brac[1][u][i])%mod;
}
void Modify(int x,int y){a[x]=y;Rebuild(bel[x]);}
bool Query(int l,int r){
	int p=bel[l],q=bel[r];top=0;
	if(p==q){
		for(int i=l;i<=r;i++)
			if(a[i]>0)stk[++top]=a[i];
			else{
				if(top&&stk[top]+a[i]==0)top--;
				else return false;
			}
		return top==0;
	}
	for(int i=p+1;i<q;i++)if(ill[i])return false;
	for(int i=l;i<=R[p];i++)
		if(a[i]>0)STK[++top]=(Node){p,-1,-1,a[i]};
		else{
			if(!top)return false;Node x=STK[top--];
			if(((x.l==-1)?x.hs:Substr(x.u,x.l,x.l))+a[i])return false;
			if(x.l!=x.r)STK[++top]=(Node){x.u,x.l+1,x.r,Substr(x.u,x.l+1,x.r)};
		}
	for(int i=p+1;i<q;i++){
		int len=brac[0][i].size(),lenlen=0,hs=0;
		while(top&&len){
			Node x=STK[top--];int L=x.r-x.l+1;
			if(len<=L){
				if(x.l==-1)(hs+=x.hs*Base[lenlen]%mod)%=mod;
				else(hs+=Substr(x.u,x.l,x.l+len-1)*Base[lenlen]%mod)%=mod;
				if(len<L)STK[++top]=(Node){x.u,x.l+len,x.r,Substr(x.u,x.l+len,x.r)};
				len=0;break;
			}
			else(hs+=x.hs*Base[lenlen]%mod)%=mod,len-=L,lenlen+=L;
		}
		if(len||hs!=HH[i])return false;
		if(!brac[1][i].empty())STK[++top]=(Node){i,0,brac[1][i].size()-1,H[i][0]};
	}
	for(int i=L[q];i<=r;i++)
		if(a[i]>0)STK[++top]=(Node){q,-1,-1,a[i]};
		else{
			if(!top)return false;Node x=STK[top--];
			if(((x.l==-1)?x.hs:Substr(x.u,x.l,x.l))+a[i])return false;
			if(x.l!=x.r)STK[++top]=(Node){x.u,x.l+1,x.r,Substr(x.u,x.l+1,x.r)};
		}
	return top==0;
}
signed main(){
	n=read();read();t=(n-1)/T+1;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=Base[0]=1;i<=n;i++)Base[i]=Base[i-1]*base%mod;
	for(int i=1;i<=t;i++)L[i]=R[i-1]+1,R[i]=L[i]+T-1;
	if(R[t]>n)R[t]=n;if(R[t]<n)R[++t]=n,L[t]=R[t-1]+1;
	for(int i=1;i<=t;i++){
		for(int j=L[i];j<=R[i];j++)bel[j]=i;
		Rebuild(i);
	}
	q=read();
	while(q--){
		int opt=read(),l=read(),r=read();
		if(opt==1)Modify(l,r);
		if(opt==2)puts(Query(l,r)?"Yes":"No");
	}
	return 0;
}