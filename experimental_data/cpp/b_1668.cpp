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

        int n,m;

        cin>>n>>m;

        int a[n];

        fl(i,0,n)

            cin>>a[i];

        sort(a,a+n);

        reverse(a,a+n);

        if(n==1){

            if(m>a[0])

                cout<<"YES"<<endl;

            else

                cout<<"NO"<<endl;

            continue;

        }

        int l=a[0]+1;

        int r=m-a[0];

        bool result=true;

        fl(i,1,n){

            if(l<r){

                if(a[i]+l<m){

                    l+=a[i]+1;

                }

                else{

                    result=false;

                    break;

                }

            }

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