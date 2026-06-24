#include <bits/stdc++.h>

using namespace std;



int main() {

    int t;

    cin>> t;

    while(t--)

    {

        int a, b, c;

        cin>> a >> b >> c;

        string ans;

        string k;

        int j = 0;

        for(int i = 0; i < a; i++)

        {

            if(j % c == 0)

            {

                j = 0;

            }

            char c = char('a' + j);

            k.push_back(c);

            j++;

        }

        cout<< k << endl;

    }

    return 0;

}