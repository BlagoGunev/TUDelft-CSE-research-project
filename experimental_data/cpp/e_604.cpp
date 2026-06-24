#include<cstdio>
typedef long long ll;
typedef double lf;
const int INT=1<<30;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
int n,k,ans;
inline int sg(int x){
	if(x==1||x==3)
		return 1;
	if(x==2)
		return 0;
	if(x==4)
		return 2;
	if(x&1)
		return 0;
	int temp=sg(x>>1);
	if(temp==1)return 2;
	else return 1;
}
int main(){
	//freopen("in","r",stdin);
	n=read(),k=read()&1;
	if(k==0){
		for(int i=1;i<=n;i++){
			int ai=read();
			if(ai==1)
				ans^=1;
			else if(ai==2)
				ans^=2;
			else if(ai%2==0)
				ans^=1;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			int ai=read();
			ans^=sg(ai);
		}
	}
	if(ans>0)printf("Kevin");
	else printf("Nicky");
	return 0;
}