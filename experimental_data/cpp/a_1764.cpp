#include<bits/stdc++.h>

using namespace std;

int T,n;

inline int gint() {

	char ch=getchar();int s=0,f=1;

	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}

	while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}

	return s*f;

}

int main() {

	T=gint();

	while(T--) {

		n=gint();

		for(int i=1,x;i<=n;i++) x=gint();

		printf("%d %d\n",1,n);

	}

	return 0;

}