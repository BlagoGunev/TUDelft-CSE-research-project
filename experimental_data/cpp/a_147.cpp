#include <iostream>



using namespace std;



int main()

{

    char ch;

    string str;

    int j=0;

    int comma_counter=0;

    while (cin>>str)

    {

        if (str[0]!=',' && str[0]!='?' && str[0]!='!' && str[0]!='.' && j!=0)

        {

            cout<<" ";

        }

        for (int i=0;i<str.size();i++)

        {

            cout<<str[i];

            if ((str[i]==',' || str[i]=='?' || str[i]=='!' || str[i]=='.') && i!=str.size()-1)

            {

                cout<<" ";

            }

        }

        j++;

    }

    return 0;

}