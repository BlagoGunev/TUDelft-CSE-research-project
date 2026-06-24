#include <iostream>
#include <string>

using namespace std;

int c[3000];


int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    
    string s = "";
    char curr = 'a';
    
    int p = n;
    while(p > 0)
    {
        if(c[p] == 0)
        {
            p--;
        }
        else
        {
            for(int i = 0; i < p; i++)
            {
                s.push_back(curr);
            }
            if(curr == 'a')
                curr = 'b';
            else
                curr = 'a';
            for(int i = 1; i <= p; i++)
            {
                c[i] -= p - i + 1;
            }
        }
    }
    
    cout << s;
    return 0;
}