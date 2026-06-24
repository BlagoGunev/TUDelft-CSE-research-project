#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    int c[N];
    for(int i=0; i<N; i++){
        cin>>c[i];
        c[i] -= 1;
    }
    for(int i=0, j;i<N;i++){
        vector<bool> visited(N, false);
        j = i;
        while(!visited[j]){
            visited[j] = true;
            j = c[j];
        }
        cout<<j+1<<" ";
    }
    return 0;
}