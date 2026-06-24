#include<cstdio>
#include<map>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include <stdio.h> 
#include <math.h>
using namespace std;
int main()
{
    int n;
    while(cin >> n)
    {
        int C = 0;
        string iString, uString;
        for (int f = 0; f < n; f++)
        {
            if(iString.size() == 0 || iString[iString.size()-1] == '.')
                iString += 'C';
            else
                iString += '.';

            if(uString.size() == 0 || uString[uString.size()-1] == 'C')
                uString += '.';
            else
                uString += 'C';
        }
        C = ceil(n/2.0)*ceil(n/2.0)+floor(n/2.0)*floor(n/2.0);
        cout << C << endl;
        if(n % 2 == 0)
        {
            
            for(int f = 0; f < n/2; f++)
            {
                cout << iString << endl << uString << endl;
            }
        }
        else
        {
        
            for(int f = 0; f < n/2; f++)
            {
                cout << iString << endl << uString << endl;
            }
            cout << iString << endl;
        }
    }
    return 0;
}