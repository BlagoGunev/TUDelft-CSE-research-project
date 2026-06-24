#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
const int inf = 1 << 30;
const LL INF = 1LL << 60;

int n;

int main() 
{
	while(scanf("%d", &n) != EOF)
	{
		if(n & 1) {			//n is odd
			int tmp = (n - 1) >> 1;
			//int mid = (n + 1) >> 1;
			if(tmp & 1) {	
				printf("0\n%d", (tmp >> 1) * 2 + 2);
				for(int i = 2; i <= tmp; i += 2)
					printf(" %d %d", i, (n + 2 - i));
				printf(" 1 %d\n", (n + 1) >> 1);
			}
			else {
				printf("1\n%d", tmp);
				for(int i = 2; i <= tmp; i += 2)
					printf(" %d %d", i, (n + 2 - i));
				printf("\n");
			}
		}
		else {				//n is even
			int tmp = n >> 1;
			if(tmp & 1) {		//half odd
				printf("1\n%d", (tmp >> 1) * 2 + 1);
				for(int i = 1; i < tmp; i += 2)
					printf(" %d %d", i, (n - i + 1));
				printf(" %d\n", tmp);
			}
			else {				//half even
				printf("0\n%d", (tmp >> 1) * 2);
				for(int i = 1; i <= tmp; i += 2)
					printf(" %d %d", i, (n - i + 1));
				printf("\n");
			}
		}
	}
	return 0;
}