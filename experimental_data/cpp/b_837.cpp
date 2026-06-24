#include <bits/stdc++.h>
using namespace std;

int main()
{
    //cout << "Hello World!" << endl;
    int n,i,m,j,k;
    cin>>n>>m;
    char s[n][m];
    string st;
    for(i=0;i<n;i++){
        cin>>s[i];
        
    }
    bool ok,ok1=false,ok2=false;
    if(n%3!=0 && m%3!=0)
        ok=false;
    else    
        ok=true;
    vector<char>v;    
    if(n%3==0){
        ok1=true;
        for(i=0;i<n;i+=(n/3)){
            char c = s[i][0];
            if(find(v.begin(),v.end(),c)!=v.end()){
                ok1=false;
                break;
            }
            v.push_back(c);
            for(k=i;k<i+(n/3);k++){
            for(j=0;j<m;j++){
                if(s[k][j]!=c)
                    ok1 = false;
            }
            }
        }
    }
    if(m%3==0){
        v.clear();
        ok2=true;
        for(i=0;i<m;i+=(m/3)){
            char c = s[0][i];
            if(find(v.begin(),v.end(),c)!=v.end()){
                ok2=false;
                break;
            }
            v.push_back(c);
            for(k=i;k<i+(m/3);k++){
            for(j=0;j<n;j++){
                if(s[j][k]!=c)
                    ok2 = false;
            }
            }
        }
    }
    if(ok && (ok1 || ok2))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}