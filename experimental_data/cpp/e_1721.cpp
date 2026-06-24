#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1001*1001,M=26;

string s,t;

int q;

map<string,vector<int>>mp;

int main()

{ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>s>>q;

    vector<int>p(s.size());

    for(int i=1;i<s.size();i++){

        int j=p[i-1];

        while(j>0 && s[i]!=s[j])j=p[j-1];

        if(s[i]==s[j])j++;

        p[i]=j;

    }

    vector<vector<int>>A(s.size(),vector<int>(M,0));

    for(int i=0;i<s.size();i++){

        for(int j=0;j<M;j++){

            if(i>0 && s[i]!=j+'a')A[i][j]=A[p[i-1]][j];

            else A[i][j]=i+(s[i]==j+'a');

        }

    }

    while(q--){

        cin>>t;

        int cur=p.back();

        s+=t;



        for(int i=s.size()-t.size();i<s.size();i++){

            vector<int>tmp(M,0);

            p.push_back(A[cur][s[i]-'a']);



           for(int j=0;j<M;j++){

                if(i>0 && s[i]!=j+'a')

                    tmp[j]=A[p[i-1]][j];

                else

                    tmp[j]=i+(s[i]==j+'a');

            }

            cur=A[cur][s[i]-'a'];

            A.push_back(tmp);



            cout<<p.back()<<' ';

        }

        while(!t.empty()){

            t.pop_back();

            s.pop_back();

            A.pop_back();

            p.pop_back();

        }

        cout<<'\n';

    }

    return 0;

}