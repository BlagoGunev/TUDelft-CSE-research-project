#include <cstdio>

#include <vector>



int n;

std::vector<int> data[233];



int main(void)

{

	int i,j,k;

	int x;

	

	scanf("%d",&n);

	

	k = 2;

	while(1ll * k * (k - 1) / 2 <= n)

		++k;

	--k;

	

	x = 1;

	for(i = 1;i <= k;++i)

		for(j = i + 1;j <= k;++j)

			data[i].push_back(x),data[j].push_back(x),++x;

	

	printf("%d\n",k);

	for(i = 1;i <= k;++i)

	{

		for(j = 0;j < data[i].size();++j)

		{

			printf("%d ",data[i][j]);

		}

		puts("");

	}

	

	return 0;

}