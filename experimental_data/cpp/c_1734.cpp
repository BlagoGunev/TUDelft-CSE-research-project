#include<bits/stdc++.h>

using namespace std;



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    long long int t;

    cin>>t;

    while(t--){

    

        int n;

        cin>>n;

        string s;    

        cin>>s;

        s=" "+s;

 

        vector<int> visited(n+1,0);

 

        for(int i=1;i<=n;i++){

            if(s[i]=='1')visited[i]=-1;

        }

 

        long long int ans=0;

        for(int i=1;i<=n;i++){

            for(int j=i;j<=n;j+=i){

                if(visited[j]==0){

                    visited[j]=1;

                    ans+=i;

                }

                else if(visited[j]==-1){

                    break;

                }

            }

        }

 

        cout<<ans<<endl;

 

    }



    return 0;

}