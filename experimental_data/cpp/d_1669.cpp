#include <bits/stdc++.h>

#include <vector>

#define endl '\n'

#define AC return 0;

using namespace std;



void slove()

{

    int n;

    cin >> n;

    string s;

    cin >> s;

    s = 'W' + s;

    s += 'W';



    int l = 0;

    vector<string>v;

    string now = "";

    for(int i = 0; i < n + 2; i++)

    {

        if(s[i] == 'W')

        {

            if(now.length() > 0)

                v.push_back(now);

            now = "";

        }

        else

        {

            now += s[i];

        }

    }



    for(auto t : v)

    {

        bool fl1 = true;

        bool fl2 = true;

        for(auto i : t)

        {

            if(i == 'R')

                fl1 = false;

            if(i == 'B')

                fl2 = false;

        }

        if(fl1 || fl2)

        {

            cout << "NO" << endl;

            return;

        }

    }    

    

    cout << "YES" << endl;

}



signed main()

{

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int T;cin >> T; while(T--)

    slove();

    AC

}