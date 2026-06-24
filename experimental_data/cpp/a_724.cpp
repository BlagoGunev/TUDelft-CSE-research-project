#include <bits/stdc++.h>

using namespace std;



int main()

{

    int a = 0, b = 0, c;

    const string dayname[7] = {"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};

    string s1, s2;

    cin >> s1 >> s2;

    for(int i=0; i<7; i++)

    {

        if(dayname[i] == s1)

        {

            a = i;

        }



        if(dayname[i]==s2)

        {

            b = i;

        }



    }

    if((a+0)%7==b || (a+2)%7==b || (a+3)%7==b ) cout << "YES" <<endl;

    else cout << "NO" << endl;

    return 0;

    //cout << a <<" " << b << endl;;

}