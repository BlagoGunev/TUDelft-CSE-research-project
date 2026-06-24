#include<bits/stdc++.h>
using namespace std;
int read() {
	int temp=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		temp=(temp<<1)+(temp<<3)+(ch^48);
		ch=getchar();
	}
	return temp*f;
}
void write(int temp) {
	if(temp>9) write(temp/10);
	putchar(temp%10|48);
}
void work() {
	int n=read(),ans=0;
	for(int i=1,x; i<=n; ++i) {
		x=read();
		if(x==3||x==1) ++ans;
	}
	write(ans),putchar('\n');
}
int main() {
	int t=read();
	while(t--) work();
	return 0;
}