#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int read()//不管是正负数，都可以 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
		return positive ? x : -x;
}
const int N=200005;
int nedge,n,m,nextt[N],son[N],ed[N],dist[N],vis[N],cd[N]; double ans;
inline void aedge(int a,int b){
	cd[a]++; nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b; 
}
inline void dfs(int p,int fa,double gai,int deep){
	if(p!=1)cd[p]--; int zs=0;
	for(int i=son[p];i;i=nextt[i])if(ed[i]!=fa){
		zs++; dfs(ed[i],p,gai/cd[p],deep+1);
	}
    //cout<<p<<" "<<zs<<" "<<gai<<" "<<deep<<endl;
	if(!zs){
		ans+=gai*deep; 
	}
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int s1=read(),s2=read(); aedge(s1,s2); aedge(s2,s1);
	}
	dfs(1,0,1,0);
	printf("%.7lf\n",ans);
}