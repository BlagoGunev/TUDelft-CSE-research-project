#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
char buf[100010];
int cc[255];
//Bulbasaur B-1 u-2 l-1 b-2 a-2 s-1 r-1
int main(){
	scanf("%s",buf);
	int len=strlen(buf);
	for(int i=0;i<len;i++){
		cc[buf[i]]++;
	}
	int ans=0;
	ans=min(cc['B'],cc['u']/2);
	ans=min(ans,cc['l']);
	ans=min(ans,cc['b']);
	ans=min(ans,cc['a']/2);
	ans=min(ans,cc['s']);
	ans=min(ans,cc['r']);
	printf("%d",ans);
	return 0;
}