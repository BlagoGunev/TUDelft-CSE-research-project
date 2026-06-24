#include<bits/stdc++.h>

#define int long long

#define mod 1000000007l

#define nl cout<<"\n";

#define pb push_back

#define all(a) a.begin(),a.end()

#define vi vector<int>

#define vpi vector<pair<int,int>>

#define vvi vector<vector<int>>

#define mii map<int,int>

#define S second

#define F first

#define f(i,a,n) for(int i=a;i<n;i++)

#define fi(i,n,a) for(int i=n-1;i>=a;i--)

#define arrayinput int n;cin>>n;vector<int> a(n);for(int i=0;i<n;i++)cin>>a[i];

#define tcsolve(tcs) while(tcs--) solve();

#define aout(f)	f==1 ? cout<<"YES\n" : cout<<"NO\n";

 

using namespace std;

template<class T,class S> void print(map<T,S> mp) {for(auto it:mp) cout<<it.first<<" "<<it.second<<"\n";}

template<class T,class S> void print(map<T,vector<S>> mp) {for(auto it:mp){ cout<<it.first<<"\n";	 int l=it.second.size();for(int i=0;i<l;i++) cout<<it.second[i]<<" ";nl;}}

template<class T> void print(vector<vector<T>> &v) {int n=v.size(); for(int i=0;i<n;i++){ cout<<"key : "<<i+1<<"\n";cout<<"val : ";for(auto y:v[i]){ cout<<y<<" ";}cout<<"\n\n";}}

template <class T> void print(const T & c)	 {cout<<c<<"\n";}

template <class T,class K>  void print(const T & c,const K & d)	{cout<<c<<" "<<d<<"\n";}

template <class T,class A,class N>  void print(const T & c,const A & d,const N & e)	{cout<<c<<" "<<d<<" "<<e<<"\n";}

template <class T> void print(vector<T> & v){int l=v.size();for(int i=0;i<l;i++) cout<<v[i]<<" ";nl;}

template <class T,class S> void print(vector<pair<T,S>> & v){int l=v.size();for(int i=0;i<l;i++) cout<<v[i].first<<" "<<v[i].second<<"\n";}

 

int a[200050ll]={0};

int tree[800050ll]={0};

void build(int n,int tl,int tr){

	if(tl==tr){

		tree[n]=a[tl];

		return;

	}

	int tm=(tl+tr)/2;

	build(2*n,tl,tm);

	build(2*n+1,tm+1,tr);

	tree[n]=max(tree[2*n],tree[2*n+1]);

}

int mxn(int n,int tl,int tr,int l,int r){

	if(l<=tl && tr<=r){

		return tree[n];

	}

	if(tr<l || r<tl)	return -1;

	

	int tm=(tr+tl)/2;

	int x=mxn(2*n,tl,tm,l,min(tm,r));

	int y=mxn(2*n+1,tm+1,tr,max(tm,l),r);

	return max(x,y);

}

 

void solve()

{

	int n;cin>>n;

	int b[n+1];

	f(i,1,n+1){

		cin>>b[i];

	}

	map<int,vi> mp;

	int f=0;

	f(i,1,n+1){

		cin>>a[i];

		if(a[i]>b[i])	f=1;

		if(a[i]!=b[i])

			mp[a[i]].pb(i);

	}

	int m;cin>>m;

	vi c(m+1);

	f(i,1,m+1){

		cin>>c[i];

	}

	if(f){

		print("NO");return;

	}

	build(1,1,n);

	mii vp;

	for(auto x : mp){

		vp[x.F]++;

		int l=x.S.size();

		f(i,0,l-1){

			int l=x.S[i];

			int r=x.S[i+1];

			int mx=mxn(1,1,n,l,r);

			if(mx>x.F){

				vp[x.F]++;

			}

		}

	}

	f(i,1,m+1){

		vp[c[i]]--;

	}

	for(auto x:vp){

		if(x.S>0){

			print("NO");return;

		}

	}

	print("YES");

	

	fill(tree,tree+4*n,0);

	fill(a,a+n,0);

}

 

signed main()

{

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	

	int tcs=1;

		cin>>tcs;

	tcsolve(tcs);

}