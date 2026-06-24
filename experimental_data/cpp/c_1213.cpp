#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   int q=0;
   cin>>q;
   for(int i=0;i<q;i++){
    long long n,m;
    cin>>n>>m;
    long long c=0;
    long long c2=0;
    long long k=0;
    long long y=0;
    k=n/m;
    for(long long g=0;g<10;g++){
        y+=m;
        y%=10;
        c2+=y;
    }
    y=0;
    c+=(k/10)*c2;
    k=k%10;
    for(long long g=0;g<k;g++){
        y+=m;
        y%=10;
        c+=y;
    }
    cout<<c<<endl;;
   }

    return 0;
}