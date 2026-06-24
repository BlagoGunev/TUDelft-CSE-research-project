#include<bits/stdc++.h>

using namespace std;



typedef long long LL;



int arr[2 << 18];

string opt, str;



int main() {

    ios::sync_with_stdio(false);

    cin.tie(0), cout.tie(0);

    int n;

    while(cin >> n) {

        memset(arr, 0, sizeof(arr));

        for(int i = 0; i < n; i ++) {

            cin >> opt >> str;

            int t = 0;

            for(int i = 0; i < str.size(); i ++) {

                t *= 2;

                t += (str[i] - '0') % 2;

            }

            if(opt == "+") {

                arr[t] ++;

            }

            else if(opt == "-") {

                arr[t] --;

            }

            else if(opt == "?") {

                printf("%d\n", arr[t]);

            }

        }

    }

    return 0;

}