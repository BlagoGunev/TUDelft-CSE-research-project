#include<iostream>
#include<cstring>
using namespace std;
int n,x;
int read(){
	int num=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))num=num*10+ch-48,ch=getchar();
	return num;
}
int leastget[100005];
int ans=100005;
int main(){
	memset(leastget,-1,sizeof(leastget));
	n=read(),x=read();
	for(int i=0;i<n;i++){
		int tmp=read();
		if(leastget[tmp]!=-1){
			ans=min(ans,leastget[tmp]);
		}
		leastget[tmp]=0;
		if((tmp&x)==tmp)
			continue;
		if(leastget[tmp&x]!=-1){
			ans=min(ans,leastget[tmp&x]+1);
		}
		else leastget[tmp&x]=1;
	}
	if(ans!=100005)cout<<ans;
	else cout<<-1;
}