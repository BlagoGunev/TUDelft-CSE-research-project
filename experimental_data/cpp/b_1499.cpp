#include<bits/stdc++.h>

#define int long long

using namespace std;



void solve()

{

    string s;

    cin>>s;

    int check=0;

    for (int i=0;i<s.length()-1;i++)

    {

        if (check==0)

        {

            if (s[i]=='1' && s[i+1]=='1') check=1;

        }

        else

        {

            if (s[i]=='0' && s[i+1]=='0')

            {

                cout<<"NO"<<endl;

                return;

            }

        }

    }

    cout<<"YES"<<endl;

}



int32_t main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int T;

    cin>>T;

    while(T--)

    {

        solve();

    }

    return 0;

}