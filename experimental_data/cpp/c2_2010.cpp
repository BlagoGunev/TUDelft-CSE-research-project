#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll shash[1000005];
ll pot[1000005];
ll mod = 1e9+7;
ll p = 191;

int main()
{
    string s;
    cin >> s;
    pot[0] = 1;
    for(int i = 1; i <= 1000003; i++)
    {
        pot[i] = (pot[i-1] * p) % mod;
    }
    shash[0] = s[0] - '0' + 1;
    //cout << shash[0] << endl;
    for(int i = 1 ; i < s.size(); i++)
    {
        shash[i] = (shash[i-1] + (s[i] - '0' + 1) * pot[i] + mod) % mod;
        //cout << shash[i] << endl;
    }
    int startt = 0;
    for(int i = 0; i < s.size()-1; i++)
    {
        //cout << (shash[i] * pot[s.size()-i-1] + mod) % mod << " " <<  (shash[s.size()-1] - shash[s.size() - i - 2] + mod) % mod << endl;
        if((shash[i] * pot[s.size()-i-1] + mod) % mod == (shash[s.size()-1] - shash[s.size() - i - 2] + mod) % mod)
        {
            startt = i+1;
        }
    }
    if(startt > s.size()/2)
    {
        cout << "YES" << endl;
        for(int i = 0; i < startt; i++)
        {
            cout << s[i];
        }
    }
    else
    {
        cout << "NO" << endl;
    }





}