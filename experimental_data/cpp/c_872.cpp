#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100000+5;

int n,q;

inline int read(){
	int k=1,x=0;char ch=0;
	while(ch<'0'||ch>'9'){if(ch=='-')k=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*k;
}

int main(){
	n=read();
	int ans=0;
	while(n--){
		q=read();
		if(q<4){
			printf("-1\n");
			continue;
		}
		if(q%2){
			q-=9;
			if(q<4&&q!=0){
				printf("-1\n");
				continue;
			} 
			else printf("%d\n",q/4+1);
		}
		else{
			printf("%d\n",q/4);
		}
	}
	return 0;
}