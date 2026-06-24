#include<iostream>

#include<cstring>

#include<string>

#include<algorithm>

using namespace std;



int main()

{

	int n;

	scanf("%d", &n);

	char cross[105];

	scanf("%s", cross);

	int num = 0;

	int ans[105];

	memset(ans, 0, sizeof(ans));

	for (int i = 0; i <n; i++)

	{

		if (i == 0 && cross[i] == 'B')

		{

			num++;

			ans[num]++;

			continue;

		}

		if (cross[i] == 'B'&&cross[i - 1] == 'W')

		{

			num++;

			ans[num]++;

		}

		if (cross[i] == 'B'&&cross[i - 1] == 'B')

		{

			ans[num]++;

		}

	}

	printf("%d\n", num);

	if (num == 0)

	{

		return 0;

	}

	for (int i = 1; i <= num; i++)

		printf("%d ", ans[i]);

	printf("\n");

	return 0;

}