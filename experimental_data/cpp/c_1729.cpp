#include <bits/stdc++.h>



using namespace std;





int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    int t;

    cin>>t;

    for(int k=0; k<t; k++)

    {

    string s;

    cin>>s;

    int n=s.length();

    char prvosl=s[0];

    char possl=s[n-1];

    map<char, vector<int>> ponavljanja;

    for(int i=0; i<n; i++)

    {

        ponavljanja[s[i]].push_back(i+1);

    }

    int brojac=0;

    vector<int> ispis;

    if(prvosl<possl)

    {

        for(char i=prvosl; i<=possl; i++)

        {

            for(int j=0; j<ponavljanja[i].size(); j++)

            {

                brojac++;

                ispis.push_back(ponavljanja[i][j]);

            }

        }

    }

    else

    {

        for(char i=prvosl; i>=possl; i--)

        {

            for(int j=0; j<ponavljanja[i].size(); j++)

            {

                brojac++;

                ispis.push_back(ponavljanja[i][j]);

            }

        }

    }

    cout<<abs(prvosl-possl)<<" "<<brojac<<"\n";

    for(int i=0; i<brojac; i++)

    {

        cout<<ispis[i]<<" ";

    }

    cout<<"\n";

    }



}