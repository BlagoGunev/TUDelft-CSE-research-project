#include<iostream>

using namespace std;

int  main()

{

    int n;

    cin>>n;

    char all, b;

    for(int i=0; i<n; i++)

    {

        for(int ii=0; ii<n; ii++)

        {

            char z;

            cin>>z;

            if(i==0 && ii ==0)

            {

                b=z;

            }

            else

            {

            if(i==0 && ii==1)

            {

                all=z;

            }

            else

            {

                if(i==ii || i==(n-ii - 1))

                {

                    if(z!=b)

                    {

                        cout<<"NO";

                        return 0;

                    }

                }

                else

                {

                    if(all!=z)

                    {

                        cout<<"NO";

                        return 0;

                    }

                }

            

            }

            }

        }

    }

    if(all != b)

    {

    cout<<"YES";

    }

    else

    {

        cout<<"NO";

    }

}