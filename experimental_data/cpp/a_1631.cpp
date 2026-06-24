#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nln "\n"
#define vln vector<long long>
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define yes cout<<"YES"<<nln; return;
#define no cout<<"NO"<<nln; return;
#define pb push_back
#define ppb pop_back
#define mo map<ll,ll>
#define vlp vector<pair<ll,ll>> 
#define vs vector<string>
#define fr(x) for( ll i = 0 ; i < x ; ++i)



void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif
	}
int alp[26];
	void disp(){fr(26)cout<<char(i+'a')<<" : "<<alp[i]<<nln;}
	bool sortbyfir(const pair<int,int> &a,const pair<int,int> &b){return (a.first < b.first);}
	int palind(string s){string t=s;reverse(all(t));for (int i = 0; i < s.size(); ++i){if(t[i]!=s[i]) return -1;}return 1;}
	void sub_min(ll &a,ll &b){ll c= min(a,b);b=b-c;a=c-a;}
	ll apowerb(int a,int b){if(b==0) return 1; if(b&1){return a*apowerb(a,b/2)*apowerb(a,b/2);}else return apowerb(a,b/2)*apowerb(a,b/2);}


	void find(vln &v1,vln &v2, ll n){
	// sort(all(v1));
	// sort(all(v2));
	// for(auto x:v1)cout<<x<<" ";cout<<nln;
	// for(auto x:v2)cout<<x<<" ";cout<<nln;
		ll max1=0;
		fr(n)if(v1[i] > v1[max1]) max1 =i; 
		ll max2=0;
		fr(n)if(v2[i] > v2[max2]) max2 =i;
		if(max1 == max2 ){ cout<<v1[max1]*v2[max2]; return;}
		ll multi,m1,m2;
		// cout<<v1[max1]<<" "<<v2[max2]<<nln;
		if(v1[max1] >= v2[max2]){
			fr(n){
					if(v1[i]<v2[i]){
						v2[i]=v1[i];
					}
				}
				ll max3 =0;
			fr(n){if(v2[i] > max3)max3=v2[i];}
			cout<<max3*v1[max1];
			return;
		}
		if(v1[max1] <= v2[max2]){
			fr(n){
					if(v2[i]<v1[i]){
						v1[i]=v2[i];
					}
				}
				ll max3 =0;
			fr(n){if(v1[i] > max3)max3=v1[i];}
			cout<<max3*v2[max2];
			return;
		}



	}

int main(){
init_code();
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	ll i,n;
	cin>>n;i=n;
	vln v1,v2;
	while(n--){
	ll e;
	cin>>e;
	v1.push_back(e);
	}
	n=i;
	while(n--){
	ll e;
	cin>>e;
	v2.push_back(e);
	}
	find(v1,v2,i);
	cout<<nln;
	}
	return 0;
}