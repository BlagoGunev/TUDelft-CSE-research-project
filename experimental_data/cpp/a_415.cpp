#include <iostream>



using namespace std;



int main()

{

    int number,buttons;

    cin>>number>>buttons;

    int arr[number];

    for (int i=0;i<number;i++)

    {

        arr[i]=0;

    }

    for (int i=0;i<buttons;i++)

    {

        int help;

        cin>>help;

        for (int j=help-1;j<number;j++)

        {

            if (arr[j]==0)

            {

                arr[j]=help;

            }

        }

    }

    for (int i=0;i<number;i++)

    {

        cout<<arr[i]<<" ";

    }

    return 0;

}