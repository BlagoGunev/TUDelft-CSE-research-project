#include <iostream>
using namespace std;

int main(){

    int n,z;
    cin>>n;
    int a[n];
    int c[101]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<101;i++){
        for(int j=0;j<n;j++){
            z=abs(i-a[j]);
            if(z!=0)
                c[i]+=z-1;
        }
    }
    long int max=100000000,maxi=-1;
    for(int i=1;i<101;i++){
        if(c[i]<max){
            max=c[i];
            maxi=i;
        }
    }
    cout<<maxi<<" "<<max;
}