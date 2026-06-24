#include<iostream>
using namespace std;
int main()
{
    int size,a,b,c;
    cin>>size;
    while(size>0)
    {
        cin>>a;
        cin>>b;
        cin>>c;
        if (b==a)
        {
            cout<<c<<endl;
        }
        else if(b==c)
        {
            cout<<a<<endl;
        }
        else
        {
            cout<<b<<endl;
        }
        size--;
    }
}