// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t=1;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> a(n),b(n),c(n);
        vector<pair<long long,long long>> ap,bp,cp; 
        for(int i=0;i<n;i++){
            cin>>a[i];
            ap.push_back({a[i],i});
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            bp.push_back({b[i],i});
        }
        for(int i=0;i<n;i++){
            cin>>c[i];
            cp.push_back({c[i],i});
        }
        long long mx=0;
        sort(ap.rbegin(),ap.rend());
        sort(bp.rbegin(),bp.rend());
        sort(cp.rbegin(),cp.rend());
        for(int i=0;i<=2;i++){
            for(int j=0;j<=2;j++){
                for(int k=0;k<=2;k++){
       if(ap[i].second!=bp[j].second and cp[k].second!=bp[j].second and ap[i].second!=cp[k].second){
          mx=max(mx,ap[i].first+bp[j].first+cp[k].first);   
         }
                }
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}