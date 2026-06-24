#include <bits/stdc++.h>

#define PI acos(-1)

#define MX 51

#define LL long long

using namespace std;



int main()

{



  //  freopen("input.txt","r",stdin);

   //  freopen("output.txt","w",stdout);



  int n,i=1;

  scanf("%d",&n);

  if(n==1)

  {

      printf("YES\n");

            return 0;

  }

  int temp=1;

    while(temp<=n)

    {

         temp=i*(i+1)/2;

        if(temp==n)

        {

            printf("YES\n");

            return 0;

        }

        i++;

    }

    printf("NO\n");



    return 0;

}