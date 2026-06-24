#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string.h>

using namespace std;

#define FILE
#undef FILE

#ifdef FILE
#include <fstream>
#define cin in
#define cout out
fstream in("input.txt", ios::out), out("output.txt", ios::out);
#endif

typedef long long ll;

ll n, w[1000],h[1000];
ll curh, curw, ans = -1;
bool fail = false;
bool ans_found = false;

int main(){
    cin >> n;
           
    for (int i = 0; i<n; i++){
        cin >> w[i] >> h[i];
    }
    
    for (int i = 0; i<n; i++){
        curh = h[i];
        curw = w[i];
        fail = false;
        for (int j = 0; j<n; j++)
        {   
            if (i == j) continue;
            
            if (min(h[j], w[j]) > curh){
                fail = true;
                break;
            }
            if (max(h[j], w[j]) <= curh) curw+=min(h[j], w[j]);
            else curw+=max(h[j], w[j]);
        }
        if (!fail){
            if (ans_found) ans = min(ans, curh*curw);
            else{
                ans_found = true;
                ans = curh*curw;
            }
        }
        //************************************************
        //************************************************
        curh = w[i];
        curw = h[i];
        fail = false;
        for (int j = 0; j<n; j++)
        {   
            if (i == j) continue;
            
            if (min(h[j], w[j]) > curh){
                fail = true;
                break;
            }
            if (max(h[j], w[j]) <= curh) curw+=min(h[j], w[j]);
            else curw+=max(h[j], w[j]);
        }
        if (!fail){
            if (ans_found) ans = min(ans, curh*curw);
            else{
                ans_found = true;
                ans = curh*curw;
            }
        }
        
    }
    cout << ans << endl;
    
    return 0;   
}