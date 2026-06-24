#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
int getint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-')f=-1; ch=getchar();	}
	while('0'<=ch&&ch<='9') { x=x*10+ch-'0'; ch=getchar();	}
	return f*x;
}
#define N 212345
int gcd(int x,int y){
	if(y==0) return x;
	else return gcd(y,x%y);
}
int a[N];
int main(){
	int n=getint();
	for(int i=1;i<=n;i++) a[i]=getint();
	int d=a[1];
	for(int i=2;i<=n;i++) d=gcd(d,a[i]);
	if(d>1) {
		printf("YES\n0\n"); return 0;	
	}
	int ans=0;
	for(int i=1;i<=n;) {
		if(a[i]%2==0) i++;
		else if((a[i]&1)&&(i+1<=n)&&(a[i+1]&1)) ans++,i+=2;
		else ans+=2,i+=2;
	}
		printf("YES\n%d\n",ans); return 0;
}