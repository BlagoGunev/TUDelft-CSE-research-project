#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    unsigned long long int n;
    unsigned long long int k;
    int i;
    unsigned long long int skaitliukas = 0;
    unsigned long long int ats[t];
    unsigned long long int liekana;
    for(i=0; i<t; i++){
        cin >> n >> k;
        skaitliukas = 0;
        while(n != 0){
            liekana = n%k;
            if(liekana == 0){
                n = n/k;
                skaitliukas++;
            }
            else{
                n = n - liekana;
                skaitliukas += liekana;
            }
        }
        //cout << skaitliukas << "\n";
        ats[i] = skaitliukas;
    }
    for(i=0; i<t; i++){
        cout << ats[i] << "\n";
    }

    return 0;
}