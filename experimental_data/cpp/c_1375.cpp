#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;
	bool f=false;
	char c=getchar();
	while(!isdigit(c))f|=c=='-',c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?~x+1:x;
}
int a[300005];
int main(){
	int T=read();
	for(register int _=0;_<T;++_){
		int n=read();
		for(register int i=0;i<n;++i){
			a[i]=read();
		}
		int last=n-1;
		for(register int i=n-2;~i;--i){
			if(a[i]>a[i+1]){
				break;
			}
			else{
				--last;
			}
		}
		if(!last){
			printf("YES\n");
			continue;
		}
		int start=0;
		int maxn=a[0];
		for(register int i=1;i<n-2;++i){
			if(a[i]<start){
				if(maxn<start){
					maxn=start;
				}
				start=a[i];
			}
		}
		if(maxn>a[n-1]){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	return 0;
}