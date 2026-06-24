#include <bits/stdc++.h>



using namespace std;

int main()

{

	int n,m,k;

	cin>>n>>m>>k;

	vector<int> v(m);

	vector<int> sum(m,-1);



	for(int i=0;i<m;i++)

	{

		cin>>v[i];

	}

	

	int MIN = n;

	for(int i=0;i<k;i++)

	{

		int temp;

		cin>>temp;

		for(int j=0; j<m;j++)

		{

			if(temp % v[j] == 0)

			{

				if(sum[j] == -1)

					sum[j] ++;

				sum[j] ++;

			}

		}

	}



	for(int i=0;i<m;i++)

	{

		if(sum[i] < MIN)

			MIN = sum[i];

	}

	int c = 0;

	std::vector<int> res;

	for(int i=0;i<m;i++)

	{

		if(sum[i] == MIN)

		{

			c++;

			res.push_back(i + 1);

		}

	}

	cout<<c<<endl;

	for(int i=0;i<res.size();i++)

	{

		cout<<res[i]<<" ";

	}

	return 0;

}