#include <iostream>



using namespace std;

int main(){

    int n,x,a[100+10],b[100+10];

    cin>>n>>x;

    for(int i=0;i<n;i++)

        cin>>a[i]>>b[i];

    for(int i=0;i<n;i++)

        if(a[i]==x||a[i]==7-x||b[i]==x||b[i]==7-x){

            cout<<"NO";

            return 0;

        }

    cout<<"YES";

}