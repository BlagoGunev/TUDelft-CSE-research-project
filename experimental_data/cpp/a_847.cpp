#include <iostream>

using namespace std;

struct asdf{
    int l;
    int r;
}v[110];

int s[110], n, r, l, k;

void solve(){
    for(int i = 1; i <= k; i++){
        while(v[s[i]].r != 0){
            s[i] = v[s[i]].r;
        }

        v[s[i]].r = s[i+1];
        v[s[i+1]].l = s[i];
    }
}

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> l >> r;

        v[i].l = l;
        v[i].r = r;

        if(l == 0){
            s[++k] = i;
        }
    }

    solve();

    for(int i = 1; i <= n; i++){
        cout << v[i].l << ' '<< v[i].r << '\n';
    }

    return 0;
}