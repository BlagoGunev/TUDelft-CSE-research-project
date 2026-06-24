#include<cstdio>
using namespace std;

const int MAXN=200010;

int n,a[MAXN];

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	bool flag=1;
	for(int i=1;i<n;i++){
		a[i]&=1;
		if(a[i]&1)a[i+1]--;
		if(a[i+1]<0){
			flag=0;
			break;
		}
	}
	if(!flag||a[n]&1)printf("NO\n");
	else printf("YES\n");
	return 0;
}