#include<bits/stdc++.h>



using namespace std;



int main()

{

   int t,a,b,k,c=0;



   cin>>t;



   while(t--){

    cin>>a>>b>>k;



    c=0;



    while(1){

        if(a>b){

            b+=a;

            c++;

        }

        else{

            a+=b;

            c++;

        }

        if(a>k || b>k){

            break;

        }



    }



    cout<<c<<endl;



   }









}