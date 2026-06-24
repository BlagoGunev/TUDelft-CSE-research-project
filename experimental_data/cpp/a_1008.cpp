#include <bits/stdc++.h>
using namespace std;

int main()
{

    string x;
    cin>>x;
    bool flag=true;
    for(int i=0;i<x.length()-1;i++)
    {

        if(x[i]!='a' && x[i]!='e' && x[i]!='i' && x[i]!='o' && x[i]!='u' && x[i]!='n'
           && (x[i+1]!='a' && x[i+1]!='e' && x[i+1]!='i' && x[i+1]!='o' && x[i+1]!='u') ){
            //cout<<i<<endl;
            flag=false;
           }

    }
     if(x[x.length()-1]!='a' && x[x.length()-1]!='e' && x[x.length()-1]!='i' && x[x.length()-1]!='o'
           && x[x.length()-1]!='u' && x[x.length()-1]!='n' )
            flag=false;
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}