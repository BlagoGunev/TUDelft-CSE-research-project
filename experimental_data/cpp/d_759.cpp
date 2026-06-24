#include<bits/stdc++.h>
#define ALL(c) (c).begin(), (c).end()
using namespace std;
using ll = long long;
using ld = long double;

const int N = 5005;
const int mod = 1e9+7;

int d[N][N];

ll inv[N], f[N], fi[N];
void init(){
	inv[1] = 1;
	for(int i=2;i<N;++i) inv[i] = 1LL*(mod-mod/i)*inv[mod%i]%mod;
	f[0] = fi[0] = 1;
	for(int i=1;i<N;++i){
		f[i] = f[i-1]*i%mod;
		fi[i] = fi[i-1]*inv[i]%mod;
	}
}

int Cnk(int n, int k){
	if(n<k) return 0;
	return f[n]*fi[n-k]%mod*fi[k]%mod;
}

/*
set<string> q;

void go(string s){
	if(q.count(s)) return ;
	q.insert(s);
	for(int i=0;i<s.size();++i){
		string t1=s, t2=s;
		if(i){
			t1[i-1] = t1[i];
			go(t1);
		}
		if(i+1<s.size()){
			t2[i+1] = t2[i];
			go(t2);
		}
	}
}

set<string> y;
void gen(string &s, string t, int i){
	if(i==s.size()){
		if(t.size())y.insert(t);
		return ;
	}
	gen(s,t,i+1);
	if(t.size()==0 || t.back()!=s[i]) gen(s,t+s[i],i+1);
}*/

int main(){
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);//cout.precision(12);cout<<fixed;
	
	init();
	
	int n, m;
	string s;
	
	
	cin>>n>>s;
	n = s.size();
	
	/*go(s);
	
	cout<<q.size()<<endl;*/
	
	/*gen(s,"",0);
	
	int res = 0;
	for(string x : y){
		int k = x.size();
		res+=Cnk(n-1,k-1);
	}
	cout<<res<<endl;*/
	
	
	int sum = 0;
	
	for(int i=0;i<n;++i) d[1][i] = 1;
	
	ll ans = 0;
	for(int j=2;j<=n+1;++j){
		int sum = 0;
		vector<int> sp(26);
		for(int i=0;i<n;++i){
			sum-=sp[s[i]-'a'];
			if(sum<0) sum+=mod;
			d[j][i] = sum;
			sp[s[i]-'a'] = d[j-1][i];
			sum+=sp[s[i]-'a'];
			if(sum>=mod) sum-=mod;
		}
		ans+=1LL*sum*Cnk(n-1,j-2);
		ans%=mod;
	}
	
	
	cout<<ans<<endl;
	
	
	
	return 0;
}