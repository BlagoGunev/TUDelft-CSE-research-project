#include <bits/stdc++.h>

using namespace std;

long long c;

void gcd(long long a, long long b){

    while (a!=0 && b!=0){



    if (a<b)

    {

        c+=b/a;

        b=b%a;

    }

    else {

        c+=a/b;

        a=a%b;

    }

    }

}



int main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    long long a, b;

    cin>>a>>b;

    c=0;

    gcd(a,b);

    cout<<c;

}