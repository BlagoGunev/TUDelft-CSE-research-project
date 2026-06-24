#include <bits/stdc++.h>

using namespace std;



void solve()

{

    string s;

    cin>>s;

    int suma=0,sumb=0;

    for(int i=0;i<s.size();i++)

    {

        if(s[i]=='a')

        {

            if(sumb==1)

            {

                cout<<"NO"<<endl;

                return;

            }

            sumb=0;

            suma++;

        }

        else

        {

            if(suma==1)

            {

                cout<<"NO"<<endl;

                return;

            }

            suma=0;

            sumb++;

        }

    }

    if(suma==1 || sumb==1)

    {

        cout<<"NO"<<endl;

        return;

    }

    cout<<"YES"<<endl;

    return;

}

int main()

{

    int s;

    cin>>s;

    while(s--)

    solve();

    return 0;

}