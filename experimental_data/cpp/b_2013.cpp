#include <bits/stdc++.h>
using namespace std;

void prim(){
    int n;
    cin >> n;
    long long int rje=0;
    for (int i=0;i<n;i++){
        int unos;
        cin >> unos;
        if (i==n-2){
            rje-=unos;
        }
        else {
            rje+=unos;
        }
    }
    cout << rje << "\n";
}

int main(){
    int t;
    cin >> t;
    for (int i=0;i<t;i++){
        prim(); 
    }
}