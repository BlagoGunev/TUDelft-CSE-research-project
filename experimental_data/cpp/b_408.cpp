#include <bits/stdc++.h>

int FBlock[1000];

int SBlock[1000];

using namespace std;



int main()

{

    string s;

    cin >> s;

    for(int i = 0;i < s.length();i++)

        FBlock[s[i]]++;



    cin >> s;

    for(int i = 0;i < s.length();i++)

        SBlock[s[i]]++;



    int Size = 0;

    for(int i = 0;i < 1000;i++)

    {

        Size += min(FBlock[i],SBlock[i]);

        if(SBlock[i] > 0 && FBlock[i] == 0)

        {

            cout << "-1";

            return 0;

        }

    }

        cout << Size;

    return 0;

}