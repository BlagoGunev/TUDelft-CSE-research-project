#include<cstdio>

#include<map>

using namespace std;

struct arr{int a,b,c,d;};

bool operator < (arr A,arr B){

	return A.a<B.a||A.a==B.a&&A.b<B.b||

	A.a==B.a&&A.b==B.b&&A.c<B.c||

	A.a==B.a&&A.b==B.b&&A.c==B.c&&A.d<B.d;

}

map<arr,bool>f;

int T,n;char s[10005];bool f1,f2,f3,f4;

int find(int a,int b,int c,int d){

	int mn=a;if (b<mn) mn=b;

	if (c<mn) mn=c;if (d<mn) mn=d;

	return mn;

}

void dfs(int a,int b,int c,int d){

	arr t=(arr){a,b,c,d};

	if (f[t]) return;f[t]=1;

	int m=a+b+c+d;

	if (m==n){int mn=find(a,b,c,d);

		if (a==mn) f1=1;if (b==mn) f2=1;

		if (c==mn) f3=1;if (d==mn) f4=1;

		return;

	}m++;

	if (s[m]=='G') dfs(a+1,b,c,d);

	if (s[m]=='H') dfs(a,b+1,c,d);

	if (s[m]=='R') dfs(a,b,c+1,d);

	if (s[m]=='S') dfs(a,b,c,d+1);

	if (s[m]=='?'){

		int mn=find(a,b,c,d);

		if (a==mn) dfs(a+1,b,c,d);

		if (b==mn) dfs(a,b+1,c,d);

		if (c==mn) dfs(a,b,c+1,d);

		if (d==mn) dfs(a,b,c,d+1); 

	}

}

int main(){

	scanf("%d%s",&n,s+1);

	f1=f2=f3=f4=0;dfs(0,0,0,0);

	if (f1) puts("Gryffindor");

	if (f2) puts("Hufflepuff");

	if (f3) puts("Ravenclaw");

	if (f4) puts("Slytherin");

}