#include<bits/stdc++.h>

#define int long long
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()

const double eps=1e-7,PI=3.14159265358979323846;
const int N=1e6+10;

using namespace std;

int n,q,m,k,x,y,a[N],mx=-1,mn=1e9,sum;
string s,s1,s2;
map < int , int > mp;
vector < int > vec;

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>q;
    while (q--){
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<1;
        bool ok=0;
        int lst=a[0];
        for (int i=1;i<n;i++){
            if (!ok&&a[i]>=lst){
                lst=a[i];
                cout<<1;
            }
            else if (!ok&&a[i]<=a[0]){
                lst=a[i];
                cout<<1;
                ok=1;
            }
            else if (ok&&a[i]>=lst&a[i]<=a[0]){
                lst=a[i];
                cout<<1;
            }
            else {
                cout<<0;
            }
        }
        cout<<"\n";
    }
    return 0;
}