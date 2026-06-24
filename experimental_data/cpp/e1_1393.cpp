// LUOGU_RID: 92435041
#include<bits/stdc++.h>

using namespace std;

constexpr int N=1000000,mod=1e9+7;

inline void reduce(int &x){if(x>=mod) x-=mod;}

constexpr long long bas=8181891891890168,pmod=818189189189016811;

string s[N+10];

int id[2][N+10],dp[2][N+10],pres[2][N+10],len[2];

void sortstr(int x,int p){

	int n=s[x].size()-2,i;

	len[p]=n;

	int L=1,R=n+1,cnt=0,j;

	for(i=1;i<=n;++i){

		++cnt;

		if(s[x][i]!=s[x][i+1]){

			if(s[x][i+1]<s[x][i]) for(j=1;j<=cnt;++j) id[p][L++]=i-cnt+j;

			else for(j=1;j<=cnt;++j) id[p][R--]=i+1-j;

			cnt=0;

		}

	}

	id[p][L]=0;

}

long long pbas[N+10];

vector<long long> vec[N+10];

void inithash(int n){

	pbas[0]=1;

	int i,j;

	for(i=1;i<=N;++i) pbas[i]=(__int128)pbas[i-1]*bas%pmod;

	for(i=1;i<=n;++i){

		int m=s[i].size()-2;

		vec[i].resize(m+1);

		for(j=1;j<=m;++j){

			vec[i][j]=((__int128)bas*vec[i][j-1]+s[i][j])%pmod;

		}

	}

}

long long query(int x,int L,int R){

	return (vec[x][R]+(__int128)(pmod-vec[x][L-1])*pbas[R-L+1])%pmod;

}

bool cmp(int id1,int p1,int id2,int p2){

	bool flag=0;

	if(p1>p2) swap(p1,p2),swap(id1,id2),flag=1;

	if(!p1){

		if(!p2){

			int L=0,R=min(vec[id1].size(),vec[id2].size()),mid;

			while(L+1<R){

				mid=L+R>>1;

				if(query(id1,1,mid)==query(id2,1,mid)) L=mid;

				else R=mid;

			}

			if(flag) swap(id1,id2);

			return s[id1][R]<=s[id2][R];

		}

		if(query(id1,1,p2-1)!=query(id2,1,p2-1)){

			int L=0,R=min((int)vec[id1].size(),p2),mid;

			while(L+1<R){

				mid=L+R>>1;

				if(query(id1,1,mid)==query(id2,1,mid)) L=mid;

				else R=mid;

			}

			if(flag) swap(id1,id2);

			return s[id1][R]<=s[id2][R];

		}

		int L=p2-1,R=min(vec[id1].size(),vec[id2].size()-1),mid;

		while(L+1<R){

			mid=L+R>>1;

			if(query(id1,p2,mid)==query(id2,p2+1,mid+1)) L=mid;

			else R=mid;

		}

		if(!flag) return s[id1][R]<=s[id2][R+1];

		else return s[id1][R]>=s[id2][R+1];

	}

	int L,R,mid;

	if(query(id1,1,p1-1)!=query(id2,1,p1-1)){

		L=0,R=p1;

		while(L+1<R){

			mid=L+R>>1;

			if(query(id1,1,mid)==query(id2,1,mid)) L=mid;

			else R=mid;

		}

		if(flag) swap(id1,id2);

		return s[id1][R]<=s[id2][R];

	}

	int len=min((int)vec[id1].size()-1-p1,p2-p1);

	if(query(id1,p1+1,p1+len)!=query(id2,p1,p1+len-1)){

		L=0,R=len+1;

		while(L+1<R){

			mid=L+R>>1;

			if(query(id1,p1+1,p1+mid)==query(id2,p1,p1+mid-1)) L=mid;

			else R=mid;

		}

		if(!flag) return s[id1][p1+R]<=s[id2][p1+R-1];

		else return s[id1][p1+R]>=s[id2][p1+R-1];

	}

	if(len!=p2-p1) return !flag;

	L=p2,R=min(vec[id1].size(),vec[id2].size());

	while(L+1<R){

		mid=L+R>>1;

		if(query(id1,p2+1,mid)==query(id2,p2+1,mid)) L=mid;

		else R=mid;

	}

	if(flag) swap(id1,id2);

	return s[id1][R]<=s[id2][R];

}

int main(){

	ios::sync_with_stdio(0);

	cin.tie(0);

	int n;

	cin>>n;

	int i,j;

	for(i=1;i<=n;++i) cin>>s[i],s[i]='#'+s[i],s[i].push_back('\0');

	int p=0;

	sortstr(1,p);

	for(i=0;i<=len[p];++i) dp[0][i]=1;

	for(i=1;i<=len[p]+1;++i) reduce(pres[p][i]=pres[p][i-1]+dp[p][id[p][i]]);

	inithash(n);

	for(i=2;i<=n;++i){

		p^=1;

		sortstr(i,p);

		int top=0;

		for(j=1;j<=len[p]+1;++j){

			while(top<=len[p^1]){

				if(cmp(i-1,id[p^1][top+1],i,id[p][j])) ++top;

				else break;

			}

			dp[p][id[p][j]]=pres[p^1][top];

		}

		for(j=1;j<=len[p]+1;++j) reduce(pres[p][j]=pres[p][j-1]+dp[p][id[p][j]]);

	}

	cout<<pres[p][len[p]+1]<<'\n';

	return 0;

}