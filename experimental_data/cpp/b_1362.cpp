#include<bits/stdc++.h>

#define endl "\n"

#define int long long

using namespace std;

int32_t main()

{

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);



    int t;

    cin>>t;

    while(t--){

    

        int n,i,j,x,f=-1;

        cin>>n;

        int a[n];

        set<int>st,tmp;

        for(i=0;i<n;i++){

            cin>>a[i];

            st.insert(a[i]);

        }



        for(i=1;i<1024;i++){

            for(j=0;j<n;j++){

                x=(a[j]^i);

                if(st.count(x))tmp.insert(x);

                else break;

            }



            if(tmp.size()==st.size()){

                f=i;

                break;

            }

            tmp.clear();

        }



        cout<<f<<endl;

        

    }



    return 0;

}