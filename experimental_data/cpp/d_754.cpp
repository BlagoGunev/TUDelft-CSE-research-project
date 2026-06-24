#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<ext/pb_ds/priority_queue.hpp>  
#include<queue>
#include<stack>
using namespace std;
typedef long long LL;
typedef pair<int,int>pii;
typedef unsigned uint;
typedef unsigned long long uLL;
const double pi=acos(-1);
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
//
priority_queue<pii,vector<pii>,greater<pii> >q;
#define MAXN 300000
pair<pii,int>a[MAXN+10];
int n,k,mx,pos;
void read(){
	Read(n),Read(k);
	int i;
	for(i=1;i<=n;i++)
		Read(a[i].first.first),Read(a[i].first.second),a[i].second=i;
	sort(a+1,a+n+1);
}
void solve(){
	int i;
	for(i=1;i<=n;i++){
		while(!q.empty()&&q.top().first<a[i].first.first)
			q.pop();
		q.push(pii(a[i].first.second,a[i].second));
		while(q.size()>k)
			q.pop();
		if(q.size()<k)
			continue;
		if(q.top().first-a[i].first.first+1>mx)
			mx=q.top().first-a[i].first.first+1,pos=i;
	}
	if(!mx){
		puts("0");
		for(int i=1;i<=k;i++)
			printf("%d ",i);
	}
	else{
		while(!q.empty())
			q.pop();
		for(i=1;i<=n;i++){
			while(!q.empty()&&q.top().first<a[i].first.first)
				q.pop();
			q.push(pii(a[i].first.second,a[i].second));
			while(q.size()>k)
				q.pop();
			if(i==pos)
				break;
		}
		printf("%d\n",mx);
		while(!q.empty()){
			printf("%d ",q.top().second);
			q.pop();
		}
	}
}
int main()
{
	read();
	solve();
}