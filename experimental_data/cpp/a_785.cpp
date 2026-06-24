#include<cstdio>
#include<cstring>
#define MAXN 200001
using namespace std;
int n,ans;
char s[20];
int main()
{
	scanf("%d\n",&n);
	for(int i=0;i<n;i++){
		gets(s);
		switch(s[0]){
			case 'T':
				ans+=4;
				break;
			case 'C':
				ans+=6;
				break;
			case 'O':
				ans+=8;
				break;
			case 'D':
				ans+=12;
				break;
			case 'I':
				ans+=20;
				break;
		}
	}
	printf("%d",ans);
	return 0;
}