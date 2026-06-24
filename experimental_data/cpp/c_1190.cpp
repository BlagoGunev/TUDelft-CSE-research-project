#include<bits/stdc++.h>
using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=100005;
int n,k,pre[2],suf[2];
char s[maxn];

int main(){
	scanf("%d%d%s",&n,&k,s);
	while(pre[0]<n&&s[pre[0]]=='0')pre[0]++;
	while(pre[1]<n&&s[pre[1]]=='1')pre[1]++;
	while(suf[0]<n&&s[n-1-suf[0]]=='0')suf[0]++;
	while(suf[1]<n&&s[n-1-suf[1]]=='1')suf[1]++;
	if(pre[0]+suf[0]>=n-k||pre[1]+suf[1]>=n-k){
		puts("tokitsukaze");
		return 0;
	}
	bool ok=true;
	rep(i,n-k+1){
		//paint to 0
		int pre0=pre[0]>=i?max(pre[0],i+k):pre[0];
		int suf0=suf[0]>=n-(i+k)?max(suf[0],n-i+1):suf[0];
		if(pre0+suf0<n-k)ok=false;
		//paint to 1
		int pre1=pre[1]>=i?max(pre[1],i+k):pre[1];
		int suf1=suf[1]>=n-(i+k)?max(suf[1],n-i+1):suf[1];
		if(pre1+suf1<n-k)ok=false;
	}
	if(ok)puts("quailty");
	else puts("once again");
	return 0;
}