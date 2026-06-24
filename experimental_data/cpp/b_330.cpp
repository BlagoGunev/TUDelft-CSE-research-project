#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

int a[1005]; 
int main()
{
	int n , m , i , j , p ,q ,ct = 0;
	memset(a,0 ,sizeof(a));
	scanf("%d%d" ,&n ,&m);
	for(i = 0 ;i < m ;i++)
	{
		scanf("%d%d" ,&p , &q);
		a[p] = a[q] = -1;
	}
	printf("%d\n" ,n-1);
	for(j = 1; j <= n ;j++)
	{
		if(a[j] == 0)
		{
			q = j;
			break;
		}
	}
	for(i = 1; i <= n; i++)
	{
		if(i != q)
		{
			printf("%d %d\n" ,q ,i);
		}
	}
	return 0;
}