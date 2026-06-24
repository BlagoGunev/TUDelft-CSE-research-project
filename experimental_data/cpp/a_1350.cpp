#include <iostream>

#include <bits/stdc++.h>



using namespace std;



int main() {

  long long int t,n,k,flag;

  cin>>t;

  for(int i=0;i<t;i++){

    cin>>n>>k;

    for(int j=1;j<=k;j++){

      long long int l;

      if(n%2==0){

        flag=0;

      }

      else{

        flag=1;

      }

      if(flag==0){

        l=2*(k-j+1);

        j=k;

      }

      else{

        l=3;

        while(n%l!=0){

          l=l+2;

          if(l>sqrt(n)){

            l=n;

          }

        }

      }

      n=n+l;

    }

    cout<<n<<endl;

  }

}