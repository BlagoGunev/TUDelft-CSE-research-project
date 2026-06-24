#include<iostream>

#include<string>

#include<algorithm>

using namespace std;

long long n,m,l[1111],c[1111],cnt;



int main(){

    cin>>n;

    for(int i=0;i<n;++i){

            cin>>l[i];

            

            }

            cin>>m;

            for(int i=0;i<m;++i){

                    cin>>c[i];

                   

                    }

                    sort(l,l+n);

                    sort(c,c+m);

                 for(int i=0;i<n;++i){

                         for(int j=0;j<m;++j){

                     if(abs(l[i]-c[j])<=1)  {

                                            c[j]=1000;

                                            cnt++;

                     break;

                                            }      

                    }

                    } 

                    cout<<cnt;  

    return 0;

    }