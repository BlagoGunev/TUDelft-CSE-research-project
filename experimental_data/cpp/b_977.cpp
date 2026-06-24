// IN THE NAME OF ALAAH ^_^
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
    int n, aa[1000], mx=1;
    cin >> n;
    string s, a[1000]={"0"};
    cin >> s;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<=i+1; j++){
            a[i] = s[i];
            a[i] += s[j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (a[i]==a[j]){
                aa[i]++;
            }
        }
        if (aa[i]>mx){
            mx = aa[i];
        }
    }
    for (int i=0; i<n; i++){
        if (aa[i]==mx){
            cout << a[i];
            break;
        }
    }
}