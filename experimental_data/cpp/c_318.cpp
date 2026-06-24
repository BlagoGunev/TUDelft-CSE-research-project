#include <iostream>
#include <string>
using namespace std;

int main(){
    long long x,y,m;
    cin >> x >> y >> m;
    if(x >= m || y >= m){
        cout << 0 << endl;
        return 0;
    }
    if(x <= 0 && y <= 0){
        cout << -1 << endl;
        return 0;
    }
    
    long long ans = 0;
    
    if(x < 0 || y < 0){
        if(x < y){
            ans += -1 * x / y;
            x += ans * y;
        } else {
            ans += -1 * y / x;
            y += ans * x;
        }
        
    }
    
    while(!(x >= m || y >= m)){
        if(x < y){
            x += y;
        } else {
            y += x;
        }
        ++ans;
    }
    cout << ans << endl;
}