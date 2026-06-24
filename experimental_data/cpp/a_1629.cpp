#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tt;
	std::cin >> tt;
	while(tt--)
	{
		int n,k;
		std::cin >> n >> k;
		std::vector<std::pair<int,int>> mem;
		std::vector<int> a(n);
		int b;
		for(int i=0;i<n;i++)
			std::cin >> a[i];//Consuming Memory
		for(int i=0;i<n;i++)
		{
			std::cin >> b;
			mem.push_back(std::make_pair(a[i],b));
		}
		std::sort(mem.begin(),mem.end());
		for(int i=0;i<n;i++)
		{
			if(k >= mem[i].first)
				k += mem[i].second;
		}
		std::cout << k << '\n';
	}
	return 0;
}