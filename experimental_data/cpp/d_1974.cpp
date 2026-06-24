#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    int l = 0;
    int u = 0;

    int l1 = 1;
    int r1 = 1;

    int nn = 0, ss = 0, e = 0, w = 0;

    string A;

    for(int i = 0; i < n; i++){
        if(s[i] == 'N'){ 
            u++;
            nn++;
        }
        else if(s[i] == 'S'){ 
            u--;
            ss++;
        }
        else if(s[i] == 'W') {
            l++;
            w++;
        }
        else {
            l--;
            e++;
        }


    }

    int n1, n2, s1, s2, e1, e2, w1, w2;

    
    n2 = nn/2;
    s2 = ss/2;
    n1 = nn - n2;
    s1 = ss - s2;
    
    
    e1 = e/2;
    w1 = w/2;
    e2 = e - e1;
    w2 = w - w1;

    int tot = e1+w1+n1+s1;

    if(u%2 != 0 || l%2 != 0 || tot == 0 || tot == n){
        cout<<"NO\n";
        return;
    }



    for(int i = 0; i < n; i++){
        if(s[i] == 'N'){
            if(n1 > 0){
                A.push_back('H');
                n1--;
            }
            else{
                A.push_back('R');
                n2--;
            }
        }
        else if(s[i] == 'S'){
            if(s1 > 0){
                A.push_back('H');
                s1--;
            }
            else{
                A.push_back('R');
                s2--;
            }
        }
        else if(s[i] == 'E'){
            if(e1 > 0){
                A.push_back('H');
                e1--;
            }
            else{
                A.push_back('R');
                e2--;
            }
        }
        else{
            if(w1 > 0){
                A.push_back('H');
                w1--;
            }
            else{
                A.push_back('R');
                w2--;
            }
        }
    }

    cout<<A<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}