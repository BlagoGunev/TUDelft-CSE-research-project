#include<bits/stdc++.h>

using namespace std;

char a[10][10];

int main()

{

	for(int i=1;i<=4;i++)

	{

		for(int j=1;j<=4;j++)

		{

			cin>>a[i][j];

		}

	}

	for(int i=1;i<=3;i++)

	{

		for(int j=1;j<=3;j++)

		{

			int check=0;

			if(a[i][j]==a[i][j+1])

			{

				check++;

			}

			if(a[i][j]==a[i+1][j])

			{

				check++;

			}

			if(a[i][j]==a[i+1][j+1])

			{

				check++;

			}

			if(check>=2)

			{

				cout<<"YES";

				return 0;

			}

		}

	}

	

	

	for(int i=4;i>=2;i--)

	{

		for(int j=4;j>=2;j--)

		{

			int check=0;

			if(a[i][j]==a[i][j-1])

			{

				check++;

			}

			if(a[i][j]==a[i-1][j])

			{

				check++;

			}

			if(a[i][j]==a[i-1][j-1])

			{

				check++;

			}

			if(check>=2)

			{

				cout<<"YES";

				return 0;

			}

		}

	}

	

	cout<<"NO";

}