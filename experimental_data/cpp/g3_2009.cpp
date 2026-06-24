#include<bits/stdc++.h>
using namespace std;
struct query { long long t,l,r,he,p; };
const int MAXN=2e5+5;
vector<query> vq[MAXN];
int A[MAXN],cnt[MAXN*2],cntt[MAXN*2],B[MAXN],L[MAXN],R[MAXN],mx=0;
long long ans[MAXN];
struct fenwicktree
{
	long long fen[MAXN][2];
	void update(int a,int n,long long val) { for(int i=a;i<=n;i+=i&-i) fen[i][0]+=val,fen[i][1]+=val*(a-1); }
	long long get(int a) { long long ans=0;for(int i=a;i;i-=i&-i) ans+=fen[i][0]*a-fen[i][1];return ans; }
	void rupd(int l,int r,int n,long long val) { update(l,n,val);update(r+1,n,-val); }
	long long rget(int l,int r) { return get(r)-get(l-1); }
};
fenwicktree fa,fb;
void insnum(int a) { cntt[++cnt[a]]++,mx=max(mx,cnt[a]); }
void ersnum(int a) { cntt[cnt[a]--]--,mx-=(!cntt[mx]); }
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    	int n,k,q;
    	cin>>n>>k>>q;
    	for(int i=1;i<=n;i++)
    	{
    		cin>>A[i];
    		A[i]+=n-i;
    		insnum(A[i]);
    		if(i>k) ersnum(A[i-k]);
    		if(i>=k) B[i-k+1]=k-mx;
		}
		for(int i=n-k+1;i<=n;i++) ersnum(A[i]);
		stack<int> st;
		n-=k-1;
		for(int i=1;i<=n;i++)
		{
			while(!st.empty()&&B[st.top()]>B[i]) st.pop();
			if(st.empty()) L[i]=1;
			else L[i]=st.top()+1;
			st.push(i);
		}
		while(!st.empty()) st.pop();
		for(int i=n;i;i--)
		{
			while(!st.empty()&&B[st.top()]>=B[i]) st.pop();
			if(st.empty()) R[i]=n;
			else R[i]=st.top()-1;
			st.push(i);
		}
		for(int i=1;i<=n;i++) vq[L[i]].push_back({1,i,R[i],B[i],0}),vq[i+1].push_back({1,i,R[i],-B[i],0});
		for(int i=1;i<=q;i++)
		{
			int l,r;
			cin>>l>>r;
			r-=k-1,ans[i]=0,vq[l-1].push_back({2,l,r,-1,i}),vq[r].push_back({2,l,r,1,i});
		}
		for(int i=1;i<=n+1;i++)
		{
			for(auto v:vq[i]) if(v.t==1) fa.rupd(v.l,v.r,n,v.he*(n-i+1)),fb.rupd(v.l,v.r,n,v.he);
			else ans[v.p]+=(fa.rget(v.l,v.r)-fb.rget(v.l,v.r)*(n-i))*v.he;
			vq[i].clear();
		}
		for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
		for(int i=1;i<=n;i++) fa.fen[i][0]=fa.fen[i][1]=fb.fen[i][0]=fb.fen[i][1]=0;
	}
}