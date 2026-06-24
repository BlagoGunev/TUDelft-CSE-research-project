#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,q,p,a;
    cin >>p;
    a=0;
    for (i=0; i<p; i++){
        cin >>q;
        if (q==1){
            a=1;
            break;
        }
    }
    if (a==1) cout<<"HARD"; else cout<<"EASY";
    return 0;

}