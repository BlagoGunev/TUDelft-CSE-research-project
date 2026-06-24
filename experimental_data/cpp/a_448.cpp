#include<iostream>

using namespace std;

int main(){



    int a1,a2,a3,b1,b2,b3,K;

    cin>>a1>>a2>>a3>>b1>>b2>>b3>>K;



    int a = (a1+a2+a3 + 4) / 5;

    int b = (b1+b2+b3 + 9) / 10;



  a+b<=K ? cout<<"YES"<<endl : cout<<"NO"<<endl;



    return 0;

}