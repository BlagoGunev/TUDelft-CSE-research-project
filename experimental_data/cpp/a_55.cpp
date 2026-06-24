#include<iostream>

using namespace std;

bool a[1000+100];

 int main(){

    int n;

    cin>>n;

    for(int i=1;i<=n;i*=2)

        a[i]=true;

    if(a[n])

        cout<<"YES";

    else

        cout<<"NO";

}