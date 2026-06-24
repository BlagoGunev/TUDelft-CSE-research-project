#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define MOD 1000000007

void solve(){
    int x,y;

    cin>>x>>y;

    if((x+y)%2!=0){
        cout<<-1<<" "<<-1<<endl;
        return;
    }

    int found = false;

    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if((abs(x-i)+abs(y-j))==(x+y)/2){
                found = true;
                cout<<i<<" "<<j<<endl;
                return;
            }
        }
    }
}

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    //t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}