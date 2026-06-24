#include<bits/stdc++.h>

using namespace std;

int main()

{

    int  t; cin>>t;

    while(t--)

    {

        int n; cin>>n;



        if(n%2==0)

        {

            int j=2,k=1;

            for(int i=0;i<n;i++){

                if(i%2==0){

                    cout<<j<<" ";

                    j+=2;

                }

                else {

                    cout<<k<<" ";

                    k+=2;

                }

            } cout<<endl;

        } //cout<<endl;

        else if(n%2!=0)

        {

            int k=3,j=2;

            cout<<1<<" ";

            for(int i=1;i<n;i++)

            {

                if(i%2==0)

                {

                    cout<<j<<" ";

                    j+=2;

                }

                else

                {

                    cout<<k<<" ";

                    k+=2;

                }

            } cout<<endl;

        }



    }

}