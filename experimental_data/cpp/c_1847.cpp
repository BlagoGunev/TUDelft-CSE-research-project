#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define debug(x...)
#else
#include "../debug.hpp"
#endif
#define ll long long
#define in(A,N); int A[N]; for(int z=0;z<N;z++){cin>>A[z];}
#define pt(A,N); for(int z=0;z<N;z++){cout<<A[z]<<" ";} cout<<endl;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int ll
using namespace std;
signed main()
{	fio;
	int t = 1;
	cin >> t;
	while (t--)
	{	int N;
		cin >> N;
		in(A, N);

		int pz = 0;
		vector<bool>dp(257, false);
		dp[0] = true;
		int ma = 0;
		for (auto it : A)
		{
			pz = pz ^ it;
			dp[pz] = true;
			for (int i = 0; i < 257; i++)
			{
				if (dp[i] && ma < (i ^ pz))
				{
					ma=(i ^ pz);
				}
			}
		}
		cout<<ma<<endl;
		
	}

	return 0;
}