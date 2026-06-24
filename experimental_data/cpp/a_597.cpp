#include <iostream>

#include <cmath>



using namespace std;



int main()

{

    long long num1,num2,num3;

    cin>>num1>>num2>>num3;

    long long ans=num3/num1;

    if (num2<=0 && num3>=0)

    {

        ans+=abs(num2/num1);

        ans++;

    }

    else if (num2<=0 && num3<=0)

    {

        ans=abs(max(num2,num3)/num1)-abs(min(num2,num3)/num1);

        ans=abs(ans);

        if (max(num2,num3)%num1==0)

        {

            ans++;

        }

    }

    else

    {

        ans-=abs(num2/num1);

        if (num2%num1==0)

        {

            ans++;

        }

    }

    cout<<abs(ans);

    return 0;

}