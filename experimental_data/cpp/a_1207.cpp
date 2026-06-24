#include<bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int b, p, f, h, c, ans;
        cin >> b >> p >> f >> h >> c;
        if(b == 1) cout << "0" << endl;
        else {
            int foo = p, bar = f;
            if(h > c) {
                while(2 * (foo + bar) > b && foo > 0 && bar > 0) bar--;
            }
            else {
                while(2 * (foo + bar) > b && foo > 0 && bar > 0) foo--;
            }
            while(2 * (foo + bar) > b && foo > 0) foo--;
            while(2 * (foo + bar) > b && bar > 0) bar--;
            cout << foo * h + bar * c << endl;
        }
    }
    return 0;
}