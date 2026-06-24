#include<bits/stdc++.h>

#define ll long long

#define ri register

#define all(x) x.begin(),x.end()

using namespace std;

const int N=4e5+7;

char a[5];

int n,m,k,in[N],t[N][27],cnt,ed[N],op;

vector<int>e[N],ans;

bool flg;

inline void dfs(int x,int y){

	if(y>k){

		if(ed[x]==op)flg=1;

		else e[op].emplace_back(ed[x]),in[ed[x]]++;

		return;

	}

	if(t[x][a[y]-'a'])dfs(t[x][a[y]-'a'],y+1);

	if(t[x][26])dfs(t[x][26],y+1);

}

queue<int>q;

inline void Topu(){int u;

	for(int i=1;i<=n;i++)if(!in[i])q.push(i);

	while(!q.empty()){

		u=q.front(),q.pop();

		ans.emplace_back(u);

		for(int v:e[u])

			if(!--in[v])q.push(v);

	}

	if((int)ans.size()^n)puts("NO");

	else{

		puts("YES");

		for(int i:ans)printf("%d ",i);

	}

}

int main(){

	scanf("%d%d%d",&n,&m,&k);

	for(int i=1,x;i<=n;i++){

		scanf("%s",a+1),x=0;

		for(int j=1;j<=k;j++)

			if(a[j]=='_'){

				if(!t[x][26])t[x][26]=++cnt;

				x=t[x][26];

			}else{

				if(!t[x][a[j]-'a'])t[x][a[j]-'a']=++cnt;

				x=t[x][a[j]-'a'];

			}

		ed[x]=i;

	}

	for(int i=1;i<=m;i++){

		scanf("%s%d",a+1,&op);

		flg=0,dfs(0,1);

		if(!flg)return puts("NO")&0;

	}

	Topu();

	return 0;

}