#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<queue>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<map>
#include<stack>
using namespace std;
const int N=100000+5;
void getint(int&num){
    char c;int flag=1;num=0;
    while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;
    while(c>='0'&&c<='9'){num=num*10+c-48;c=getchar();}
    num*=flag;
}
int T,n,a[N];
int main(){
	getint(T);
	while(T--){
		getint(n);
		for(int i=1;i<=n;i++)
			getint(a[i]);
		sort(a+1,a+n+1);
		int cnt=unique(a+1,a+n+1)-a-1;
		printf("%d\n",cnt);
	}
}
/*

*/