#include<iostream>

#include<cstdio>



using namespace std;



int main()

{

    int n,sum;



    while(scanf("%d",&n)==1)

    {

        sum=0;



        for(int i=1; i<=n; i++)

        {

            sum+=(i*(i+1))/2;



            if(sum==n)

            {

                printf("%d\n",i);

                break;

            }



            else if(sum>n)

            {

                printf("%d\n",i-1);

                break;

            }

        }

    }



    return (0);

}