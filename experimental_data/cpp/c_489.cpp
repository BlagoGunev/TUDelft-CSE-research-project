#include<bits/stdc++.h>

using namespace std;

//nksheokand

int main()

{

	int m,s,st;

	string sm,la;

	scanf("%d%d",&m,&s);

	if(m==1)

	{

		if(s<10)

		{

			printf("%d %d",s,s);

		}

		else

		{

			printf("-1 -1");

		}

	}

	else if(s==0)

	{

		printf("-1 -1");

	}

	else if(s>m*9)

	{

		printf("-1 -1");

	}

	else

	{

		sm="";

		la="";

		st=s;

		if(s<=9*(m-1)+1)

		{

			sm+='1';

			s--;

		}

		else

		{

			sm+='0'+(s-9*(m-1));

			s=9*(m-1);

		}

		for(int i=1;i<m;i++)

		{

			if(s>9*(m-i-1))

			{

				sm+='0'+(s-9*(m-i-1));

				s=(9*(m-i-1));

			}

			else

			sm+='0';

		}

		for(int i=0;i<m;i++)

		{

			if(st>=9)

			{

				la+='9';

				st-=9;

			}

			else

			{

				la+='0'+st;

				st=0;

			}

		}

		cout<<sm<<" "<<la;

	}

	return 0;

}