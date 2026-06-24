#include<bits/stdc++.h>
using namespace std;
long long a[200000],c[200000],inf=1000000000000000000LL;
map<long long,long long>mp,mp2;
void ins(long long x){
	mp2[mp[x]]--;
	mp[x]++;
	mp2[mp[x]]++;
}
void ers(long long x){
	mp2[mp[x]]--;
	mp[x]--;
	mp2[mp[x]]++;
}
long long getmx(){
	map<long long,long long>::iterator it;
	while(1)
	{
		it=mp2.end();
		it--;
		if((*it).second==0)
		{
			mp2.erase(it);
			continue;
		}
		return (*it).first;
	}
	return -1;
}
long long svl[1<<19],lazy[1<<19];
void gen(int t,int dep){
	svl[t]=0;
	lazy[t]=0;
	if(dep==0)return;
	gen(t*2+1,dep-1);
	gen(t*2+2,dep-1);
}
struct qry{
	int r;
	int id;
};
vector<qry>vq[200000];
void pushdown(int t,int dep){
	int lt=t*2+1,rt=t*2+2;
	svl[lt]+=lazy[t]*(1LL<<(dep-1));
	svl[rt]+=lazy[t]*(1LL<<(dep-1));
	lazy[lt]+=lazy[t];
	lazy[rt]+=lazy[t];
	lazy[t]=0;
}
void add(int t,int dep,int l,int r,long long vl){
	if(l==0&&r==(1<<dep))
	{
		svl[t]+=vl*(1LL<<dep);
		lazy[t]+=vl;
		return;
	}
	pushdown(t,dep);
	int x=(1<<(dep-1));
	if(l<x)
	{
		if(r<=x)add(t*2+1,dep-1,l,r,vl);
		else
		{
			add(t*2+1,dep-1,l,x,vl);
			add(t*2+2,dep-1,0,r-x,vl);
		}
	}
	else add(t*2+2,dep-1,l-x,r-x,vl);
	svl[t]=svl[t*2+1]+svl[t*2+2];
}
long long qsum(int t,int dep,int l,int r){
	if(l==0&&r==(1<<dep))return svl[t];
	pushdown(t,dep);
	int x=(1<<(dep-1));
	if(l<x)
	{
		if(r<=x)return qsum(t*2+1,dep-1,l,r);
		return qsum(t*2+1,dep-1,l,x)+qsum(t*2+2,dep-1,0,r-x);
	}
	return qsum(t*2+2,dep-1,l-x,r-x);
}
long long ans[200000];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,tdep;
	long long n,k,q,i,l,cpos;
	map<long long,long long>::iterator it;
	vector<qry>::iterator itq;
	qry qx;
	for(cin>>T;T>0;T--)
	{
		cin>>n>>k>>q;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			a[i]-=i;
		}
		mp2[0]=inf;
		for(i=0;i<k;i++)ins(a[i]);
		c[0]=k-getmx();
		for(i=k;i<n;i++)
		{
			ins(a[i]);
			ers(a[i-k]);
			c[i-k+1]=k-getmx();
		}
		mp.clear();
		mp2.clear();
		n-=k-1;
		for(tdep=0;(1<<tdep)<n;tdep++);
		gen(0,tdep);
		mp[n]=-1;
		for(i=0;i<q;i++)
		{
			cin>>l>>qx.r;
			qx.r-=k-1;
			qx.id=i;
			vq[l-1].push_back(qx);
		}
		for(i=n-1;i>-1;i--)
		{
			add(0,tdep,i,i+1,c[i]);
			cpos=i;
			while(1)
			{
				it=mp.begin();
				if((*it).second<c[i])break;
				add(0,tdep,cpos+1,(*it).first+1,c[i]-(*it).second);
				cpos=(*it).first;
				mp.erase(it);
			}
			mp[cpos]=c[i];
			for(itq=vq[i].begin();itq!=vq[i].end();itq++)ans[(*itq).id]=qsum(0,tdep,i,(*itq).r);
		}
		for(i=0;i<n;i++)vq[i].clear();
		mp.clear();
		for(i=0;i<q;i++)cout<<ans[i]<<'\n';
	}
	return 0;
}