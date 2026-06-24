#include<stdio.h>

#include<cstring>

#include<algorithm>

#define HardBoy main()

#define ForMyLove return 0;

using namespace std;

const int MYDD = 1103;



int HardBoy {

	int k, Map[128][128];

	scanf("%d", &k);

	

	int n = 1;

	while((n+1)*(n+2)*(n+3)/6 <= k) n++;

	for (int i = 0; i < n+2; i++)	{

		for (int j = 0;  j < n+2; j++) {

			Map[i][j] = 1;

		}

		Map[i][i] = 0;

	}



	int node = n + 2, l = (n+1)*(n+2)*n/6;

	if (l < k) {

		while (l < k) {

			Map[0][node] = 1;

			Map[node][0] = 1;

			int j = 1;

			int t = 1;

			while (l+t <= k) {

				Map[t][node] = 1;

				Map[node][t] = 1;

				l += t;

				t++;

			}

			if (l < k)

				node++;

		}

		node++;

	}

	

	printf("%d\n", node);

	for(int j = 0; j < node; j++) {

		for(int k = 0; k < node; k++) {

			printf("%d", Map[j][k]);

		}

		printf("\n");

	}

	ForMyLove

}