#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
 
using namespace std;

int main(){
	char s[100001];
	int n;
	scanf("%s",s);
	n=strlen(s);
	char c=s[n-1];
	int ai=-1,aai=-1;
	for(int i=0;i<n-1;i++){
		if((s[i]-'0')&1)continue;
		if(s[i]<c){ai=i;break;}
		else if(s[i]>c){if(i>aai)aai=i;}
	}
	if(ai>=0||aai>=0){
		if(ai>=0)swap(s[ai],s[n-1]);
		else if(aai>=0)swap(s[aai],s[n-1]);
		printf("%s\n",s);
	}
	else printf("-1\n");
	return 0;
}