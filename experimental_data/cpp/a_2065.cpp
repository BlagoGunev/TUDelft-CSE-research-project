#include<bits/stdc++.h>
using namespace std;

//#define ONLINE
#ifndef ONLINE
char DEBUG_BUFFER[1000];
#define debug(...) {sprintf(DEBUG_BUFFER,##__VA_ARGS__);\
cerr<<"\033[1;36m"<<DEBUG_BUFFER<<"\033[0;2m"<<"\033[0m";}
#else
#define debug(...) ;
#endif

using LL=long long;
using PII=pair<int,int>;
#define ai(x) using ai##x=array<int,x>;
ai(2);ai(3);ai(4);ai(5);ai(6);ai(7);ai(8);ai(9);ai(10);
#undef ai

#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()

#define FAST_IO {ios::sync_with_stdio(false);cin.tie(nullptr);}
inline int read(){static int x; cin>>x; return x;}
inline LL readLL(){static LL x; cin>>x; return x;}
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

void solve(){
	string s; cin>>s;
	s.pop_back();
	s.pop_back();
	cout<<s<<"i\n";
}
int main(){
	FAST_IO;
	for(int T=read();T--;) solve();
	return 0;
}

/* stuff you should look for
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
*/