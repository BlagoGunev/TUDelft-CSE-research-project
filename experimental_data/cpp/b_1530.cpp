#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    int n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        if(n%2!=0){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(i%2==0){
                        cout <<"0";
                    }
                    else{
                        if(i==1||i==n){
                            if(j%2!=0){
                                cout << "1";
                            }
                            else{
                                cout << "0";
                            }
                        }
                        else{
                            if(j==1||j==m){
                                cout << "1";
                            }
                            else{
                                cout << "0";
                            }
                        }
                    }
                }
                cout << endl;
            }
        }
        else{
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(i==2||i==3){
                        cout <<"0";
                    }
                    else{
                        if(i%2==0&&i!=n){
                            if(j==1||j==m){
                                cout << "1";
                            }
                            else{
                                cout << "0";
                            }
                        }
                        else if(i==1||i==n){
                            if(j%2!=0){
                                cout << "1";
                            }
                            else{
                                cout << "0";
                            }
                        }
                        else{
                            cout << "0";
                        }
                    }
                }
                cout << endl;
            }
        }
        cout << endl;
    }
    return 0;
}