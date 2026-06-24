#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
template<class T> bool chmax(T &a, T b){if (a < b){a = b;return true;} else return false;}
template<class T> bool chmin(T &a, T b){if (a > b){a = b;return true;} else return false;}

void solve(){
	ll N;
	int K,Q;
	cin>>N>>K>>Q;
	vector<ll>A(K+1),B(K+1);
	for(int i=0;i<K;i++)cin>>A[i+1];
	for(int i=0;i<K;i++)cin>>B[i+1];
	vector<pair<ll,int>>vp;
	for(int q=0;q<Q;q++){
		ll d;
		cin>>d;
		vp.push_back(make_pair(d,q));
	}
	sort(rall(vp));
	ll sum=0;
	vector<ll>ans(Q);
	for(int i=0;i<K;i++){
		while(vp.size()&&vp.back().first<=A[i+1]){
			auto[d,q]=vp.back();
			ans[q]=sum+((d-A[i])*(B[i+1]-B[i]))/(A[i+1]-A[i]);
			vp.pop_back();
		}
		sum=B[i+1];
	}
	for(int i=0;i<Q;i++)cout<<ans[i]<<" ";
	cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
}