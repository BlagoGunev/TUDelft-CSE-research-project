#include<bits/stdc++.h>//0xnnb
using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
const int N=400005;
int T,n,acnt[N],anum[N],nn,nums[N],pos[N],tot;
int num1[N],num2[N],s[N],s2[N],nxt[N][2],las[N][2];
int t[N*4];
char a[N],b[N];
bool vis[N];
vector<int>vec[N];
void build(int p,int l,int r){
	t[p]=-1e9;
	if(l==r){
		if(l==1)t[p]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
}
void down(int p){
	if(t[p]>-1e9){
		t[p*2]=max(t[p*2],t[p]);
		t[p*2+1]=max(t[p*2+1],t[p]);
		t[p]=-1e9;
	}
}
void upd1(int p,int l,int r,int xl,int xr,int val){
	if(xl<=l&&r<=xr){
		t[p]=max(t[p],val);
		return;
	}
	down(p);
	int mid=(l+r)>>1;
	if(xl<=mid)upd1(p*2,l,mid,xl,xr,val);
	if(xr>mid)upd1(p*2+1,mid+1,r,xl,xr,val);
}
void upd2(int p,int l,int r,int x){
	if(l==r){
		t[p]=-1e9;
		return;
	}
	down(p);
	int mid=(l+r)>>1;
	if(x<=mid)upd2(p*2,l,mid,x);
	else upd2(p*2+1,mid+1,r,x);
}
int ask(int p,int l,int r,int x){
	if(l==r)return l-t[p];
	down(p);
	int mid=(l+r)>>1;
	if(x<=mid)return ask(p*2,l,mid,x);
	else return ask(p*2+1,mid+1,r,x);
}
int solve2(){
	for(int i=0;i<=nn+1;i++){
		vec[i].clear();
		vis[i]=0;
	}
	tot=0;
	acnt[nn+1]=0;
	anum[nn+1]=anum[nn]^1;
	for(int i=1;i<=nn+1;i+=2){
		nums[++tot]=i;
		pos[i]=tot;
	}
	for(int i=2;i<=nn+1;i+=2){
		nums[++tot]=i;
		pos[i]=tot;
	}
	for(int i=1;i<=nn+1;i++){
		s[i]=s[i-1]+acnt[i];
		s2[i]=s2[max(i-2,0)]+acnt[i];
	}
	for(int i=1;i<=nn;i++){
		int l=s[i-1]+1,r=s[i];
		int pos=nxt[l][anum[i]^1];
		if(pos<=r)vis[i]=1;
	}
	for(int i=1;i<=nn;i++){
		if(vis[i])continue;
		int posl=s[i-1]+1;
		int xx=nxt[posl][anum[i]^1];
		int l=0,r=(nn-i)/2,anss=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(s2[i+mid*2]-s2[max(i-2,0)]+posl-1>=xx){
				r=mid-1;
			}
			else anss=mid,l=mid+1;
		}
		num1[i]=i+anss*2;
	}
	for(int i=2;i<=nn+1;i++){
		int posr=s[i];
		int xx=las[posr][anum[i]^1];
		int l=0,r=(i-1)/2,anss=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(posr-(s2[i]-s2[max(i-mid*2-2,0)])+1<=xx){
				r=mid-1;
			}
			else anss=mid,l=mid+1;
		}
		num2[i]=i-anss*2;
		vec[i-anss*2-1].push_back(i);
	} 
	build(1,1,nn+1);
	for(int i=1;i<=nn;i++){
		int tmp=vec[i].size();
		for(int j=0;j<tmp;j++){
			int x=vec[i][j];
			upd2(1,1,nn+1,pos[x]);
		}
		if(vis[i])continue;
		int now=ask(1,1,nn+1,pos[i]);
		int l=i+1,r=num1[i]+1;
		upd1(1,1,nn+1,pos[l],pos[r],pos[l]-now);
	}
	int ans=ask(1,1,nn+1,pos[nn+1]);
	return ans;
}
void solve(){
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	nn=1,acnt[1]=1,anum[1]=a[1]-'0';
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1])acnt[nn]++;
		else{
			acnt[++nn]=1;
			anum[nn]=a[i]-'0';
		}
	}
	nxt[n+1][0]=nxt[n+1][1]=n+1;
	for(int i=n;i>=1;i--){
		if(b[i]=='0')nxt[i][0]=i;
		else nxt[i][0]=nxt[i+1][0];
		if(b[i]=='1')nxt[i][1]=i;
		else nxt[i][1]=nxt[i+1][1];
	}
	las[0][0]=las[0][1]=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='0')las[i][0]=i;
		else las[i][0]=las[i-1][0];
		if(b[i]=='1')las[i][1]=i;
		else las[i][1]=las[i-1][1];
	}
	int ans=solve2();
	if(nn>=2){
		swap(acnt[1],acnt[2]);
		swap(anum[1],anum[2]);
		if(nn>=3){
			acnt[2]+=acnt[3];
			for(int i=3;i<nn;i++){
				acnt[i]=acnt[i+1];
				anum[i]=anum[i+1];
			}
			nn--;
		}
		ans=min(ans,solve2()+1);
	}
	if(ans>=1e9)ans=-1;
	printf("%d\n",ans);
}
void clear(){
	
}
int main(){
	T=read();
	while(T--){
		solve();
		clear();
	}
    return 0;
}