#include<map>

#include<new>

#include<set>

#include<cmath>

#include<queue>

#include<stack>

#include<ctime>

#include<cstdio>

#include<memory>

#include<vector>

#include<bitset>

#include<cstdlib>

#include<cstring>

#include<utility>

#include<iostream>

#include<algorithm>

using namespace std;



int n;

int x,a,b,c;

vector<pair<int,string> > team;

vector<pair<int,string> > cla[5];

vector<pair<int,string> > group[55];



int rnd()

{

	x=(x*a+b)%c;

	return x;

}



int main()

{

	freopen("input.txt","r",stdin);

	freopen("output.txt","w",stdout);

	cin>>n;

	cin>>x>>a>>b>>c;

	int t1;

	string t2;

	for(int i=0;i<n;i++)

	{

		cin>>t2>>t1;

		team.push_back(make_pair(t1,t2));

	}

	sort(team.rbegin(),team.rend());

	for(int i=0;i<4;i++)

	{

		for(int j=0;j<n/4;j++)

		{

			cla[i].push_back(team[i*(n/4)+j]);

		}

	}

	for(int i=0;i<n/4;i++)

	{

		cout<<"Group "<<(char)('A'+i)<<":"<<endl;

		for(int j=0;j<4;j++)

		{

			int temp=rnd()%cla[j].size();

			cout<<cla[j][temp].second<<endl;

			cla[j].erase(cla[j].begin()+temp);

		}

	}

	return 0;

}