#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
inline ll read(){
	ll x=0,f=1;	
	char ch=getchar();	
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();	
	}	
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();	
	}	
	return x*f;
}
const int maxn=2e5+5;
int t,n;
struct node{
	int x,y;
	bool operator<(const node &a)const{
		return x<a.x;
	} 
}p[maxn];
vector<pair<int,int> > ans;
int main(){
	t=read();
	while(t--){
		ans.clear();
		n=read();
		for(int i=1;i<=n;++i){
			p[i].x=read();
			p[i].y=i;
		}
		sort(p+1,p+n+1);
		int l=1,r=n;
		while(l<r){
			while(p[l].x&&p[r].x){
				--p[l].x;
				--p[r].x;
				ans.push_back({p[l].y,p[r].y});
			}
			if(!p[l].x) ++l;
			if(!p[r].x) --r;
		}
		if(p[l].x>=2){
			for(int i=0;i<ans.size();++i){
				if(p[l].x>=2&&ans[i].first!=p[l].y&&ans[i].second!=p[l].y){
					ans.push_back({ans[i].first,p[l].y});
					ans[i].first=p[l].y;
					p[l].x-=2;
				}
			}
		}
		if(p[r].x>=2){
			for(int i=0;i<ans.size();++i){
				if(p[r].x>=2&&ans[i].first!=p[r].y&&ans[i].second!=p[r].y){
					ans.push_back({ans[i].first,p[r].y});
					ans[i].first=p[r].y;
					p[r].x-=2;
				}
			}
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();++i) printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}