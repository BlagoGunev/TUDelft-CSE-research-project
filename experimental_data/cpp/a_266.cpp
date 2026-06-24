#include <bits/stdc++.h>

using namespace std;

#include<cstdio>
#include<cstring>
main()
{
	int N;
	char s[55];	
	scanf("%d",&N);
	getchar();
	fgets(s, sizeof(s), stdin);
	int ans=1;
	for (int i=0;i<N-1;i++)
		if (s[i]!=s[i+1])
			ans++;
	printf("%d\n",N-ans);
}