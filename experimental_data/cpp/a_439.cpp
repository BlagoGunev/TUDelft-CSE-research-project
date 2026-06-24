#include <iostream>



using namespace std;



int main()

{

    long long number,timeh,sum=0;

    cin>>number>>timeh;

    int arr[number];

    for (int i=0;i<number;i++)

    {

        cin>>arr[i];

        sum+=arr[i];

    }

    if (((number-1)*10)+sum>timeh)

    {

        cout<<-1;

        return 0;

    }

    timeh-=sum;

    cout<<timeh/5;

    return 0;

}