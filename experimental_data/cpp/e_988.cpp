#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << "  - " << #x << ": " << x << endl;
#define debugs(x, y) cerr << "  - " << #x << ": " << x << "         " << #y << ": " << y << endl;
#define here() cerr << "here" << endl;
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define EPS 1e-7
#define INF 2000000000
const int MODN = 1e9 + 7;
#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
string s;
int n;
int solve(int w){
	int zs=0; bool c=false,se=false,t=false;
	for(int i=0;i<n;i++){
		if(s[i]=='0') zs++;
		if(s[i]=='2') t=true;
		if(s[i]=='5') c=true;
		if(s[i]=='7') se=true;
	}
	if(w==0){
		if(zs<2) return INF;
		int ret=0;
		string h=s;
		for(int i=n-1;i>=0;i--){
			if(h[i]=='0'){
				for(int j=i;j<n-1;j++){
					swap(h[j],h[j+1]);
					ret++;
				}
				break;
			}
		}
		for(int i=n-2;i>=0;i--){
			if(h[i]=='0'){
				for(int j=i;j<n-2;j++){
					swap(h[j],h[j+1]);
					ret++;
				}
				break;
			}
		}
		debugs(w,ret);
		return ret;
	}
	if(w==1){
		if(!t || !c) return INF;
		int ret=0;
		bool dc=false;
		string h=s;
		for(int i=n-1;i>=0;i--){
			if(h[i]=='5'){
				for(int j=i;j<n-1;j++){
					swap(h[j],h[j+1]);
					ret++;
				}
				break;
			}
		}
		for(int i=n-1;i>=0;i--){
			if(h[i]=='2'){
				for(int j=i;j<n-2;j++){
					swap(h[j],h[j+1]);
					ret++;
				}
				break;
			}
		}
		bool r=false;
		int k=0;
		for(int i=0;i<n-2;i++){
			if(h[i]!='0'){
				r=true;
				k=i;
				break;
			}
		}
		if(!r && n>2) return INF;
		ret+=k;	
		return ret;
	}
	if(w==2){
		if(zs==0 || !c) return INF;
		int ret=0;
		bool dc=false;
		string h=s;
		for(int i=n-1;i>=0;i--){
			if(h[i]=='0'){
				for(int j=i;j<n-1;j++){
					swap(h[j],h[j+1]);
					ret++;
				}
				break;
			}
		}

		for(int i=n-1;i>=0;i--){
			if(h[i]=='5'){
				for(int j=i;j<n-2;j++){
					swap(h[j],h[j+1]);
					ret++;
				}
				break;
			}
		}
		bool r=false;
		int k=0;
		for(int i=0;i<n-2;i++){
			if(h[i]!='0'){
				r=true;
				k=i;
				break;
			}
		}
		if(!r && n>2) return INF;
		ret+=k;
		return ret;
	}
	if(w==3){
		if(!se || !c) return INF;
		int ret=0;
		bool dc=false;
		string h=s;
		for(int i=n-1;i>=0;i--){
			if(h[i]=='5'){
				for(int j=i;j<n-1;j++){
					swap(h[j],h[j+1]);
					ret++;
				}
				break;
			}
		}
		for(int i=n-1;i>=0;i--){
			if(h[i]=='7'){
				for(int j=i;j<n-2;j++){
					swap(h[j],h[j+1]);
					ret++;
				}
				break;
			}
		}
		bool r=false;
		int k=0;
		for(int i=0;i<n-2;i++){
			if(h[i]!='0'){
				r=true;
				k=i;
				break;
			}
		}
		if(!r && n>2) return INF;
		ret+=k;
		return ret;
	}
}
int main(){
	cin>>s;
	n=s.length();
		if(s=="75" || s=="50" || s=="25" || s=="0"){
			printf("0\n");
			return 0;
		}
	
	int rs=INF;
	rep(i,4) rs=min(rs,solve(i));
	if(rs==INF) rs=-1;
	printf("%d\n", rs);
}