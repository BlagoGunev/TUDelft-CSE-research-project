#include <bits/stdc++.h>

using namespace std;

inline long long read(){
	long long x(0);char ch('@');bool flag(false);
	for(;!isdigit(ch);ch=getchar())	flag|=(ch=='-');
	for(;isdigit(ch);ch=getchar())	x=(x<<3)+(x<<1)+(ch^48);
	return flag?-x:x;
}

int T;
int n,m;
char ch;
int col[50010],row[50010];
char ol[400010];

int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(register int i(1);i<=n;++i)
			for(register int j(1);j<=m;++j){
				ch=getchar();
				if(ch!='*'&&ch!='.')	ch=getchar();
				if(ch=='*')	++col[i],++row[j];
				ol[(i-1)*m+j]=ch;
			}
		int ans=0x7fffffff;
		for(register int i(1);i<=n;++i)
			for(register int j(1);j<=m;++j)
				ans=min(ans,n+m-col[i]-row[j]-(ol[(i-1)*m+j]=='.'));
		printf("%d\n",ans);
		for(register int i(1);i<=n;++i)	col[i]=0;
		for(register int j(1);j<=m;++j)	row[j]=0;
	}
	return 0;
}