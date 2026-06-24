#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int bio[30];
int main()
{
    string t;
    cin >> t;
    int k;
    cin >> k;
    int rz = 0, is = 0;
    for(int i = 0; i < t.size(); i++)
    {
        if(bio[t[i]-'a'] == 0)
        {
            rz++;
            bio[t[i]-'a'] = 1;
        }
        else
        {
            is++;
        }
    }
    if(k > rz + is)
    {
        cout << "impossible" << endl;
    }
    else if(rz >= k)
    {
        cout << 0 << endl;
    }
    else if(is >= k - rz)
    {
        cout << k-rz << endl;
    }
    return 0;
}