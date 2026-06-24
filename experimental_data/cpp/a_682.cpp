#include <iostream>



using namespace std;



int main()

{

    long long num1,num2,ans=0,counter[5][2]={{0},{0}};

    cin>>num1>>num2;

    for (int i=1;i<=num1;i++)

    {

        counter[i%5][0]++;

    }

    for (int i=1;i<=num2;i++)

    {

        counter[i%5][1]++;

    }

    ans=(counter[0][0]*counter[0][1])+((counter[1][0]*counter[4][1])+(counter[2][0]*counter[3][1]))+((counter[4][0]*counter[1][1])+(counter[3][0]*counter[2][1]));

    cout<<ans;

    return 0;

}