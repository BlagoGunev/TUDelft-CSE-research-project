#include<bits/stdc++.h>
using namespace std;
#define int long long




long long mod=1e18+10;
struct Info
{
    int L,R;
    long long sum;
    void init(int l,int r,long long v){//build 内初始化
        L=l;
        R=r;
        sum=v;
    }
    friend Info operator+(const Info &l,const Info &r){
        Info res;
        res.L=min(l.L,r.L);
        res.R=max(l.R,r.R);
        res.sum=(l.sum + r.sum) % mod;
        return res;
    }
};

struct Lazy//懒标记
{
    long long add,prod;//加  乘
    long long modify;bool flag;//修改
    Lazy(){//懒标记归零
        add=0;
        prod=1;
        modify=0;
        flag=false;
    }
    void work(Info &info,Lazy &lazy){
        if(flag){
            info.sum=modify*(info.R-info.L+1)%mod;
            lazy.modify=modify;
            lazy.flag=flag;
            return;// ???
        }
        if(prod!=1){
            lazy.prod=lazy.prod * prod % mod;
            lazy.add=lazy.add * prod % mod;
            info.sum=info.sum * prod % mod;
        }
        if(add!=0){
            lazy.add=(lazy.add + add) % mod;
            info.sum=(info.sum + (info.R - info.L + 1) * add % mod) % mod;
        }
    }
};

const int N=1e5+10;
long long a[N];
struct Segment_Tree
{
    int n=0;
    vector<Info>tr;
    vector<Lazy>lazy;
    Segment_Tree (int n_){
        init(n_);
    }
    void init(int n_){
        n=n_;
        n_ <<=2;
        tr.resize(n_);
        lazy.resize(n_);
    }
    void clear(){
        n=0;
        tr.resize(0);
        lazy.resize(0);
    }
    void build(){
        build(1,n);
    }
    void build(int l,int r,int p=1){
        if(l==r){
            tr[p].init(l,r,a[l]);
            return;
        }
        int mid=(l+r)>>1;
        build(l,mid,p<<1);
        build(mid+1,r,p<<1|1);
        tr[p]=tr[p<<1]+tr[p<<1|1];
    }
    void pushdown(int p){//将当前节点的懒标记向下传递给其子节点，并更新子节点的信息
        lazy[p].work(tr[p<<1],lazy[p<<1]);
        lazy[p].work(tr[p<<1|1],lazy[p<<1|1]);
        lazy[p]=Lazy();
    }
    void modify(int l,int r,Lazy la,int p=1){//区间修改，并更新懒标记
        if(l<=tr[p].L&&r>=tr[p].R){
            la.work(tr[p],lazy[p]);
            return;
        }
        int mid=(tr[p].L+tr[p].R)>>1;
        pushdown(p);
        if(l<=mid)modify(l,r,la,p<<1);
        if(r>=mid+1)modify(l,r,la,p<<1|1);
        tr[p]=tr[p<<1]+tr[p<<1|1];
    }
    Info query(int l,int r,int p=1){//区间查询
        if(l<=tr[p].L&&r>=tr[p].R){
            return tr[p];
        }
        int mid=(tr[p].L+tr[p].R)>>1;
        pushdown(p);
        if(r<=mid)return query(l,r,p<<1);
        else if(l>=mid+1)return query(l,r,p<<1|1);
        return query(l,r,p<<1)+query(l,r,p<<1|1);
    }
};

Segment_Tree t(100005);
void solve()
{
	set<int>s;
	int n,q;
	cin>>n>>q;
	s.clear();
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)s.insert(i);
	}	
	//cout<<0<<endl;
	t.init(n);
	t.build();
	while(q--){
		int op;
		cin>>op;
		if(op==1){
			int x;
			cin>>x;
			int l=1,r=n;
			int mid;
			Info aa;
			while(l<r){
				mid=(l+r+1)>>1;
				aa=t.query(1,mid);
				if(aa.sum>x){
					r=mid-1;
				}
				else l=mid;
			}

			Info ans=t.query(1,r);//sum>=x
			if(ans.sum==x){
				puts("YES");
				continue;
			}
			else if(r==n&&ans.sum<x-1){
				puts("NO");
				continue;
			}
			else if(s.empty()||*s.begin()>n-r&&*s.rbegin()<=r){
				puts("NO");
				continue;
			}
			puts("YES");
		}
		else{
			int x,k;
			cin>>x>>k;
		 	if(a[x]==k)continue;
		 	a[x]=k;
			//if(a[x]!=k){
			if(k==2)s.erase(x);
			else s.insert(x);
			Lazy la;
            la.modify=k;
            la.flag=1;
			t.modify(x,x,la);
		}
	}
	t.clear();
}

signed main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)
    {
    	solve();	
    }
	return 0;
}