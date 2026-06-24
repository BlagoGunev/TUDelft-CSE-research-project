#include <iostream>

#include <algorithm>



using namespace std;



struct legs

{

    int len;

    int index;

};



int main()

{

    int number=6;

    int arr[number],headbody[2]={0,0};

    bool check[2]={false,false};

    legs leg[4];

    for (int i=0;i<4;i++)

    {

        leg[i].index=-1;

        leg[i].len=-1;

    }

    for (int i=0;i<number;i++)

    {

        cin>>arr[i];

    }

    sort(arr,arr+number);

    int counter=0;

    for (int i=0;i<number;i++)

    {

        int g=0;

        for (int j=0;j<number;j++)

        {

            if (arr[i]==arr[j] && i!=j)

            {

                g++;

            }

        }

        if (g>=3)

        {

            leg[counter].len=arr[i];

            leg[counter].index=i;

            counter++;

            if (counter>=4)

            {

                check[0]=true;

                i=7;

            }

        }

    }

    counter=0;

    for (int i=0;i<number;i++)

    {

        int g=0;

        for (int j=0;j<4;j++)

        {

            if (leg[j].index==i)

            {

                g++;

            }

        }

        if (g==0)

        {

            headbody[counter]=arr[i];

            counter++;

            if (counter==2)

            {

                check[1]=true;

                i=7;

            }

        }

    }

    if (check[0] and check[1])

    {

        if (headbody[0]!=headbody[1])

        {

            cout<<"Bear";

        }

        else

        {

            cout<<"Elephant";

        }

    }

    else

    {

        cout<<"Alien";

    }

    return 0;

}