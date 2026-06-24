#include<iostream>

#include<stdio.h>

#include<math.h>

#include<string>

#include<set>

#include<string.h>

#include<algorithm>

#include<vector>

#include<map>

using namespace std;



vector<int> wan(100);

void solve1()

{

	for(int i = 1; i <= 100; i++)

	{

		wan[i] = (1 + i) * i / 2;

	}

}

void solve()

{

    int m,s;

    cin>>m>>s;

    int sum = s;

    vector<int> ff(100);

    vector<bool> vis(100);

    for(int i = 1; i <= m; i++)

    {

    	cin>>ff[i];

    	sum += ff[i];

    	vis[ff[i]] = 1;

	}

	for(int i = 1; i <= 100; i++)

	{

		if(sum == wan[i]) 

		{

			for(int j = 1; j <= m; j++)

			{

				sum -= ff[j];

			}

			for(int j = 1; j <= i; j++)

			{

				if(!vis[j])

				{

					sum -= j;

				}

			}

			if(sum == 0) cout<<"YES"<<endl;

			else cout<<"NO"<<endl;

			return ;

		}

	}

	cout<<"NO"<<endl;

}

int main() 

{

	std::ios::sync_with_stdio(false);

	int t;

	cin>>t;

	solve1();

	while(t--)

	{

		solve();

	}

}