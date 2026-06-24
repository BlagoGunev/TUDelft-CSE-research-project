#include<cstdio>

#include<cstdlib>

#include<algorithm>

#include<cstring>

#define cl(x) memset(x,0,sizeof(x))

using namespace std;



inline char nc(){

  static char buf[100000],*p1=buf,*p2=buf;

  if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }

  return *p1++;

}



inline void read(int &x){

  char c=nc(),b=1;

  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;

  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;

}



const int N=205;

const int M=40005;



int n,m;

int E[N][N],w[N][N];

int cnt,blo[N],vst[N];

int deg[N];



#define V G[p].v

inline void dfs(int u){

  blo[u]=cnt;

  for (int i=1;i<=n;i++)

    if (w[u][i] && !blo[i])

      dfs(i);

}



inline void find(int u){

  for (int i=1;i<=n;i++)

    if (w[u][i]){

      if (E[u][i])

	E[u][i]--,E[i][u]--,printf("%d %d\n",u,i);

      w[u][i]--,w[i][u]--;

      find(i);

    }

}



int main(){

  int iu,iv,ans,T;

  read(T);

  while (T--){

    read(n); read(m);

    for (int i=1;i<=m;i++){

      read(iu),read(iv);

      E[iu][iv]++; E[iv][iu]++;

      w[iu][iv]++; w[iv][iu]++;

      deg[iu]++; deg[iv]++;

    }

    ans=0;

    for (int i=1;i<=n;i++)

      if (deg[i]%2==0)

	ans++;

    printf("%d\n",ans);

    for (int i=1;i<=n;i++)

      if (!blo[i])

	++cnt,dfs(i);

    for (int i=1;i<=n;i++)

      if (deg[i]%2)

	for (int j=1;j<=n;j++)

	  if (i!=j && deg[j]%2){

	    w[i][j]++; w[j][i]++;

	    deg[i]++; deg[j]++;

	    break;

	  }

    for (int i=1;i<=n;i++)

      if (!vst[blo[i]])

	vst[blo[i]]=1,find(i);

    cl(E); cl(w);  cl(deg);

    cnt=0; cl(blo); cl(vst);

  }

  return 0;

}