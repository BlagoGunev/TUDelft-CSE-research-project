#include<bits/stdc++.h>

using namespace std;

int T, n, m, flag;

string s[11], ans;

int check(string tmp)

{

	int cnt;

	for(int i=1;i<=n;++i)

	{

		cnt = 0;

		for(int j=0;j<=m-1;++j)

		{

			if(s[i][j]!=tmp[j])

			{

				++cnt;

			}

		}

		if(cnt>1) return 0; 

	}

	return 1;

}

int main()

{

	ios::sync_with_stdio(0);

	cin.tie(0);

	cout.tie(0);

	char t;

	cin>>T;

	while(T--)

	{

		cin>>n>>m;

		for(int i=1;i<=n;++i)

		{

			cin>>s[i];

		}

		ans = s[1];

		flag = 0;

		for(int i=0;i<=m-1;++i)

		{

			for(int j=0;j<=25;++j)

			{

				t = ans[i];

				ans[i] = 'a'+j;

				if(check(ans))

				{

					cout<<ans<<"\n";

					flag = 1;

					break;

				}

				ans[i] = t;

			}

			if(flag)

			{

				break;

			}

		}

		if(!flag)

		{

			cout<<-1<<"\n";

		}

	}

	return 0;

}