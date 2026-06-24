#include <bits/stdc++.h>

#define ll long long int

using namespace std;



int main()

{

    ll i,j,k,m,n, len;

    string str;

    char ch;

    cin >> str;

    len= str.size();

     for(i=1; i<len; i++)

    {

        if(str[i] >='a' && str[i] <='z'){

                cout << str << endl;

        return 0;

        }

    }

    for(i=0; i<len; i++)

    {

        str[i] ^= 32;

    }

    cout << str << endl;

}