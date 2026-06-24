#include <bits/stdc++.h>

using namespace std;

int n;

bool notprime[1234];

vector<int>v;

int main()

{

	cin>>n;

	if(n==1)

	{

		puts("0");

		return 0;

	}

	for(int i=2;i*i<=n;i++)

		if(!notprime[i])

			for(int j=i+i;j<=n;j+=i)

				notprime[j]=true;

	for(int i=2;i<=n;i++)

		if(!notprime[i])

			for(int j=i;j<=n;j*=i)

				v.push_back(j);

	sort(v.begin(),v.end());

	v.resize(unique(v.begin(),v.end())-v.begin());

	random_shuffle(v.begin(),v.end());

	cout<<v.size()<<endl;

	for(int i=0;i<v.size()-1;i++)

		cout<<v[i]<<" ";

	cout<<v[v.size()-1];

}