// Created by KHALED MOSHARRAF PARVEZ

#include <bits/stdc++.h>



#define whatis1(x) cout<<#x<<"="<<x<<'\n'

#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'

#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'

#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';

#define whatArray2D(arr,m,n) cout<<#arr<<", Size: "<<m<<","<<n<<'\n';for(int mm=0;mm<m;mm++){for(int nn=0;nn<n;nn++)cout<<arr[mm][nn]<<" ";cout<<'\n';} 

#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'

#define endl '\n'

#define all(v) v.begin(),v.end()

#define mod 1000000007

#define MX 200005



using namespace std;

using ll = long long;



void solve(int caseno){

    int n;

    cin>>n;

    vector<int> v(n);

    ll sum = 0;

    for(int i=0;i<n;i++) {

        cin>>v[i];

        sum+=v[i];

    }

    int ans =0;

    for(int k=n; k>=1; k--) {

        if(sum%k!=0)continue;

        ll avg = sum/k;

        int num=0;

        ll add=0;

        for(int i=0; i<n; i++) {

            add+=v[i];

            if(add==avg){

                add=0;

                num++;

            }

            else if(add>avg){break;}

        }

        if(num==k){

            cout<<n-k<<'\n';return;

        }



    }

    

    return;

    

}

int main()

{

    ios::sync_with_stdio(0);

    int cases,caseno=0;

    cin>>cases;

    while(cases--){

        solve(++caseno);

    }

    return 0;

}