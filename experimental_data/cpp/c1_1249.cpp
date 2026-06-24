#include <iostream>
#include <algorithm> // std::fill

using namespace std;

int pw3[10] = {1,3,9,27,81,243,729,2187,6561,19683};
//bool tajz[10];

/*void taj(int n){
    int p = 9;

    while(pw3[p] > n){
        p--;
    }

    if (pw3[p] != n){
        tajz[p] = 1;
        taj(n - pw3[p]);
    } else {
        tajz[p] = 1;
        //cout << "taj ended for " << n << endl;
    }
}*/

int main(){
    int q;
    cin >> q;

    string state = "0000000000";
    int x = 0;
    unsigned long long int ans[1024] = {};
    while (state != "1111111111"){
        for (int i = 9; i > -1; i--){
            if (state[i] == '0'){
                state[i] = '1';
                for (int j = i + 1; j < 10; j++){
                    state[j] = '0';
                }
                break;
            }
        }
        ans[x] = 0;
        for (int i = 0; i < 10; i++){
            ans[x] += (state[i] - '0') * pw3[i];
        }

        //cout << state << endl;

        x++;
    }
    sort(ans, ans + 1024);

    //cout << x << endl;
    //for (int i =0 ; i < 1024; i++) cout << ans[i] << ",";

    int n;
    for (int i = 0; i < q; i++){
        //fill(tajz, tajz+10, 0);
        cin >> n;

        /*taj(n);

        int p = 0;
        while (tajz[p] == 1){
            p++;
        }*/

        //cout << "while ended for " << n << endl;
        //cout << "answer" << endl;
        for (int j = 1; j < 1024; j++){
            if (ans[j] >= n){
                cout << ans[j] << endl;
                break;
            }
        }
        //cout << n +  << endl;
    }

    return 0;
}