#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int r=2*n,g=5*n,b=8*n;
    int c=0;
    c+=r/k+g/k+b/k;
    if((r%k))c++;
    if((g%k))c++;
    if((b%k))c++;
    cout<<c<<endl;
}