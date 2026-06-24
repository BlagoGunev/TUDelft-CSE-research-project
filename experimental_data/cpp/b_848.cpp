#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
#define REP(i,st,ed) for(int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(int i=st,i##end=ed;i>=i##end;--i)
namespace ioput{
#ifdef __linux__
	#define getchar getchar_unlocked
	#define putchar putchar_unlocked
#endif
	template<typename T>T read(){
		T x=0,f=1;
		char c=getchar();
		while((c<'0')||(c>'9')){if(c=='-')f=-1;c=getchar();}
		while((c>='0')&&(c<='9'))x=(x<<1)+(x<<3)+(c^48),c=getchar();
		return x*f;
	}
	template<typename T>void write(T x,char c){
		static char t[20];
		static int tlen;
		t[tlen=1]=c;
		if(x<0)putchar('-'),x=-x;
		do t[++tlen]=x%10+'0',x/=10;
		while(x);
		while(tlen)putchar(t[tlen--]);
	}
}
using namespace ioput;
const int maxn=100005;
struct seg{
	int id,pos,t;
	bool operator < (const seg &A) const {
		return pos-t==A.pos-A.t?pos<A.pos:pos-t<A.pos-A.t;
	}
}a[maxn],b[maxn],tmp[maxn];
int a_cnt,b_cnt;
int p[maxn],n,W,H;
pair<int,int>ans[maxn];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read<int>(),W=read<int>(),H=read<int>();
	int type,pos,t;
	REP(i,1,n){
		type=read<int>(),pos=read<int>(),t=read<int>();
		if(type==1)a[++a_cnt]=(seg){i,pos,t};
		else b[++b_cnt]=(seg){i,pos,t};
	}
	sort(a+1,a+1+a_cnt);
	sort(b+1,b+1+b_cnt);
	int cur=1;
	REP(i,1,a_cnt){
		static stack<int>stk;
		int j=i;
		while((j<a_cnt)&&(a[j+1].pos-a[j+1].t==a[i].pos-a[i].t))++j;
		int pos=j,tmpcur;
		while((cur<=b_cnt)&&(b[cur].pos-b[cur].t<a[i].pos-a[i].t))++cur;
		tmpcur=cur;
		DREP(k,j,i)stk.push(a[k].id);
		while((cur<=b_cnt)&&(b[cur].pos-b[cur].t==a[i].pos-a[i].t))stk.push(b[cur].id),++cur;
		REP(k,i,j)a[k].id=stk.top(),stk.pop();
		DREP(k,cur-1,tmpcur)b[k].id=stk.top(),stk.pop();
		i=j;
	}
	REP(i,1,a_cnt)
		ans[a[i].id]=make_pair(a[i].pos,H);
	REP(i,1,b_cnt)
		ans[b[i].id]=make_pair(W,b[i].pos);
	REP(i,1,n)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}