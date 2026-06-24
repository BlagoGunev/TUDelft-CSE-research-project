#include <bits/stdc++.h>



using namespace std;

int main() {

    #define int long long int

    int t;

    cin>>t;

    // int y=0;

    // int start=t;

    while(t--)

    {

        int n;

        string s;

        cin>>n>>s;

        // y++;

        // if(start==1000)

        // {if(y==289)

        // cout<<s<<endl;

        // continue;

        // }

        map<int,int>m;

        for(int i=0;i<n;i++)

        {

            m[s[i]-'0']++;

        }

        if(m[1]>0)

        cout<<1<<endl<<1<<endl;

        else if(m[4]>0)

        cout<<1<<endl<<4<<endl;

        else if(m[6]>0)

        cout<<1<<endl<<6<<endl;

        else if(m[8]>0)

        cout<<1<<endl<<8<<endl;

        else if(m[9]>0)

        cout<<1<<endl<<9<<endl;

        else

        {

            if(m[2]>1)

            cout<<2<<endl<<22<<endl;

            else if(m[3]>1)

            cout<<2<<endl<<33<<endl;

            else if(m[5]>1)

            cout<<2<<endl<<55<<endl;

            else if(m[7]>1)

            cout<<2<<endl<<77<<endl;

            else 

            {

                int i=n-1;

                for(;i>=0;i--)

                {

                    if(s[i]=='2'||s[i]=='5')

                    break;

                }

                if(i>0)

                cout<<2<<endl<<s[0]<<s[i]<<endl;

                else if(s[n-1]=='7'&&m[2]>0||s=="273")

                cout<<2<<endl<<27<<endl;

                else if(s[n-1]=='7'||s=="573")

                cout<<2<<endl<<57<<endl;

            }

        }

    }

}