//```
#define YF ios_base::sync_with_stdio(0);cout.setf(ios::fixed);
#define YUSUF cout.precision(0);cout.tie(0);cin.tie(0);
#include <bits/stdc++.h>
using namespace std;
string ab=" abcdefghijklmnopqrstuvwxyz";
#define revers(a) reverse(a.begin(),a.end())
#define sortt(a) sort(a.begin(),a.end())
#define DO2 itn v=1,int tl=1,int tr=n
#define all(a) a.begin(),a.end()
#define DO1 v+v+1,(tl+tr)/2+1,tr
#define DO v+v,tl,(tl+tr)/2
#define ll long long
#define pb push_back
#define S second
#define F first
#define itn int
void MAX(ll &x,ll y){x=max(x,y);}
void MIN(ll &x,ll y){x=min(x,y);}
const int mod = 998244353 + 7 ;
const ll  INF = 1e18      + 7 ;
const int inf = 1e9       + 7 ;
const int N   = 1e6       + 7 ;
int used[N];
vector <int> g[N];
ll n;
void YF_MAIN(){
	cin>>n;
	set <int> st;
	vector <map<int,int>>mp(100);
	int aa[100];
	itn a[100][100];
	for(int i=1;i<=n;i++){
		cin>>aa[i];
		for(int j=1;j<=aa[i];j++){
			cin>>a[i][j];
			st.insert(a[i][j]);
			mp[i][a[i][j]]++;
		}
	}
	ll ans=0;
	for(auto xx : st){
		ll now=0;
		set <int> stt;
		for(int i=1;i<=n;i++){
			if(mp[i][xx]==0){
				for(int j=1;j<=aa[i];j++){
					stt.insert(a[i][j]);
				}
			}
		}
		MAX(ans,stt.size());
	}
	cout<<ans;
}
int main(){
	YF YUSUF
	#ifdef YF_CHECK
	cout<<"\nYF_ANSWER: \n \n";
	#endif
	int YF_TECT=1;
	cin>>YF_TECT;
	YF_TECT--;
	YF_MAIN();
while(YF_TECT--){
	cout<<"\n";
	YF_MAIN();
}
}
//```