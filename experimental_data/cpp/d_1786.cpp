#include<bits/stdc++.h>

using namespace std;

#define int long long



struct ob{

    int x1,c1,x2,c2;

};



char fun(int x){

    if(x==0)return 'i';

    if(x==1)return 'n';

    return 'w';

}



int32_t main(){

   ios_base::sync_with_stdio(false);

   cin.tie(NULL);cout.tie(NULL);

   int t;cin>>t;

   while(t--){

       int n;cin>>n;

       vector<string>a(n);

       vector<vector<int>>b(n,vector<int>(3,0));

       for(int i=0;i<n;i++){

          cin>>a[i];

          for(int j=0;j<3;j++){

            if(a[i][j]=='i')b[i][0]++;

            if(a[i][j]=='n')b[i][1]++;

            if(a[i][j]=='w')b[i][2]++;

          }

       }

       vector<vector<int>>c(6);

       for(int i=0;i<n;i++){

           if(b[i][0]==1 && b[i][1]==1 && b[i][2]==1)continue;

           if(b[i][0]>1  && b[i][1]==0)c[0].push_back(i);

           if(b[i][0]==0 && b[i][1]>1 )c[1].push_back(i);

           if(b[i][0]>1  && b[i][2]==0)c[2].push_back(i);

           if(b[i][0]==0 && b[i][2]>1 )c[3].push_back(i);

           if(b[i][1]>1  && b[i][2]==0)c[4].push_back(i);

           if(b[i][1]==0 && b[i][2]>1 )c[5].push_back(i);

       }

       vector<ob>vec;

       while(c[0].size() && c[1].size()){

            struct ob d;

            d.x1=c[0].back()+1;

            d.c1=0;

            d.x2=c[1].back()+1;

            d.c2=1;

            vec.push_back(d);

            c[0].pop_back();

            c[1].pop_back();

       }

       while(c[2].size() && c[3].size()){

            struct ob d;

            d.x1=c[2].back()+1;

            d.c1=0;

            d.x2=c[3].back()+1;

            d.c2=2;

            vec.push_back(d);

            c[2].pop_back();

            c[3].pop_back();

       }

       while(c[4].size() && c[5].size()){

            struct ob d;

            d.x1=c[4].back()+1;

            d.c1=1;

            d.x2=c[5].back()+1;

            d.c2=2;

            vec.push_back(d);

            c[4].pop_back();

            c[5].pop_back();

       }

       while(c[0].size() && c[4].size() && c[3].size()){

            struct ob d;

            d.x1=c[0].back()+1;

            d.c1=0;

            d.x2=c[4].back()+1;

            d.c2=1;

            vec.push_back(d);

            c[0].pop_back();

            c[4].pop_back();



            struct ob m;

            m.x1=d.x2;

            m.c1=0;

            m.x2=c[3].back()+1;

            m.c2=2;

            vec.push_back(m);

            c[3].pop_back();

       }

        while(c[1].size() && c[2].size() && c[5].size()){

            struct ob d;

            d.x1=c[1].back()+1;

            d.c1=1;

            d.x2=c[2].back()+1;

            d.c2=0;

            vec.push_back(d);

            c[1].pop_back();

            c[2].pop_back();



            struct ob m;

            m.x1=d.x2;

            m.c1=1;

            m.x2=c[5].back()+1;

            m.c2=2;

            vec.push_back(m);

            c[5].pop_back();

       }

       cout<<vec.size()<<'\n';

       for(auto p : vec){

           cout<<p.x1<<" "<<fun(p.c1)<<" "<<p.x2<<" "<<fun(p.c2)<<'\n';

       }

   }

}