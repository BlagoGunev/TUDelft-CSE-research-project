//============================================================================
// Name        : 0.cpp
// Author      : ss
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
char a[200][200];
bool x[205];
int main() {
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i = 0; i < d; i ++)
	{
		scanf("%s",&a[i]);
		for(int j = 0; j < n; j ++)
		{
			if(a[i][j] == '0')
			{
				x[i] = true;
				break;
			}
		}
	}
	int maxn =0,temp = 0;
	for(int i = 0; i < d; i ++)
	{
		if(x[i] == true)
		{
			temp ++;
			maxn = max(temp,maxn);
		}
		else
		{
			temp = 0;
		}
	}
	printf("%d\n",maxn);
	return 0;
}