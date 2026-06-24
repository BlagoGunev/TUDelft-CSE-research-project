#include <bits/stdc++.h>

#define mk make_pair

#define pb push_back

#define ms(x,y) memset(x,y,sizeof(x))

#define Mod 322122547191331

typedef long long ll;



using namespace std;



int main() {

    ios::sync_with_stdio(0);

    int t;

    cin>>t;

    while(t--){

        int n;

        cin>>n;

        vector<int> a(n);

        for(int i=0;i<n;i++)cin>>a[i];

        if(n&1){

            cout<<"Mike"<<endl;

            continue;

        }

        int mn=INT_MAX;

        int res=-1;

        for(int i=0;i<n/2;i++){

            int t=min(a[i*2],a[i*2+1]);

            if(t<mn){

                res=a[i*2]>a[i*2+1];

                mn=t;

            }

        }

        cout<<(res?"Mike":"Joe")<<endl;

    }

    return 0;

}