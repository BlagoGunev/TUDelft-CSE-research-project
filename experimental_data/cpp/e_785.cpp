#include <iostream>
#include <cstdio>
#include <algorithm> 
#define ls x<<1
#define rs x<<1|1
using namespace std;

inline int _in(){
	char t = getchar(); int o = 0,f = 0;
	while(t<48 || t>57)f |= (t=='-'), t = getchar();
	while(t>47 && t<58)o = (o<<1)+(o<<3)+t-48, t = getchar();
	return f?-o:o; 
}

const int N = 200005, N1 = N * 4, N2 = N * 100;
int n,m,i,s,t,tot,lsto;
int A[N];
int Rt[N],L[N2],R[N2],_Rt[N2],V[N2];
long long o;

void _ins_in(int& x,int l,int r,int s,int d){
	if(!x) x=++tot;
	V[x]+=d;
	if(l == r) return; 
	int m = l+r>>1;
	if(s <= m) _ins_in(L[x],l,m,s,d);
	else _ins_in(R[x],m+1,r,s,d); 
}

int _qry_in(int x,int l,int r,int s,int t){
	if(V[x] == 0) return 0;
	if(s<=l&&r<=t) return V[x];
	int m = l+r>>1, ret = 0;
	if(s <= m)ret += _qry_in(L[x],l,m,s,t);
	if(t >  m)ret += _qry_in(R[x],m+1,r,s,t);
	return ret;
}

void _ins_out(int p,int s,int d){
	for(int i=p;i<=n;i+=(i&-i))
		_ins_in(Rt[i],1,n,s,d);
}

int _qry_out(int l,int r,int p){
	int o=0;
	for(int i=r;i;i-=(i&-i))o+=_qry_in(Rt[i],1,n,1,p);
	for(int i=l-1;i;i-=(i&-i))o-=_qry_in(Rt[i],1,n,1,p);
	return o;
}

int main(){
	n = _in(); m = _in();
	for(int i=1;i<=n;i++)A[i]=i,_ins_out(i,A[i],1);
	while(m--){
		int u=_in(),v=_in();
		if(u^v){
			if(u>v)swap(u,v);
			if(A[u]<A[v])o++;
			else o--;
			if(v-u>1){
				t=_qry_out(u+1,v-1,A[u]); 
				o-=t,o+=(v-u-1-t);
				t=_qry_out(u+1,v-1,A[v]);
				o+=t,o-=(v-u-1-t);
			}
			_ins_out(u,A[u],-1);
			_ins_out(u,A[v],1);
			_ins_out(v,A[v],-1);
			_ins_out(v,A[u],1); 
			swap(A[u],A[v]);
		}
		printf("%I64d\n",o);
	}
}