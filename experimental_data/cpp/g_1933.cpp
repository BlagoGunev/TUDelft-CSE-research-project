#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define SZ(v) ((int)v.size())
#define fs first
#define sc second
#define all(x) (x.begin()),(x.end())
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
vector<string> temp(9);
int ok[10];
string now;
ll t,n,m,q,r,c;
int ans(){
	int ret=0;
	rep(i,1,8)	ret+=ok[i];
	return ret;
}
int main(){
	temp[1]+='1';
	temp[1]+='1';
	temp[1]+='2';
	temp[1]+='2';
	temp[1]+='2';
	temp[1]+='2';
	temp[1]+='1';
	temp[1]+='1';
	temp[1]+='1';
	temp[1]+='1';
	temp[1]+='2';
	temp[1]+='2';
	temp[1]+='2';
	temp[1]+='2';
	temp[1]+='1';
	temp[1]+='1';
	temp[2]+='1';
	temp[2]+='2';
	temp[2]+='1';
	temp[2]+='2';
	temp[2]+='1';
	temp[2]+='2';
	temp[2]+='1';
	temp[2]+='2';
	temp[2]+='2';
	temp[2]+='1';
	temp[2]+='2';
	temp[2]+='1';
	temp[2]+='2';
	temp[2]+='1';
	temp[2]+='2';
	temp[2]+='1';
	temp[3]+='1';
	temp[3]+='2';
	temp[3]+='1';
	temp[3]+='2';
	temp[3]+='2';
	temp[3]+='1';
	temp[3]+='2';
	temp[3]+='1';
	temp[3]+='2';
	temp[3]+='1';
	temp[3]+='2';
	temp[3]+='1';
	temp[3]+='1';
	temp[3]+='2';
	temp[3]+='1';
	temp[3]+='2';
	temp[4]+='1';
	temp[4]+='2';
	temp[4]+='2';
	temp[4]+='1';
	temp[4]+='2';
	temp[4]+='1';
	temp[4]+='1';
	temp[4]+='2';
	temp[4]+='1';
	temp[4]+='2';
	temp[4]+='2';
	temp[4]+='1';
	temp[4]+='2';
	temp[4]+='1';
	temp[4]+='1';
	temp[4]+='2';
	temp[5]+='2';
	temp[5]+='1';
	temp[5]+='1';
	temp[5]+='2';
	temp[5]+='1';
	temp[5]+='2';
	temp[5]+='2';
	temp[5]+='1';
	temp[5]+='2';
	temp[5]+='1';
	temp[5]+='1';
	temp[5]+='2';
	temp[5]+='1';
	temp[5]+='2';
	temp[5]+='2';
	temp[5]+='1';
	temp[6]+='2';
	temp[6]+='1';
	temp[6]+='2';
	temp[6]+='1';
	temp[6]+='1';
	temp[6]+='2';
	temp[6]+='1';
	temp[6]+='2';
	temp[6]+='1';
	temp[6]+='2';
	temp[6]+='1';
	temp[6]+='2';
	temp[6]+='2';
	temp[6]+='1';
	temp[6]+='2';
	temp[6]+='1';
	temp[7]+='2';
	temp[7]+='1';
	temp[7]+='2';
	temp[7]+='1';
	temp[7]+='2';
	temp[7]+='1';
	temp[7]+='2';
	temp[7]+='1';
	temp[7]+='1';
	temp[7]+='2';
	temp[7]+='1';
	temp[7]+='2';
	temp[7]+='1';
	temp[7]+='2';
	temp[7]+='1';
	temp[7]+='2';
	temp[8]+='2';
	temp[8]+='2';
	temp[8]+='1';
	temp[8]+='1';
	temp[8]+='1';
	temp[8]+='1';
	temp[8]+='2';
	temp[8]+='2';
	temp[8]+='2';
	temp[8]+='2';
	temp[8]+='1';
	temp[8]+='1';
	temp[8]+='1';
	temp[8]+='1';
	temp[8]+='2';
	temp[8]+='2';
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>q;
		string ss;
		rep(i,1,8)	ok[i]=1;
		cout<<ans()<<endl;
		while(q--){
			cin>>r>>c>>ss;
			char now;
			if(ss[0]=='c')	now='1';
			else	now='2';
			r--;c--;r%=4;c%=4;
			rep(i,1,8){
				if(temp[i][r*4+c]!=now)	ok[i]=0;
			}
			cout<<ans()<<endl;
		}
	}
	return 0;
}