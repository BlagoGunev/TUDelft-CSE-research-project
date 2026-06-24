#include<cstdio>

#include<cstring>

char s[200010];

int i,n;

int main(){

	scanf("%s",s);

	n=strlen(s);

	for(i=n;i<2*n;i++)s[i]=s[2*n-i-1];

	printf("%s",s);

	return 0;

}