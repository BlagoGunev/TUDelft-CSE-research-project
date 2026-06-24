#include <cstdio>

using namespace std;



int main()

{

	int n;

	scanf("%d",&n);

	if (n < 4)

	{

		puts("NO");

		return 0;

	}

	else puts("YES");

	if (n%2) puts("5 - 1 = 4\n4 - 2 = 2");

	else puts("1 * 2 = 2");

	puts("4 * 3 = 12\n12 * 2 = 24");

	while (--n > 4)

		printf("%d - %d = 1\n24 * 1 = 24\n",n+2,n--);

}