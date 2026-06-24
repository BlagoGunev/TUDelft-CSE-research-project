#include <iostream>
using namespace std;

int main()
{
    long long n,k,z=50;
    cin>>n>>k;
    long long arra[z],c=0;
    for(long long i=1 ; ; i=(i*2)){
        arra[c]=i;
        c++;
        if(c>=50)break;
    }
    for(int i=49 ; i>=0 ; i--){
        if(k%arra[i]==0){
            cout<<i+1<<endl;
            return 0;
            }
    }

    return 0;
}