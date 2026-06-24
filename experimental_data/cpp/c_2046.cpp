#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define fi first
#define se second
#define mkp make_pair
const int N=400024,M=6000024,RR=1000000001;
int t,n,idx1,idx2,A1,A2;
int rt1,rt2;
struct node{
	int ge,ls,rs;
}tre1[M],tre2[M];
struct point{
	int x,y;
}a[N];
bool cmpp(point x,point y){
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
inline int insert1(int cur,int L,int R,int pl){
	if(cur==0){
		idx1++;
		cur=idx1;
		tre1[idx1].ls=0;
		tre1[idx1].rs=0;
		tre1[idx1].ge=0;
	}
	if(L==R){
		tre1[cur].ge++;
		return cur;
	}
	int mid=(L+R)>>1;
	if(pl<=mid){
		tre1[cur].ls=insert1(tre1[cur].ls,L,mid,pl);
	}
	else{
		tre1[cur].rs=insert1(tre1[cur].rs,mid+1,R,pl);
	}
	tre1[cur].ge++;
	return cur;
}
inline int insert2(int cur,int L,int R,int pl){
	if(cur==0){
		idx2++;
		tre2[idx2].ls=0;
		tre2[idx2].rs=0;
		tre2[idx2].ge=0;
		cur=idx2;
	}
	if(L==R){
		tre2[cur].ge++;
		return cur;
	}
	int mid=(L+R)>>1;
	if(pl<=mid){
		tre2[cur].ls=insert2(tre2[cur].ls,L,mid,pl);
	}
	else{
		tre2[cur].rs=insert2(tre2[cur].rs,mid+1,R,pl);
	}
	tre2[cur].ge++;
	return cur;
}
inline int del2(int cur,int L,int R,int pl){
	if(L==R){
		tre2[cur].ge--;
		return cur;
	}
	int mid=(L+R)>>1;
	if(pl<=mid){
		tre2[cur].ls=del2(tre2[cur].ls,L,mid,pl);
	}
	else{
		tre2[cur].rs=del2(tre2[cur].rs,mid+1,R,pl);
	}
	tre2[cur].ge--;
	return cur;
}
inline int query1(int cur,int L,int R,int sum){
	if(L==R){
		return L;
	}
	int mid=(L+R)>>1;
	if(tre1[tre1[cur].ls].ge>=sum){
		return query1(tre1[cur].ls,L,mid,sum);
	}
	else{
		return query1(tre1[cur].rs,mid+1,R,sum-tre1[tre1[cur].ls].ge);
	}
}
inline int query2(int cur,int L,int R,int sum){
	if(L==R){
		return L;
	}
	int mid=(L+R)>>1;
	if(tre2[tre2[cur].ls].ge>=sum){
		return query2(tre2[cur].ls,L,mid,sum);
	}
	else{
		return query2(tre2[cur].rs,mid+1,R,sum-tre2[tre2[cur].ls].ge);
	}
}
inline bool check(int cur){
	idx1=0;
	idx2=0;
	rt1=0;
	rt2=0;
	for(int i=1;i<=n;i++){
		rt2=insert2(rt2,-RR,RR,a[i].y);
	}
	for(int i=1,j=1;i<=n;i++){
		j=i;
		while(j<=n&&a[j].x==a[i].x){
			rt1=insert1(rt1,-RR,RR,a[j].y);
			rt2=del2(rt2,-RR,RR,a[j].y);
			j++;
		}
		i=j-1;
		if(tre1[rt1].ge>=2*cur&&tre2[rt2].ge>=2*cur){
			int L1=query1(rt1,-RR,RR,cur);
			int R1=query1(rt1,-RR,RR,tre1[rt1].ge-cur+1);
			int L2=query2(rt2,-RR,RR,cur);
			int R2=query2(rt2,-RR,RR,tre2[rt2].ge-cur+1);
			R1=min(R1,R2);
			L1=max(L1,L2);
			if(L1<R1){
				A1=a[i].x;
				A2=L1;
				return 1;
			}
		}
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y;
		}
		sort(a+1,a+1+n,cmpp);
		int L=1,R=n/4,mid,ans=0;
		while(L<=R){
			mid=(L+R)>>1;
			if(check(mid)){
				ans=mid;
				L=mid+1;
			}
			else{
				R=mid-1;
			}
		}
		cout<<ans<<"\n";
		cout<<A1+1<<" "<<A2+1<<"\n";
	}
	return 0;
}