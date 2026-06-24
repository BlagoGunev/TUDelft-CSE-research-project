#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n;char s[MAXN];
void Solve(){
	scanf("%s",s+1);n=strlen(s+1);
	int hsh[2]={0,0};
	for(int i=1;i<=n;i++) hsh[s[i]-'0']++;
	if(hsh[0]==hsh[1]) printf("%d\n",hsh[0]-1);
	else printf("%d\n",min(hsh[0],hsh[1]));
}
int main(){
	int t;scanf("%d",&t);
	while(t--) Solve();
	return 0;
}