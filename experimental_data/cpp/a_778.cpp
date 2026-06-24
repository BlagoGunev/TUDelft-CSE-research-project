#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	char c=getchar();int p=1,ret=0;
	while((c<'0')||(c>'9')){if(c=='-')p=-1;c=getchar();}
	while((c>='0')&&(c<='9'))ret=(ret<<1)+(ret<<3)+c-'0',c=getchar();
	return ret*p;
}
char s[200005],S[200005],tmp[200005];
int n,m;
int a[200005];
inline bool check(int k){
	int len=0;
	for(int i=1;i<=n;i++)if(a[i]>k)tmp[++len]=S[i];
	int now=1;
	for(int i=1;i<=len;i++){
		if(s[now]==tmp[i])now++;
		if(now>m)break;
	}
	return now>m;
}
int main(){
	scanf("%s",S+1);scanf("%s",s+1);
	n=strlen(S+1);m=strlen(s+1);
	for(int i=1;i<=n;i++)a[read()]=i;
	int l=0,r=n-m+1;
	while(r-l>1){
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	printf("%d",l);
}