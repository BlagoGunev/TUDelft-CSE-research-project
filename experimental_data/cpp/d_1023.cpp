#include <iostream>
#include <cstdio>

#define Max 200005

using namespace std;

inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x=0;char ch=gc();bool positive=1;
	for(;!isdigit(ch);ch=gc())if(ch=='-')positive=0;
	for(;isdigit(ch);ch=gc())x=x*10+ch-'0';
	return positive?x:-x;
}

inline void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);putchar(x%10+'0');
}

inline void writeln(int x){
	write(x);puts("");
}

struct Tree{
	int l,r,minn;
}st[Max*4];

int n,q,now,l[Max],r[Max],a[Max];
bool vis[Max],use[Max];

inline void update(int node){
	st[node].minn=min(st[node<<1].minn,st[node<<1|1].minn);
}

inline void build(int node,int l,int r){
	st[node].l=l;st[node].r=r;
	if(l==r){
		st[node].minn=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(node<<1,l,mid);
	build(node<<1|1,mid+1,r);
	update(node);
}

inline int query(int node,int l,int r){
	if(st[node].l>r||st[node].r<l)return 1e9;
	if(st[node].l>=l&&st[node].r<=r)return st[node].minn;
	return min(query(node<<1,l,r),query(node<<1|1,l,r));
}

int main(){
	n=read();q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(!a[1]){
		a[1]=1;
		use[1]=true;
	}
	if(!a[n]){
		a[n]=1;
		use[n]=true;
	}
	for(int i=1;i<=n;i++){
		if(!a[i]){
			use[i]=true;
			a[i]=a[i-1];
		}
	}
	build(1,1,n);
	now=1e9;
	for(int i=1;i<=n;i++){
		if(vis[a[i]]){
			r[a[i]]=max(r[a[i]],i);
		}else{
			l[a[i]]=i;
			r[a[i]]=i;
			vis[a[i]]=true;
		}
	}
	for(int i=1;i<=q;i++){
		// cout<<l[i]<<" "<<r[i]<<endl;
		if(l[i]){
			if(query(1,l[i],r[i])<i){
				puts("NO");
				return 0;
			}
		}
	}
	if(!l[q]){
		int id=0,maxn=-1e9;
		for(int i=1;i<=n;i++){
			if(use[i]&&maxn<a[i]){
				maxn=a[i];
				id=i;
			}
		}
		if(id){
			a[id]=q;
			goto loop;
		}
		puts("NO");
		return 0;
	}
	loop:
	puts("YES");
	for(int i=1;i<=n;i++){
		write(a[i]);putchar(' ');
	}
	return 0;
}