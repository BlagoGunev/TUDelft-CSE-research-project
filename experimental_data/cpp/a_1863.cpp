#include <iostream>
#include<vector>
using namespace std;
vector<char>x;

int main()
{
    
    int m,a,b,c;
    char y;
    cin >> m;
    while (m--)
    {
        x.clear();
        bool u = 0;
        int sum1 = 0;
        cin >> a >> b >> c;
        for (int i = 0; i < c; i++)
        {
            cin >> y;
            x.push_back(y);
        }
        if (a == b)
        {
            cout << "YES\n";
            continue;
        }
        int q = b;
        for (auto i = x.begin(); i != x.end(); i++)
        {
            if (*i == '-')
                sum1++;
            else
            {
                if (sum1 == 0)
                {
                    b++;
                    if (b == a)
                    {
                        u = 1;
                        break;
                    }
                }
                else
                    sum1--;
            }
        }
        if(u)
        {
            cout << "YES\n";
            
            continue;
        }
        else
        {
            for (auto i = x.begin(); i != x.end(); i++)
            {
                if (*i == '+')
                {
                    q++;
                    
                }
            }
            if (q < a)
                 cout << "NO\n";
            else
                cout << "MAYBE\n";

        }
    }
}