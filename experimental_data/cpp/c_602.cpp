#include<cstdio>

#include<cstring>

#include<algorithm>

#include<set>

#include<map>

#define Rep(i,x,y) for (int i=x;i<=y;i++)

#define Dep(i,x,y) for (int i=x;i>=y;i--)



using namespace std;

typedef long long ll;

typedef double ld;

typedef pair<int,int> PII;

typedef pair<double,int> PDI;

typedef pair<double,double> PDD;

typedef map<int,int> MII;

typedef set<int> SI;

inline int read(){

	int f=1,res=0,ch=getchar();

	while (ch<'0' or ch>'9'){if (ch=='-') f=-1;ch=getchar();}

	while (ch>='0' && ch<='9') res=res*10+ch-48,ch=getchar();

	return f*res;

}

const int N=405;

int n,m,que[N],dis[N],E[N][N];

int Bfs(int type){

	int head=0,tail=1;

	dis[que[1]=1]=1;

	while (head<tail){

		int u=que[++head];

		for (int i=1;i<=n;i++)

			if (E[u][i]==type && !dis[i]){

				dis[que[++tail]=i]=dis[u]+1;

			}

	}

	return dis[n]-1;

}

int main(){

	scanf("%d%d",&n,&m);Rep(i,1,m){

		int x=read(),y=read();

		E[x][y]=E[y][x]=1;

	}

	printf("%d\n",Bfs(E[1][n]^1));

}