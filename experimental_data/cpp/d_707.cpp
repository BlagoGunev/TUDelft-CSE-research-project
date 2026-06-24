#include <ctime>

#include <cstdio>

#include <cctype>

#include <cstring>

#include <cstdlib>

#include <cassert>

#include <iostream>

#include <algorithm>

#include <vector>

using namespace std;

typedef long long ll;

typedef double db;

typedef long double ldb;

typedef pair<int,int>pii;

typedef vector<int> vi;

typedef vector<pii> vpii;

#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();++it)

#define rep(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)

#define per(i,a,b) for(int i=(b)-1,i##_begin_=(a);i>=i##_begin_;--i)

#define all(x) (x).begin(),(x).end()

#define fi first

#define se second

#define mp make_pair

#define pb push_back

#define sz(x) ((int)(x).size())

const int inf=(int)1e9;

const int INF=0x7fffffff;

const ll linf=1LL<<60;

template <typename Tp>inline void read_positive(Tp &res){

	char c;res=0;

	while(c=getchar(),!isdigit(c));

	do res=(res<<1)+(res<<3)+(c^48);

	while(c=getchar(),isdigit(c));

}

template <typename Tp>void print(Tp x){

	if(x==0)return;

	print(x/10);

	putchar(x%10^48);

}

template <typename Tp>inline void print_positive(Tp x){

	if(x==0)putchar('0');

	else print(x);

}

const int N=(int)1e3;

const int Q=(int)1e5;

struct Query{

	int f,x,y;

}query[Q+5];

int n,m,q;

int top[Q+5];

vector<int>mate[Q+5];

void input(){

	scanf("%d %d %d",&n,&m,&q);

	//init

	rep(i,0,q+1)top[i]=i;

	rep(i,0,q+1)mate[i].resize(1,i);

	

	rep(i,1,q+1){

		int f;read_positive(f);

		if(f==1||f==2){

			int x,y;

			read_positive(x);

			read_positive(y);

			query[i]=(Query){f,x,y};

		}else{

			int x;

			read_positive(x);

			query[i]=(Query){f,x,0};

			if(f==4){

				top[i]=top[top[x]];

				mate[top[i]].pb(i);

			}

		}

	}

}

bool book[N+5][N+5];

bool rev[N+5];

int cnt[N+5],sum;

void init(){

	rep(i,1,n+1){

		rep(j,1,m+1)book[i][j]=false;

		rev[i]=false;

		cnt[i]=0;

	}

	sum=0;

}

int ans[Q+5];

void add(int x,int y){

	bool c=book[x][y]^rev[x];

	if(c)return;

	book[x][y]^=1;

	cnt[x]++;

	sum++;

}

void remove(int x,int y){

	bool c=book[x][y]^rev[x];

	if(!c)return;

	book[x][y]^=1;

	cnt[x]--;

	sum--;

}

void reverse(int x){

	rev[x]^=1;

	sum-=cnt[x];

	cnt[x]=m-cnt[x];

	sum+=cnt[x];

}

void dfs(int cur){

//	printf("cur %d\n",cur);

	rep(i,0,sz(mate[cur])){

		int u=mate[cur][i];

//		printf("  cur %d mate %d\n",cur,u);

		ans[u]=sum;

//		rep(j,1,n+1){

//			rep(k,1,m+1)cout<<book[j][k];

//			puts("");

//		}

//		puts("");

		int v=u+1;

		if(v>q)continue;

		int f=query[v].f,x=query[v].x,y=query[v].y;

		

		int msum,mcnt;

		bool mbook;

		if(f==1||f==2)msum=sum,mcnt=cnt[x],mbook=book[x][y];

		

		if(f==1)add(x,y);

		else if(f==2)remove(x,y);

		else if(f==3)reverse(x);

		else continue;

		

//		printf("cur %d before sum %d\n",cur,sum);

		dfs(v);

//		printf("cur %d after sum %d\n",cur,sum);

		

		if(f==1||f==2){

			cnt[x]=mcnt;

			sum=msum;

			book[x][y]=mbook;

		}else{

			reverse(x);

		}

//		if(f==1)remove(x,y);

//		else if(f==2)add(x,y);

//		else if(f==3)reverse(x);

//		else assert(false);

	}

}

void output(){

	rep(i,1,q+1){

		print_positive(ans[i]);

		putchar('\n');

	}

}

int main(){

	input();

	init();

	dfs(0);

	output();

	return 0;

}