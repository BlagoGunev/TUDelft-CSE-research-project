#include <bits/stdc++.h>



using namespace std;



int main()

{

    int t;

    cin>>t;

    while(t--){

        int n,d;

        cin>>n>>d;

        int l,r,mid,z;

        l=0;r=1e9;

        bool p=0;

        z=n/2;

        z++;

        l=ceil((double)d/z);

        z--;

        

        if((z+l)<=n){

            cout<<"YES\n";

        }

        else cout<<"NO\n";

    }



    return 0;

}