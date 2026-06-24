#include <iostream>

#include <cmath>



using namespace std;



int main()

{

    long long x1,y1,x2,y2;

    cin>>x1>>y1>>x2>>y2;

    long long ans;

    if ((y1%2==0 && y2%2==0) || (y1%2!=0 && y2%2!=0))

    {

        ans=(long long)((((abs(y2-y1)/2)+1)*(abs(x2-x1)+1)))-(abs(x1-x2)/2);

    }

    else

    {

        ans=(long long)((abs(y2-y1)/2)+1)*(abs(x2-x1));

    }

    cout<<ans;

    return 0;

}