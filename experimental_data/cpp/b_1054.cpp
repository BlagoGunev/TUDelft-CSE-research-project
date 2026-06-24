#include <bits/stdc++.h>

int read() {
	static int x,c;
	int flag=1;
	while (c=getchar(),!isdigit(c)) if (c=='-') flag=-1;
	x=c-'0';
	while (c=getchar(),isdigit(c))
		x=(x<<1)+(x<<3)+c-'0';
	return x*flag;
}

int n,ns[100100];

int main() {
	n=read();
	int max=-1;
	for (int i=1; i<=n; ++i) {
		ns[i]=read();
		if (ns[i]==max+1)
			max=ns[i];
		else if (ns[i]>max) {
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
}