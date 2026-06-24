//Copyright(c)2018 Mstdream
#include<bits/stdc++.h>
using namespace std;

inline void splay(int &v){
	v=0;char c=0;int p=1;
	while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();}
	while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();}
	v*=p;
}
const int N=100010;
int is[N];
namespace tire{
	int rt[105];
	int t[N*14*20][2],tot,v[N*14*20];
	void add(int l,int r,int&now,int x){
		if(!now)now=++tot;v[now]++;
		if(l==r)return;
		int mid=l+r>>1;
		if(x<=mid)add(l,mid,t[now][0],x);
		else add(mid+1,r,t[now][1],x);
	}
	void add(int k,int x){
		add(0,131071,rt[k],x);
	}
	int sta[N],top,L[N],R[N];
	void get(int l,int r,int w,int x){
		if(!w)return;
		if(r<=x){
			sta[++top]=w;
			L[top]=l,R[top]=r;
			return;
		}
		int mid=l+r>>1;
		get(l,mid,t[w][0],x);
		if(mid+1<=x)get(mid+1,r,t[w][1],x);
	}
	int qur(int l,int r,int w,int x){
		if(l==r)return l^x;
		int mid=l+r>>1;
		if(!t[w][0])return qur(mid+1,r,t[w][1],x);
		else if(!t[w][1])return qur(l,mid,t[w][0],x);
		else{
			if((x^l)>(x^r))return qur(l,mid,t[w][0],x);
			else return qur(mid+1,r,t[w][1],x);
		}
	}
	int qur(int k,int x,int s){
		if(s-x<0)return -1;
		top=0;
		get(0,131071,rt[k],s-x);
		if(top==0)return -1;
		int ans=-1;
		for(int i=1;i<=top;i++){
			ans=max(ans,qur(L[i],R[i],sta[i],x));
		}
		return ans^x;
	}
}
int main(){
	int Q;splay(Q);
	while(Q--){
		int id;splay(id);
		if(id==1){
			int x;splay(x);
			if(is[x]==1)continue;
			is[x]=1;
			for(int i=1;i<=100;i++){
				if(x%i==0)tire::add(i,x);
			}
		}
		else{
			int x,k,s;
			splay(x),splay(k),splay(s);
			if(x%k!=0)puts("-1");
			else{
				if(k>100){
					int ans=-1;
					for(int i=k;i<=100000;i+=k){
						if(is[i]&&i<=s-x){
							ans=max(ans,x^i);
						}
					}
					if(ans==-1)printf("%d\n",ans);
					else printf("%d\n",ans^x);
				}
				else{
					printf("%d\n",tire::qur(k,x,s));	
				}
			}
		}
	}
}