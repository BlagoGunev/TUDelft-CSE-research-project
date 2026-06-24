#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pi pair<int,int>
#define mp make_pair
#define pb push_back
#define endl "\n"

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    if(n==0||n==1) cout << 10 << endl;
    else if(n==3||n==10) cout << 9 << endl;
    else if(n==9) cout << 0 << endl;
    else if(n==2||n==4||n==12) cout << 8 << endl;
    else if(n==5||n==8||n==7||n==6||n==5) cout << 7 << endl;
    else if(n==11) cout << 6 << endl;


    return 0;
}