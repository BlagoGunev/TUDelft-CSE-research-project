#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using tii=tuple<int, int, int>;
inline int read(){
	register int res=0, c;
	while(c=getchar(), c<'0'||c>'9');
	do{
		res=(res*10)+(c^48);
	} while(c=getchar(), c>='0'&&c<='9');
	return res;
}
const char id[]="qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPLKJHGFDSAZXCVBNM";
int main(){
	int T=read();
	while(T--){
		int N=read(), M=read(), R=read(), cnt=0;
		vector<string> mp(N, string(M, '0'));
		vector<string> ans(N, string(M, '0'));
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				mp[i][j]=getchar();
				if(mp[i][j]=='R')cnt++;
			}
			getchar();
		}
		int a = cnt/R, b=cnt%R, c=0, now=0;
		auto pos = [&](int x)->pii{
			int a = x/M;
			int b = (a&1)?M-1-x%M:x%M;
			return {a, b};
		};
		for(int i=0; i<N*M; i++){
			int x, y;
			tie(x, y) = pos(i);
			if(mp[x][y]=='R'){
				c++;
				ans[x][y]=id[now];
				if(c == a+(b>0)){
					b--;
					c=0;
					if(now<R-1)now++;
				}
			}
			else ans[x][y]=id[now];
		}
		for(int i=0; i<N; i++)printf("%s\n", ans[i].c_str());
	}
	return 0;
}