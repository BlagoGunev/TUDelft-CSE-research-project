#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r,g,b,w; cin>>r>>g>>b>>w;
        if (r % 2 == 0 && g % 2 == 0 && b % 2 == 0)
            cout << "YES";
        else if ((r % 2) + (g % 2) + (b % 2) == 1 && w % 2 == 0)
            cout << "YES";
        else if ((r % 2) + (g % 2) + (b % 2) == 2 && w % 2 != 0 && r && b && g)
            cout << "YES";
        else if ((r % 2) + (g % 2) + (b % 2) == 3)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}