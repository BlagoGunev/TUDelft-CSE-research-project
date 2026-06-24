#include<iostream>
#include<cstdio>
#include<cstring>
#include<string.h>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<deque>
#include<time.h>
using namespace std;
inline void read(int &x){
	x=0;
	bool sgn=0;
	char ch;
	while(ch=getchar(),ch<'!');
	if(ch=='-'){
		sgn=1;
	}else{
		x=ch-48;
	}
	while(ch=getchar(),ch>'!'){
		x=(x<<3)+(x<<1)+ch-48;
	}
	if(sgn==1){
		x=-x;
	}
	return;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
	return;
}
inline void read(long long &x){
	x=0;
	bool sgn=0;
	char ch;
	while(ch=getchar(),ch<'!');
	if(ch=='-'){
		sgn=1;
	}else{
		x=ch-48;
	}
	while(ch=getchar(),ch>'!'){
		x=(x<<3)+(x<<1)+ch-48;
	}
	if(sgn==1){
		x=-x;
	}
	return;
}
inline void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
	return;
}
long long n,m,k,cnt,lcp[1050][1050],dp[1050][1050],redp[1050][1050]; 
char s[1050];
struct st{
	long long l,r;
}a[1000050];
inline bool operator<(st const &lhs,st const &rhs) {
	long long length=lcp[lhs.l][rhs.l];
	if(length>=lhs.r-lhs.l+1||length>=rhs.r-rhs.l+1){
		return lhs.r-lhs.l+1<rhs.r-rhs.l+1;
	}
	return s[lhs.l+length]<s[rhs.l+length];
}
inline bool check(long long x){
	memset(dp,0,sizeof(dp));
	memset(redp,0,sizeof(redp));
	redp[n+1][0]=1;
	long long length=a[x].r-a[x].l+1;
	for(int i=n;i>=1;i--){
		long long t=min(length,lcp[a[x].l][i]);
		if(t==length||s[i+t]>s[a[x].l+t]){
			for(int j=1;j<=m;j++){
				dp[i][j]=redp[i+t+1][j-1];
			}
		}
		for(int j=0;j<=m;j++){
			redp[i][j]=min(redp[i+1][j]+dp[i][j],k);
		}
	}
	return dp[1][m]>=k;
}
int main(){
	read(n);
	read(m);
	read(k);
	scanf("%s",s+1);
	for(int i=n;i>=1;i--){
		for(int j=n;j>=1;j--){
			lcp[i][j]=0;
			if(s[i]==s[j]){
				lcp[i][j]=lcp[i+1][j+1]+1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			a[++cnt]=st{i,j};
		}
	}
	sort(a+1,a+1+cnt);
	long long l=1,r=cnt;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	for(int i=a[l].l;i<=a[l].r;i++){
		putchar(s[i]);
	}
	return 0;
}