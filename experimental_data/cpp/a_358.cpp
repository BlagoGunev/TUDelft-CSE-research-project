#include <iostream>

#include <algorithm>



using namespace std;

int main(){

    long long n,x[1000+10];

    cin>>n;

    for(int i=0;i<n;i++)

        cin>>x[i];

    for(int i=0;i<n-1;i++){

        for(int j=0;j<n-1;j++){

            if(max(x[i],x[i+1])<max(x[j],x[j+1])&&

               min(x[i],x[i+1])<min(x[j],x[j+1])

               &&max(x[i],x[i+1])>min(x[j],x[j+1])){

                cout<<"yes";

                return 0;

            }

        }

    }

    cout<<"no";

}