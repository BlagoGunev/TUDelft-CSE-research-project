#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int _=2e5+5;
int n,k;
int z[_],p[_];
string s;
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>s,n=s.size(),s=' '+s+' ';
	for(int i=1,lst=0;i<=n;i++){
		if(s[i]!=s[i+1])
			z[++k]=s[i]-'A'+1,p[k]=i-lst,lst=i;
	}
	if((k&1)==0||p[(k+1)/2]<2)
		goto die;
	for(int i=1,mid=(k+1)/2;i<mid;i++){
		if(z[mid-i]!=z[mid+i]||p[mid-i]+p[mid+i]<3)
			goto die;
	}
	printf("%d",p[(k+1)/2]+1);
	return 0;
die:;
	printf("0");
}