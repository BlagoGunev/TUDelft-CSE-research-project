#include<bits/stdc++.h>

#define IOS ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

#define ll long long

#define fl(x,y,n) for(int x=y;x<n;x++)

#define rfl(x,y,n) for(int x=y;x>=n;x--)

int main(){

    IOS;

    #ifndef ONLINE_JUDGE

        freopen("input.txt","r",stdin);

        freopen("output.txt","w",stdout);

    #endif

    int t;

    cin>>t;

    while(t--){

        int n;

        cin>>n;

        int a[n];

        fl(i,0,n)

            cin>>a[i];

        bool result=true,left=true,right=true;

        if(n==1){

            cout<<"YES"<<endl;

            continue;

        }

        for(int i=1;i<n;i++){

            if(a[i]-a[i-1]==1)

                continue;

            else if(a[i]-a[i-1]==2&&left){

                left=false;

                continue;

            }

            else if(a[i]-a[i-1]==2&&right){

                right=false;

                continue;

            }

            else if(a[i]-a[i-1]==3&&left&&right)

                right=left=false;

            else{

                result=false;

                break;

            }

        }

        if(result)

            cout<<"YES"<<endl;

        else

            cout<<"NO"<<endl;

    }

    return 0;

}