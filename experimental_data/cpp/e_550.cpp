#include<bits/stdc++.h> 

using namespace std;



const int maxn = 1e5 + 10;

int n;

int a[maxn];



int main(){

	scanf("%d", &n);

	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

	if(a[n]){

		puts("NO"); return 0;

	}

	if(n == 1){

		puts("YES"); puts("0"); return 0;

	}

	if(a[n-1]){

		puts("YES");

		for(int i = 1; i <= n; i++) printf("%d%s", a[i], i == n ? "\n" : "->");

		return 0;

	}

	if(n == 2){

		puts("NO"); return 0;

	}

	int pos = -1;

	for(int i = n - 2; i >= 1; i--) if(!a[i]){

		pos = i; break;

	}

	if(pos < 0){

		puts("NO"); return 0;

	}

	puts("YES");

	for(int i = 1; i < pos; i++) printf("%d->", a[i]);

	for(int i = pos; i <= n - 2; i++) printf("(%d->", a[i]);

	printf("%d", a[n-1]);

	for(int i = pos; i <= n -2; i++) printf(")");

	printf("->%d", a[n]);

	return 0;

}



/*

题意：

*/