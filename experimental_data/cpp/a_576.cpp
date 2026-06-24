#include<bits/stdc++.h>

using namespace std;



main()

{

	



	int n;

	

    scanf("%d",&n);

	

	bool a[n+1];

	int m = 0;

	

	memset(a,0,sizeof(a));



	

	for(int i =2;i <= n;i++)

	{

	

	    if(!a[i])

		{

		     bool flag = 0;   

			 for(int j = 2;j*j <= i;j++)

			 {

			 

			      if(i%j == 0)

			      {

			      	

			      	flag = 1;

			      	break;

			      	

				  }

			   	flag = 0;

			}	

			

			if(!flag)

			{



				for(int k = i;k <= n;k *= i)

			      	   a[k] = 1,m++;

//			    m++;

			}

		}	

		

	}	

	

	printf("%d\n",m);

	

	for(int i = 2;i <= n;i++)

	{

		

		if(a[i])

		  printf("%d ",i);

		

	}

}