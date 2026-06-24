#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
#define MAXN 200005
#define MAXM 500005
#define INF 0x7fffffff
#define ll long long

int A[MAXN];
bool vis[MAXN];
inline int read(){
	int x=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
		if(c=='-')
			f=-1;
	for(;isdigit(c);c=getchar())
		x=x*10+c-'0';
	return x*f;
}

int main(){
	int N=read(),p=1;
	bool fir=0;
	for(int i=1;i<=N;i++) A[i]=read();
	for(int i=1;i<=N;i++){
		int b=read();
		if(vis[b]){
			if(!fir) printf("0"),fir=1;
			else printf(" 0");
		}
		else{
			int cnt=0;
			for(;p<=N;p++){
				vis[A[p]]=1,cnt++;
				if(A[p]==b) break;
			}p++;
			if(!fir) printf("%d",cnt),fir=1;
			else printf(" %d",cnt);
		} 
	}
	printf("\n");
	return 0;
}