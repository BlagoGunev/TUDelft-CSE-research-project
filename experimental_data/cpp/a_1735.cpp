#include <iostream>

 

using namespace std;

 

int main()

{

    int t;

    cin>>t;

    while(t--)

    {

        long long z;

        cin>>z;

        long long  k=z/3,f=k+2;

        long long d1=k-1;

        long long d2=1;

        long long  d3 = z-(k+2)-1;

        long long  l1=abs(d1-d2);

        long long  l2=abs(d2-d3);

        long long l3=abs(d3-d2);

        long long e=min(l1,l3);

        long long  m=min(e,l2);

        cout<<m<<endl;

 

    }

}