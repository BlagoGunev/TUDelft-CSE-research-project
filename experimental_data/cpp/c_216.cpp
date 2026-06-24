#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include<bits/stdc++.h>

using namespace std;

int n,m,k;

int main(){

    cin>>n>>m>>k;

    int cnt=k,gin=0;

    int Save[n+m+1]={};

    vector<int>ans;

    if(k==1){

        for(int i=1;i<=n+m;i+=n-1)ans.push_back(i);

    }

    else{

    Save[0]=k;

    Save[n]=-k;

    for(int i=0;i<k;i++)ans.push_back(1);

    for(int i=0;i<n+m;i++){

            gin+=Save[i];

       if(gin<k){

            if(gin==0){

                gin++;

                Save[i+n-1]--;

                ans.push_back(i);

                cnt++;

            }

            int tmp=k-gin;

            Save[i]+=tmp;

            cnt+=tmp;

            gin+=tmp;

            for(int j=0;j<tmp;j++)ans.push_back(i+1);

        }



    }}cout<<ans.size()<<endl;

    for(int i=0;i<ans.size();i++)cout<<ans[i]<<(i+1==ans.size()?'\n':' ');





return 0;}