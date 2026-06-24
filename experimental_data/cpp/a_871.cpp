#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <assert.h>

using namespace std;

inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}

inline void rea(int &x){
	char c=nc(); x=0;
	for(;c>'9'||c<'0';c=nc());for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc());
}

int n,t;

int main(){
	rea(t);
	while(t--){
		rea(n);
		int rest=n%4,divr=n/4;
		if(rest==0) printf("%d\n",divr);
		else if(rest==1){
			if(divr>=2) printf("%d\n",divr-1);
			else puts("-1");
		}
		else if(rest==2){
			if(divr>=1) printf("%d\n",divr);
			else puts("-1");
		}
		else{
			if(divr>=3) printf("%d\n",divr-1);
			else puts("-1");
		}
	}
	return 0;
}