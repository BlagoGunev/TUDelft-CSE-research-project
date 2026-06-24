#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define mes(a,b) memset(a,b,sizeof(a))
const int maxn = 2e5+10;
char s[maxn];
char color[10]="RGB";
int pos[27];
int main(){
	int n;
	mes(pos,-1);
	pos['R'-'A']=0;
	pos['G'-'A']=1;
	pos['B'-'A']=2;
	scanf("%d",&n);
	scanf("%s",s);
	int ans=0;
	for(int i=1;s[i];i++){
		if(s[i+1]!=0){
			if(s[i]==s[i-1]){
				ans++;
				if(s[i-1]=='R'||s[i+1]=='R'){
					if(pos[s[i+1]-'A']+pos[s[i-1]-'A']==1) s[i]=color[2];
					else s[i]=color[1];
				}
				else
					s[i]=color[(pos[s[i+1]-'A']+pos[s[i-1]-'A'])%3];
			}
		}
		else{
			if(s[i]==s[i-1]){
				ans++;
				s[i]=color[(pos[s[i-1]-'A']+1)%3];
			}
		}
	}
	printf("%d\n%s\n",ans,s);
}