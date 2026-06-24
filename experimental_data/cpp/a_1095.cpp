#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0;
    char s[60];
    cin >> n;
    cin >> s;
    cout << s[0];
    for(int i=1;s[sum]!='\0';i++)
    {
        sum=sum+i;
        //cout << sum;
        if(sum==n)
        {
            break;
        }
        cout << s[sum];

    }
}