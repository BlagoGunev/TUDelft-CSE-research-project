#include <bits/stdc++.h>

using namespace std;



int main()

{

	ios_base::sync_with_stdio(false);

	cin.tie(0);

	

	int t;

	cin>>t;

	

	while(t--)

	{

		int n,hr,mi;

		cin>>n>>hr>>mi;

		

		vector<vector<int>> v1(n);

		

		for(int i=0;i<n;i++)

		{

			int x,y,p1,p2,x1,y1;

			cin>>x>>y;

		 

		 	p1=hr*60+mi;

		 	p2=x*60+y;

		 	if(p1<=p2)

			{

				x1=(p2-p1)/60;

				y1=(p2-p1)%60;

			}

			else

			{

				x1=(24*60-p1+p2)/60;

				y1=(24*60-p1+p2)%60;

			}

			v1[i].push_back(x1);

			v1[i].push_back(y1);

		}

		

		

		sort(v1.begin(),v1.end());

		

		cout<<v1[0][0]<<" "<<v1[0][1]<<endl;

	}

}