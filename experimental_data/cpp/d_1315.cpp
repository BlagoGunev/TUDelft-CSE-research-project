#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
using namespace std;
int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
long long READ(){
    long long xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
char one(){
	char ch=getchar();
	while(ch==' '||ch=='\n'||ch=='\r')
		ch=getchar();
	return ch;
}
const int maxn=200010;
int n;
struct my{
	int a,t;
	bool friend operator<(const my&A,const my&B){
		return A.a<B.a||(A.a==B.a&&A.t<B.t);
	}
}p[maxn];
priority_queue<int>pq;
int main(){
	//freopen("in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++)
		p[i].a=read();
	for(int i=1;i<=n;i++)
		p[i].t=read();
	p[++n].a=int(2e9)+10,p[n].t=0;
	
	sort(p+1,p+1+n);
	long long ans=0,sum;
	pq.push(p[1].t);sum=p[1].t;
	for(int i=2;i<=n;i++){
		int tmp=p[i].a-p[i-1].a;
		for(int j=0;j<tmp&&!pq.empty();j++){
			int x=pq.top();
			pq.pop();sum-=x;
			ans+=1LL*x*j;
		}
		ans+=sum*tmp;
		pq.push(p[i].t);sum+=p[i].t;
	}
	//printf("%d\n",pq.size());
	printf("%I64d\n",ans);
	return 0;
}