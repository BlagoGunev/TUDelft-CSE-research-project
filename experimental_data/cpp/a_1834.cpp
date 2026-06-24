#include <iostream>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        int sum = 0, mult = 1, ans = 0;
        
        for(int i = 0; i < n; ++i){
            int num;
            cin >> num;
            sum += num;
            mult *= num;
        }
        
        if(mult == -1){
            ans++;
            sum += 2;
            while(sum < 0){
                ans += 2;
                sum += 4;
            }
        }else{
            while(sum < 0){
                ans += 2;
                sum += 4;
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}