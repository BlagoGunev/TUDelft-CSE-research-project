#include <bits/stdc++.h>

using u32 = uint32_t;
using u64 = uint64_t;
using i32 = int32_t;
using i64 = int64_t;

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	u32 q;

	std::cin >> q;

	while(q--)
	{
		u32 n;
		std::cin >> n;

		std::vector<u32> v;
		v.reserve(n);

		for(u32 i=0; i<n; i++)
		{
			u32 x;
			std::cin >> x;
			v.push_back(x);
		}

		std::sort(v.begin(), v.end(), std::greater<u32>());

		u32 max = 1;

		for(u32 i=1; i<=n; i++)
		{
			if(v[i-1]>=i)
			{
				max = i;
			}
		}
		std::cout << max << "\n";
	}

	
	return 0;
}