// LUOGU_RID: 96331355

#include<bits/stdc++.h>

using namespace std;

int a[15];

int main(){

    cout<<fixed<<setprecision(2);

    for(int i=10;i>=0;i--) cin>>a[i];

    for(int i=0;i<=10;i++){

        int x=a[i];

        double res=sqrt(abs(x))+x*x*x*5;

        if(res>400) cout<<"f("<<x<<") = MAGNA NIMIS!"<<'\n';

        else cout<<"f("<<x<<") = "<<res<<'\n';

    }

}