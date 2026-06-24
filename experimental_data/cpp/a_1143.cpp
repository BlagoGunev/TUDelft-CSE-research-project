#include <bits/stdc++.h>
using namespace std;
int n, mx1=1, mx0=1;
int main(){
    int a;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        if(a)
            mx1 = i+1;
        else
            mx0 = i+1;
    }
    cout << min(mx1, mx0);
}