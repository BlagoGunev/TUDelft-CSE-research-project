#include<bits/stdc++.h>

using namespace std;

int main()

{

    int n,temp,c2=0,c1=0;

    cin>>n;

    while(n--)

    {

        scanf("%d",&temp);

        if(temp==100)

            c1++;

        else

            c2++;

    }

    if(c1%2==1)

    {

           cout<<"NO";

    }

    else

    {

           if(c2%2==0)

              cout<<"YES";

           else if(c1 >= 2)

              cout<<"YES";

           else

              cout<<"NO";

    }

    return 0;





}