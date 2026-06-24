#include <cstdio>
#include <cassert>
#include <algorithm>
#include <tuple>
#include <vector>
#include <numeric>

template<typename T> bool ckmax(T &a, T const& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T &a, T const& b) {return b<a?a=b,1:0;}

using ll = long long;

int const MM = 2e5 + 10;
int revmap[MM];

int main()
{
	int T;
	scanf("%d", &T);
	for(;T--;)
	{
		int N, M;
		scanf("%d%d", &N, &M);
		std::vector<std::vector<int> > shops(N);
		std::vector<int> all;
		for(int i=0;i<N;++i)
		{
			int k;
			scanf("%d", &k);
			shops[i].resize(k);
			for(int &x: shops[i])
				scanf("%d", &x), --x, all.push_back(x);
		}
		std::sort(all.begin(), all.end());
		int M2;
		all.resize(M2 = std::distance(all.begin(), std::unique(all.begin(), all.end())));
		for(int i=0;i<M2;++i)
			revmap[all[i]] = i;
		for(auto &shop: shops)
			for(int &x: shop)
				x = revmap[x];
		
		std::vector<int> to_end(N + 1, 0);
		{
			bool idk = 0;
			std::vector<char> seen(M2, 0);
			int cnt = 0;
			for(int i=N-1;i>=0;--i)
			{
				if(shops[i].size() == 0)
					idk = 1;
				else
				{
					bool ok = 1;
					for(int x: shops[i])
						if(seen[x])
						{
							ok = 0;
							break;
						}
						else
							seen[x] = 1, ++cnt;
					if(!ok)
						break;
				}
				to_end[i] = idk ? M : cnt;
			}
		}

		std::vector<char> can_kill(N, 0);
		{
			int prev = -1;
			int bad = 0;
			std::vector<int> map(M2, 0);
			int l = 0;
			int pkill = -1, free = -1;
			for(int i=0;i<N;++i)
			{
				if(shops[i].size() == 0)
				{
					can_kill[i] = 1;
					free = pkill;
					prev = i;
				}
				else
				{
					for(int x: shops[i])
						if(++map[x] == 2)
							++ bad;
					for(;bad > 0;)
					{
						for(int x: shops[l])
							if(--map[x] == 1)
								-- bad;
						can_kill[i] |= l == 0 || can_kill[l-1];
						++l;
					}
					//assert(bad == 0);
					can_kill[i] |= l <= prev && (l == 0 || can_kill[l-1]) || l <= free;
				}
				if(can_kill[i])
					pkill = i;
			}
		}

		int ans = to_end[0];
		for(int i=0;i<N;++i)
			if(can_kill[i])
				ckmax(ans, to_end[i+1]);
		printf("%d\n", ans);
	}
	return 0;
}