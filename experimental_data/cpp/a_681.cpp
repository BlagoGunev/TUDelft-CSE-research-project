#include <bits/stdc++.h>

using namespace std;

int main()

{

    int n;

    cin>>n;

    int b,c;

    string s;

    for(int i=0;i<n;i++)

    {

        cin>>s>>b>>c;

        if(b>=2400&&c>b)

        {

            cout<<"YES";

            return 0;

        }

    }

    cout<<"NO";

    return 0;

}