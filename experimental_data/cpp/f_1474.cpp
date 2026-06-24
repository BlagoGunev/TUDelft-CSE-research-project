#include <bits/stdc++.h>

using namespace std;

#define int long long



const int mod=998244353;

struct mint{

	int a;

	mint()=default;

	mint(int x):a((x%mod+mod)%mod){}

	mint operator+(const mint &x)const{return this->a+x.a;}

	mint operator-(const mint &x)const{return this->a-x.a;}

	mint operator*(const mint &x)const{return this->a*x.a;}

	mint &operator+=(const mint x){*this=*this+x; return *this;}

	mint &operator-=(const mint x){*this=*this-x; return *this;}

	mint &operator*=(const mint x){*this=*this*x; return *this;}

	mint operator-()const{return (this->a?mod-this->a:0);}

	mint power(int y)const{

		mint x=*this;

		mint res=1;

		while(y){

			if(y&1) res*=x;

			x*=x;

			y>>=1;

		}

		return res;

	}

	mint inv()const{return power(mod-2);} //mod must be prime

	mint operator/(const mint &x)const{return *this*x.inv();}

	mint &operator/=(const mint &x){*this=*this/x; return *this;}

	bool operator==(mint x)const{return (this->a==x.a);}

	bool operator!=(mint x)const{return (this->a!=x.a);}

	bool operator<(mint x)const{return (this->a<x.a);}

	bool operator>(mint x)const{return (this->a>x.a);}

};

mint operator*(int &x,mint &y){return y*x;}

istream&operator>>(istream&stream,mint&y){int x;stream>>x;y=x;return stream;}

ostream&operator<<(ostream&stream,mint y){return stream<<y.a;}

vector<mint>fact(1,1),invf(1,1);

mint ncr(int n,int k){

	if(n<0||k<0||n<k) return 0;

	int x=(int)(fact.size());

	while(x<=n){

		mint f=fact[x-1]*x;

		fact.push_back(f);

		invf.push_back(f.inv());

		x++;

	}

	return fact[n]*invf[k]*invf[n-k];

}



#ifndef ONLINE_JUDGE

#include "debug.h"

#else

#define deb(...) 4

#endif



struct mat{

    int n;

    vector < vector < mint > > a;

    mat(int N) {

        n = N;

        a.resize(N, vector < mint >(N, 0));

    }

};

mat mult(mat a, mat b) {

    int n = a.n;

    mat c(n);

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            for (int k = 0; k < n; k++) {

                c.a[i][k] = c.a[i][k] + a.a[i][j] * b.a[j][k];

            }

        }

    }

    return c;

}

mat pw(mat a, int n) {

    if (n == 0) {

        int nn = a.n;

        mat c(nn);

        for (int i = 0; i < nn; i++) {

            c.a[i][i] = 1;

        }

        return c;

    }

    if (n & 1) {

        return mult(a, pw(a, n - 1));

    }

    mat res = pw(a, n / 2);

    return mult(res, res);

}

mat fi(int i,vector<pair<int,int>>vv,int n){

	vector<int>eq;

	int z=0;

	int o=0;

	for(auto p:vv){

		int l=min(p.first,p.second);

		int r=max(p.first,p.second);

		if(i-1>=l&&i-1<=r&&p.first<=p.second){

			eq.push_back(0);

			z++;

		}

		if(i>=l&&i<=r){

			eq.push_back(1);

			o++;

		}

		if(i-1>=l&&i-1<=r&&p.first>p.second){

			eq.push_back(0);

			z++;

		}

	}

	assert(max(z,o)<=n);

	int idx=0;

	int m=eq.size();

	vector<int>wh(m);

	for(int i=0;i<m;i++){

		if(!eq[i]){

			wh[i]=idx++;

		}

	}

	int id=0;

	mat M(n);

	for(int i=0;i<m;i++){

		if(!eq[i]) continue;

		for(int j=0;j<i;j++){

			if(!eq[j]) M.a[id][wh[j]]=1;

		}

		id++;

	}

	return M;

}

vector<mint> upd(int n,mat M,int P,vector<mint>cur){

	vector<mint>res(n);

	M=pw(M,P);

	for(int i=0;i<n;i++){

		for(int j=0;j<n;j++){

			res[i]+=M.a[i][j]*cur[j];

		}

	}

	return res;

}

mint calc(vector<int>v){

	vector<int>f;

	int n=v.size();

	vector<pair<int,int>>vv;

	for(int i=1;i<n;i++){

		if(i==1){

			vv.push_back({v[i-1],v[i]});

		}

		else{

			if(v[i-1]>v[i]){

				vv.push_back({v[i-1]-1,v[i]});

			}

			else{

				vv.push_back({v[i-1]+1,v[i]});

			}

		}

	}

	set<int>s;

	for(auto p:vv){

		s.insert(p.first-1);

		s.insert(p.first-2);

		s.insert(p.first);

		s.insert(p.second);

		s.insert(p.second+1);

		s.insert(p.second+2);

	}

	int m=vv.size();

	int l=v[0];

	int r=v.back();

	vector<mint>res(m);

	int idx=0;

	for(auto p:vv){

		int a=min(p.first,p.second);

		int b=max(p.first,p.second);

		if(a<=l&&l<=b) res[idx++]=1;

	}

	int cur=l+1;

	while(cur<=r){

		res=upd(m,fi(cur,vv,m),1,res);

		cur++;

		if(cur>r) break;

		if(s.find(cur)!=s.end()){

			continue;

		}

		res=upd(m,fi(cur,vv,m),1,res);

		cur++;

		if(cur>r) break;

		auto it=s.lower_bound(cur);

		res=upd(m,fi(cur,vv,m),*it-cur+1,res);

		cur=*it+1;

	}

	mint ans=0;

	for(auto x:res) ans+=x;

	return ans;

}

signed main()

{

	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);



	int n,x;

	cin>>n>>x;

	vector<int>a(n);

	for(int i=0;i<n;i++) cin>>a[i];

	for(int i=0;i<n;i++){

		if(a[i]>0){

			for(int j=i+1;j<n;j++){

				if(a[j]<0) break;

				a[i]+=a[j];

				a[j]=0;

			}

		}

		else if(a[i]<0){

			for(int j=i+1;j<n;j++){

				if(a[j]>0) break;

				a[i]+=a[j];

				a[j]=0;

			}

		}

	}

	vector<int>cu={x};

	for(auto y:a){

		if(!y) continue;

		x+=y;

		cu.push_back(x);

	}

	int ans1=0;

	n=cu.size();

	for(int i=0;i<n;i++){

		for(int j=i+1;j<n;j++){

			ans1=max(ans1,max(0LL,cu[j]-cu[i])+1);

		}

	}

	set<pair<int,int>>s;

	for(int i=0;i<n;i++){

		for(int j=i+1;j<n;j++){

			if(cu[j]-cu[i]+1==ans1){

				s.insert({cu[i],cu[j]});

			}

		}

	}

	mint ans2=0;

	if(ans1<=1){

		ans1=1;

		for(auto x:a) ans2+=abs(x);

		ans2+=1;

	}

	else{

		for(auto p:s){

			int i=0;

			int j=n-1;

			while(cu[i]!=p.first) i++;

			while(cu[j]!=p.second) j--;

			vector<int>f;

			for(int k=i;k<=j;k++) f.push_back(cu[k]);

			ans2+=calc(f);

		}

	}

	cout<<ans1<<' '<<ans2<<'\n';

	return 0;

}