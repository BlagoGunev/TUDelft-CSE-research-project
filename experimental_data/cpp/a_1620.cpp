#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string c;
        cin>>c;
        
        int flag = 0;
        for(int i=0;i<c.size();i++)
        {
            if(c[i]=='N'){
                flag++;
            }
        }
        if(flag == 1)
        {
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
}