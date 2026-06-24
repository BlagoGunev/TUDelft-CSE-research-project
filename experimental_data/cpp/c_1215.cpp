#include<bits/stdc++.h>
#define maxn 200005
#define maxm 500005
#define inf 0x7fffffff
#define ll long long

using namespace std;
int N; char s[maxn],t[maxn];
stack<int> s1,s2;

inline int read(){
    int x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}

int main(){
	N=read();
	scanf("%s%s",s+1,t+1);
	int numa=0,ans=0;
	for(int i=1;i<=N;i++)
		numa+=(s[i]=='a')+(t[i]=='a');
	if(numa%2){printf("-1\n");return 0;}
	int num1=0,num2=0;
	for(int i=1;i<=N;i++){
		if(s[i]=='a' && t[i]=='b') num1++,s1.push(i);
		if(s[i]=='b' && t[i]=='a') num2++,s2.push(i);
	} 
	ans+=num1/2+num2/2;
	if(num1%2) ans+=2;
	printf("%d\n",ans);
	while(s1.size()>1){
		printf("%d ",s1.top()),s1.pop();
		printf("%d\n",s1.top()),s1.pop();
	}
	while(s2.size()>1){
		printf("%d ",s2.top()),s2.pop();
		printf("%d\n",s2.top()),s2.pop();
	}
	if(s1.size()){
		printf("%d %d\n",s1.top(),s1.top());
		printf("%d %d\n",s1.top(),s2.top());
		s1.pop(),s2.pop();
	}
	return 0;
}