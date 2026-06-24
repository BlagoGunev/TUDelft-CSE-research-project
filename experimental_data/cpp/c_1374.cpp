/* Alex Petrenko */
#include <algorithm>
#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
using ll = long long int;

int main()
{
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test)
    {
        int n;
        cin >> n;
        stack<char> myStack;
        for (int i = 0; i < n; ++i)
        {
            char cur;
            cin >> cur;
            if (cur == ')' && !myStack.empty() && myStack.top() == '(')
            {
                myStack.pop();
            }
            else
            {
                myStack.push(cur);
            }
        }
        cout << (myStack.size() / 2) << endl;
    }
}