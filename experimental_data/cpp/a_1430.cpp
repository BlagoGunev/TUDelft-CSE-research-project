#define lli long long int

#include<bits/stdc++.h>

using namespace std;



// 3 5 7 

void f(){

lli n = 0 ; cin>>n;

for (int i =n/7 ; i >= 0; i--) // recall this is what we do in manual counting

{ lli a = n - (7*i);

for (int j = a/5; j>= 0; j--)

{ lli b = a - (j*5);

 if (b%3==0){cout<< b/3<<" "<<j<<" "<<i<<"\n";  ; return ;}

}



}

cout<<"-1\n";





}

int main(){ 

int t=0;cin>>t;for (int i=0; i< t; i++ ) f();

return 0;

}