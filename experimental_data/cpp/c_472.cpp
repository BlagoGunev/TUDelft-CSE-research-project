#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
char A[200000+5][50+5];
bool Check[200000+5];
int n,t1,t2;
int main()
{
    //freopen("inp.txt","r",stdin);
    ios::sync_with_stdio(false);
    int i;
    cin >>n;
    for (i=1; i<=n*2; i++) {
        cin>> A[i];
    }

    cin>>t1;
    Check[t1*2-1]=true;
    Check[t1*2]=true;
    t2=t1;
    for (i=1; i<n; i++) {
        cin >>t2;
        if ( strcmp(A[t1*2-1], A[t2*2-1]) < 0 && Check[t1*2-1] ) Check[t2*2-1]=true;
        if ( strcmp(A[t1*2-1], A[t2*2]) < 0 && Check[t1*2-1] ) Check[t2*2]=true;
        if ( strcmp(A[t1*2], A[t2*2-1]) < 0 && Check[t1*2] ) Check[t2*2-1]=true;
        if ( strcmp(A[t1*2], A[t2*2]) < 0 && Check[t1*2] ) Check[t2*2]=true;
        if (Check[t2*2]==false && Check[t2*2-1]==false ) { cout <<"NO"; return 0;  }
        t1=t2;
    }
    if (Check[t2*2] || Check[t2*2-1] ) cout <<"YES"; else cout <<"NO";
    return 0;
}