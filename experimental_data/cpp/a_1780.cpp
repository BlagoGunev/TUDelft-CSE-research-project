#include <bits/stdc++.h>
using namespace std;
#define killua ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0)
int main(){
    #ifndef ONLINE_JUDGE
        freopen("Input.txt","r",stdin);
        freopen("Output.txt","w",stdout);
    #endif
    killua;
    int t=1; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>v(n); for(int i=0;i<n;i++) cin>>v[i];
        int co=0,ce=0;
        for(auto i:v){
            if(i%2==0)
                ce++;
            else
                co++;
        }
//        cout<<co<<" "<<ce<<endl;
        if(co>=3){
            cout<<"YES"<<endl;
            int x=0;
            for(int i=0;i<n&&x<3;i++){
                if(v[i]&1)
                    cout<<i+1<<" ",x++;
            }
        }
        else if(co>=1&&ce>=2){
//            cout<<"2"<<endl;
            cout<<"YES"<<endl;
            int l=0,r=0;
            for(int i=0;i<n;i++){
                if(v[i]&1&&l<1){
                    cout<<i+1<<" ";
                    l++;
                }
                else if(v[i]%2==0&&r<2){
                    cout<<i+1<<" ";
                    r++;
                }
            }
        }
        else
            cout<<"NO";
        cout<<endl;
    }
}