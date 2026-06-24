#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    vector<int> a, b;
    int N, M;
    cin >> N >> M;
    int tmp;

    for(int i = 0; i < N; i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    for(int i = 0; i < M; i++){
        cin >> tmp;
        b.push_back(tmp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    /*if(a[0] == b[0]){
        cout << a[0];
        return 0;
    }*/
    int m = 999;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(a[i] == b[j]){
                if(a[i] < m){
                    m = a[i];
                }
            }
        }
    }
    if(m != 999){
        cout << m;
        return 0;
    }
    cout << min(a[0], b[0])*10 + max(a[0], b[0]);
    return 0;
}