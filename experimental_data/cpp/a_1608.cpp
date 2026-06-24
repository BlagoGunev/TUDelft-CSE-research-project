#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    int linput=2;
    int counter=1;
    for(int j=0; j<t; j++)
    {
         int i=0;
        int n;
        cin>>n;
        if(n==1)
            cout<<n<<endl;
        else
        {
            while(i<n)
            {
               counter++;
                if(counter%linput-1==0)
                   {
                       i++;
                       linput=counter;
                       cout<<counter<<' ';
                   }
            }
        }
        cout<<endl;
    }
    return 0;
}