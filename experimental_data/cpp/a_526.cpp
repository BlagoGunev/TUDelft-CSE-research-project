// IN THE NAME OF GOD



#include <iostream>



#include <vector>



using namespace std;



vector <int> v;



int a[101]={0};



int search_for(int x)

{

    int index;

    index=-1;

    for(int i=0;i<v.size();i++)

    {

        if(v[i]==x)

        {

            index=i;

            break;

        }

    }

    return index;

}

int main()

{

    int n;

    cin>>n;

    char c;

    for(int i=1;i<=n;i++)

    {

        cin>>c;

        if(c=='*')

        {

            v.push_back(i);

        }

    }

    for(int i=1;i<=24;i++)

    {

        int counter;

        counter=0;

        for(int k=1;k<=100;k++)

        {

            a[k]=0;

        }

        for(int j=0;j<v.size();)

        {

            a[j]=1;

            if(search_for(v[j]+i)!=-1)

            {

                counter++;

                j=search_for(v[j]+i);

            }

            else

            {

                if(counter>=4)

                {

                    cout<<"yes";

                    return 0;

                }

                else

                {

                    counter=0;

                    for(int k=1;k<=100;k++)

                    {

                        if(a[k]==0)

                        {

                            j=k;

                            break;

                        }

                    }

                }

            }

        }

        if(counter>=4)

        {

            cout<<"yes";

            return 0;

        }

    }

    cout<<"no";

    return 0;

}