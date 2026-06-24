#include<bits/stdc++.h>
using namespace std;

int t;
int str , intt , exp1;

int main()
{
    cin >> t;
    for(int i = 1 ; i <= t ; i++)
    {
        cin >> str >> intt >> exp1;
        long long los = intt - str + 1 , x;
        if((los + exp1) < 0) los =- exp1;
        if((los + exp1) % 2 == 0) x = (exp1 + los) / 2;
        else x = (exp1 + los) / 2 + 1;
        if(x <= exp1) cout << exp1 - x + 1 <<endl;
        else cout<< "0" <<endl;
    }
}