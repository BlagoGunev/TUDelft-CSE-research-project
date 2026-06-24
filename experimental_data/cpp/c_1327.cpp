#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pll pair <long long, long long>

#define DIM 207
#define INF 998244353

using namespace std;

ll n,k,m,sx[DIM],sy[DIM],fx[DIM],fy[DIM];

int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=k;i++) {
        cin>>sx[i]>>sy[i];
    }
    for (int i=1;i<=k;i++) {
        cin>>fx[i]>>fy[i];
    }
    if (n==1) {
        cout<<2*m-2<<endl;
        for (int i=1;i<m;i++) cout<<"L";
        for (int i=1;i<m;i++) cout<<"R";
    }
    else if (m==1) {
        cout<<2*n-2<<endl;
        for (int i=1;i<n;i++) cout<<"D";
        for (int i=1;i<n;i++) cout<<"U";
    }
    else {
        cout<<(n-1+m-1+(n)*(m))<<endl;
        for (int i=1;i<n;i++) cout<<"D";
        for (int i=1;i<m;i++) cout<<"L";
        for (int i=1;i<=n;i++) {
            for (int j=1;j<m;j++) {
                if (i%2==1) cout<<"R";
                else cout<<"L";
            }
            cout<<"U";
        }
    }
    return 0;
}