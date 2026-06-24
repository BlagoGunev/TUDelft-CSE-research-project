#include<bits/stdc++.h>

using namespace std;



set<int>s;



void primefactors(long long n) {



    while (n%2 == 0){

        s.insert(2);

        n = n/2;

    }



    for (long long i = 3; i <= sqrt(n); i = i+2){

        while (n%i == 0){

            s.insert(i);

            n = n/i;

        }

    }



    if (n > 2) s.insert(n);

}



int main(){



    int n;



    cin>>n;



    if(n<=5){

        cout<<"0\n";

        return 0;

    }



    int k=0;

    for(int i=5;i<=n;i++){

        primefactors(i);

        if(s.size()==2) k++;

        s.clear();

    }



    cout<<k<<"\n";



}