#include <bits/stdc++.h>

#define pb push_back
#define db double
#define int long long
#define all(c) (c).begin(), (c).end()
using namespace std;

const int N = 1e6 + 1;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

inline int read () {
    char c = getchar();
    int t = 0, f = 1;
    while (!isdigit(c)) f = (c == '-') ? -1 : 1, c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    return t * f;
}

main() {
    int n = read(),
    k ;

    int t = 0 , cnt = 0;

    for(int i=1;i<=n;i++){
        k = read();
        if(k==1)
            t++;
        else cnt++;
    }

    if(t==0){
        cout<< 0;
    }else if(cnt==0)
    cout<< t/3;
    else {
        int d = min(t,cnt);

        if(d==t){

            cout<< t;

        }else cout<< cnt + (t-cnt)/3;



    }


}