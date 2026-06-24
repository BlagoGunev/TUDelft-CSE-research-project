#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int a[300000];
char str[300000];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%s",str);
	int n = strlen(str);
	for(int i = 1; i < n; i++)
	{
		if (str[i-1] == str[i])
			a[i-1] = 1;
		else
			a[i-1] = 0;
	}

	a[n-1] = 0;

	for(int i = n-2; i >= 0; i--)
		a[i] += a[i+1];

	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int l, r;
		scanf("%d %d",&l,&r);
		printf("%d\n",a[l-1]-a[r-1]);
	}

}