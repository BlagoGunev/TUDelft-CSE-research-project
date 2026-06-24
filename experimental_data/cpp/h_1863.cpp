#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#define int long long
using namespace std;

const int md=998244353;
void read(int &x){
	x=0;
	int f=1;
	char c=getchar();
	while(!('0'<=c && c<='9')){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c && c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	x*=f;
}
int powr(int b,int k){
	int res=1;
	for(;k;k>>=1,b=b*b%md){
		if(k&1){
			res=res*b%md;
		} 
	}
	return res;
}
vector<int> e[200010];
int n,q,anc[200010][20],dpt[200010],h[200010],dfn[200010],rev[200010],cnt=0;
bool is[200010];
set<pair<vector<int>,int> > st;
int getlca(int u,int v){
	u=rev[u];
	v=rev[v];
	if(dpt[u]<dpt[v]){
		swap(u,v);
	} 
	for(int i=19;~i;i--){
		if(dpt[anc[u][i]]>=dpt[v]){
			u=anc[u][i];
		}
	}
	if(u==v){
		return u;
	}
	for(int i=19;~i;i--){
		if(anc[u][i]!=anc[v][i]){
			u=anc[u][i];
			v=anc[v][i];
		}
	}
	return anc[u][0];
} 
void dfs(int k){
	rev[dfn[k]=++cnt]=k;
	for(int i:e[k]){
		dfs(i);
	}
}
void insert(pair<vector<int>,int> pos){
//	putchar('+');
//	for(auto i:pos.first){
//		printf("[%lld]",i);
//	}
//	printf(",%lld\n",pos.second);
	auto it=st.insert(pos).first;
	int val=0;
	
	if(prev(it)->first==pos.first && prev(it)->second>0){
		int l=getlca(prev(it)->second,pos.second);
		val=l;
	}
	if(next(it)->first==pos.first){
		int l=getlca(next(it)->second,pos.second);
		if(dpt[val]<dpt[l]){
			val=l;
		}
	}
	if(val){
		pos.first.push_back(dpt[val]);
		insert(make_pair(pos.first,dfn[val]));
	}
}
void remove(pair<vector<int>,int> pos){
//	putchar('-');
//	for(auto i:pos.first){
//		printf("[%lld]",i);
//	}
//	printf(",%lld\n",pos.second);
	auto it=st.find(pos);
	int val=0;
	if(prev(it)->first==pos.first && prev(it)->second>0){
		int l=getlca(prev(it)->second,pos.second);
		val=l;
	}
	if(next(it)->first==pos.first){
		int l=getlca(next(it)->second,pos.second);
		if(dpt[val]<dpt[l]){
			val=l;
		}
	}
	if(val){
		pos.first.push_back(dpt[val]);
		remove(make_pair(pos.first,dfn[val]));
	}
	st.erase(it);
}
signed main(){
	memset(is,1,sizeof(is));
	read(n);
	dpt[0]=-1;
	for(int i=2;i<=n;i++){
		read(anc[i][0]);
		e[anc[i][0]].push_back(i);
		dpt[i]=dpt[anc[i][0]]+1;
		for(int j=1;j<=19;j++){
			anc[i][j]=anc[anc[i][j-1]][j-1];
		}
		is[anc[i][0]]=0;
	}
	dfs(1);
	st.insert(make_pair(vector<int>(),-4e18));
	st.insert(make_pair(vector<int>(1,4e18),4e18));
	for(int i=1;i<=n;i++){
		read(h[i]);
		h[i]--;
		if(is[i] && h[i]>=0){
			vector<int> cur;
			for(int j=29;~j;j--){
				if(h[i]&(1<<j)){
					cur.push_back(j+dpt[i]);
				}
			}
			insert(make_pair(cur,dfn[i]));
		}
	}
	auto cur=next(st.rbegin())->first;
	if(st.size()!=2){
		int res=0;
		for(auto i:cur){
			res=(res+powr(2,i))%md;
		}
		printf("%lld\n",(res+1)%md);
	}else{
		printf("0\n");
	}
	read(q);
	int u,v;
	while(q--){
		read(u);
		read(v);
		v--;
		if(is[u] && h[u]>=0){
			vector<int> cur;
			for(int j=29;~j;j--){
				if(h[u]&(1<<j)){
					cur.push_back(j+dpt[u]);
				}
			}
			remove(make_pair(cur,dfn[u]));
		}
		h[u]=v;
		if(is[u] && h[u]>=0){
			vector<int> cur;
			for(int j=29;~j;j--){
				if(h[u]&(1<<j)){
					cur.push_back(j+dpt[u]);
				}
			}
			insert(make_pair(cur,dfn[u]));
		}
		auto cur=next(st.rbegin())->first;
		if(st.size()!=2){
			int res=0;
			for(auto i:cur){
				res=(res+powr(2,i))%md;
			}
			printf("%lld\n",(res+1)%md);
		}else{
			printf("0\n");
		}
	}
	return 0;
}