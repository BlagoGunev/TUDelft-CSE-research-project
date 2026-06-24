#include <bits/stdc++.h>

using namespace std;



int main()

{

	int n;

	scanf("%d",&n);

	printf("1");

	for (int i = 2; i <= n ; i++) printf(" %d",(i&1 ? i/2+1 : n-i/2+1));

}