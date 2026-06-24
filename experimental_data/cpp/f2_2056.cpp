#include <bits/stdc++.h>
#define int ll
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define rng(i,c,n) for(int i=c;i<n;i++)
#define fi first
#define se second
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define vec(...) vector<__VA_ARGS__>
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
void print(){cout<<'\n';}
template<class h,class...t>
void print(const h&v,const t&...u){cout<<v<<' ',print(u...);}

int cnk_lucas(int a,int b){
	return (a&b)==a;
}

int stirling2(int k,int n){
	if(n==k) return 1;
	if(n==0 or k==0) return 0;
	if(k>n) return 0;
	int a=n-k,b=(k-1)/2;
	return (a&b)==0;
}

int f(int k,int n){
	int wys=0;
	rep(y,k+1){
		wys+=cnk_lucas(y,k)*stirling2(y,n);
	}
	return wys%2;
}

void slv(){
	int n,m;
	cin>>n>>m;
	m-=1;

	string s;
	cin>>s;

	int c=0;
	rep(i,n){
		c+=(s[i]=='1');
	}

	auto get=[&](int x){
		// count number of y's such that:
		//  * y & x == y
		//  * y <= m - 1
		int res=0,ho=0;
		per(j,30){
			if(x>>j&1){
				if(!(m>>j&1)){
					ho=1;
					break;
				}else{
					x^=(1<<j);
				}
			}else{
				if(m>>j&1){
					res+=(j==__builtin_popcountll(x));
				}
			}
		}
		res+=!ho;
		return res%2;
	};

	// print("wtf",get(get,7,4),f(8,4));
	int ans=0;
	rep(i,c+1){
		if(!stirling2(i+1,c)) continue;
		rep(j,30){
			int x=(1<<j)|i;
			int wys=get(x);
			wys%=2;
			ans^=wys*(1<<j);
		}
	}
	print(ans);
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	rep(cs,t){
		slv();
	}
}