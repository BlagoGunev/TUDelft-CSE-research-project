#include<bits/stdc++.h>
#define f(i,a,b) for(register int i=a;i<=b;++i)
#define F(i,a,b) for(register int i=a;i>=b;--i)
using namespace std;
inline int read(){
	int x=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x;
}
int n,k,c[28];char s[100010];
inline void calc(int x,int y){
	memset(c,0,sizeof(c));
	s[x]=y+'a';
	f(i,1,x) ++c[s[i]-'a'];
	int sum=n-x;
	f(i,0,25) sum-=(k-c[i]%k)%k;
	f(i,1,x) putchar(s[i]);
	f(i,1,sum) putchar('a');
	f(i,0,25) f(j,1,(k-c[i]%k)%k) putchar('a'+i);
	puts("");
}
signed main(){
	int t=read();
	f(l,1,t){
		int sum=0;memset(c,0,sizeof(c));
		n=read();k=read();scanf("%s",s+1);
		if(n%k){puts("-1");continue;}
		f(i,1,n) ++c[s[i]-'a'];
		f(i,0,25) sum+=(k-c[i]%k)%k;
		if(!sum){puts(s+1);continue;}
		F(i,n,1){
			sum-=(k-c[s[i]-'a']%k)%k;
			--c[s[i]-'a'];
			sum+=(k-c[s[i]-'a']%k)%k;
			f(j,s[i]-'a'+1,25){
				int cur=sum;
				cur-=(k-c[j]%k)%k;++c[j];
				cur+=(k-c[j]%k)%k;--c[j];
				if(cur<=n-i){calc(i,j);goto label;}
			}
		}
		label:continue;
	}
	return 0;
}