#include<bits/stdc++.h>

using namespace std;



int main(){

    int t;

    cin >> t;

    while(t--){

        int n;

        cin >> n;

        int a=0,b=0,c=0,d=0;

        while(n--){

            int i,j;

            cin >> i >> j;

            if(i==0 && j<0)

                a=max(a,abs(j));

            else if(i==0)

                b=max(b,abs(j));

            else if(i<0)

                c=max(c,abs(i));

            else

                d=max(d,abs(i));

        }

        cout << 2*(a+b+c+d) << endl;

    }

    return 0;

}