#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;   
const int M=510;

int main(){
    ios::sync_with_stdio(0);
    int n,m,tmp;
    cin>>n>>m;
    if(3*m>n) cout<<-1;
    else {
        for(int i=1;i<=m;i++) cout<<i<<' ';
        for(int i=m+1;i<=n;i++){
            int t=(i+1)%m;
            if(t==0) t=m;
            cout<<t<<' ';
        }
    }
    return 0;
}