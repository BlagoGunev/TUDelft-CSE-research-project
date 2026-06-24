#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>
inline void read(T &x) {
	Finish_read=0;
	x=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-')f=-1;
		if(ch==EOF)return;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	x*=f;
	Finish_read=1;
}
template<class T>
inline void print(T x) {
	if(x/10!=0)
		print(x/10);
	putchar(x%10+'0');
}
template<class T>
inline void writeln(T x) {
	if(x<0)
		putchar('-');
	x=abs(x);
	print(x);
	putchar('\n');
}
template<class T>
inline void write(T x) {
	if(x<0)
		putchar('-');
	x=abs(x);
	print(x);
}
/*================Header Template==============*/
const int N=3e5+10;
int n,m,s,ans,cnt,fir[N],used[N*2],vis[N];
struct Edge
 {
 	 int pre,arr,type,nex,num,ax,use;
 }a[N*2];

void add(int x,int y,int t,int nx,int r)
 {
 	 cnt++;
 	 a[cnt].pre=x; a[cnt].arr=y;
 	 a[cnt].type=t; a[cnt].num=nx;
 	 a[cnt].nex=fir[x];
 	 fir[x]=cnt;
 	 a[cnt].ax=r;
 }

void dfs1(int x)
 {
 	 if (vis[x]) return;
	 vis[x]=1; ans++;
 	 for (int i=fir[x];i;i=a[i].nex)
 	  if (a[i].type==1)
 	  {
 	  	 if (!vis[a[i].arr]) dfs1(a[i].arr);
	  }
}

void dfs2(int x)
 {
 	 if (vis[x]) return;
	 vis[x]=1; ans++;
 	 for (int i=fir[x];i;i=a[i].nex)
 	  if (a[i].type==1)
 	   {
	   	 if (!vis[a[i].arr]) dfs2(a[i].arr);
	   }
	  else if (!used[a[i].num]&&(!vis[a[i].arr]))
	   {
	   	 used[a[i].num]=1;
	   	 a[i].use=1;
	   	 dfs2(a[i].arr);
	   }
 }

main()
 {
     read(n); read(m); read(s);
     for (int i=1;i<=m;i++)
      {
      	 int x,y,t;
      	  read(t);read(x); read(y);
      	 if (t==1)
      	  {
     	  	 add(x,y,1,i,1);
		  }
		 else 
		  {
			 add(x,y,2,i,1);
			 add(y,x,2,i,2);
		  }
	  }
	 dfs2(s);
	 writeln(ans);
	 for (int i=1;i<=cnt;i++)
	  if ((a[i].type==2&&a[i].use)||(a[i].ax==2&&used[a[i].num]==0))
	   if (a[i].ax==1) putchar('+');
	    else putchar('-');
	 ans=0;
	 putchar('\n');
	 memset(vis,0,sizeof(vis));
	 memset(used,0,sizeof(used));  
	 dfs1(s);
	 writeln(ans);
	 for (int i=1;i<=cnt;i++)
	  if (!used[a[i].num]&&a[i].type==2)
	   {
	  	 used[a[i].num]=1;
	  	 if (vis[a[i].pre]&&(!vis[a[i].arr])) putchar('-');
	 	  else putchar('+');
	   }
 }