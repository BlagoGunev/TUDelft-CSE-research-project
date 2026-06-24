#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#define debug(x) cerr << #x << " is " << x << endl;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define endl '\n'

#define pb push_back

#define F first

#define S second

#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()

#define ll long long int

using namespace __gnu_pbds;

using namespace std;

typedef tree<pair<long long, long long>,null_type,less<pair<long long, long long>>,rb_tree_tag,

tree_order_statistics_node_update> indexed_set;

indexed_set st;

const int mod = 1e9 + 7;

int n, diff, cnt, j;

bool flag = 0;

string s;

void doWork(){

    cin >> n >> s;

    for(int i = 0; i < n; ++i){

        if(s[i] == ')'){

            diff -= 1;

        }

        if(s[i] == '('){

            diff += 1;

        }

        if(diff == 0){

            if(flag){

                /// Segment Reorder

                cnt += (i + 1) - j;

            }

            j = i + 1;

            flag = 0;

        }

        if(diff < 0){

            flag = 1;

        }

    }

    if(diff != 0){

        cout << -1 << endl;

    }

    else{

        cout << cnt << endl;

    }

}

int main(){

    FastIO

    int tc = 1;

    while(tc--){

        doWork();

    }

    return 0;

}