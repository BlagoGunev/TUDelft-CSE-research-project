#include <bits/stdc++.h>
using namespace std;
int n;
string s, l = "", saida = "";
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s;

    for(int i = 0; i<s.size(); i++) l += 'A';

    for(int i = 0; i<s.size(); i++)
    {
        if(i < s.size() - 2) {
        if(s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o')
        {
        if(l[i] != '*') {
            saida += "***";
            l[i] = '*';
            l[i+1] = '*';
            l[i+2] = '*';
            } else
            {
            //cout<<i<<" ";
                l[i] = '*';
                l[i+1] = '*';
                l[i+2] = '*';
               // i+=2;
            }

        } else if(l[i] != '*')saida += s[i], l[i] = s[i];

        }

        else if(l[i] != '*')saida += s[i], l[i] = s[i];


    }

    cout<<saida<<"\n";
}