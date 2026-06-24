#include<bits/stdc++.h>

using namespace std;



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    

    int t;

    cin>>t;

    

    while(t--){

        int a, b, c, d;

        cin>>a>>b>>c>>d;

        

        long long x, y, x1, y1, x2, y2;

        cin>>x>>y>>x1>>y1>>x2>>y2;

        

        long long xans=x+b-a;

        long long yans=y+d-c;

        

        bool flag1=false, flag2=false;

        if(x1 <= xans && xans <= x2)

            flag1=true;

        if(y1 <= yans && yans <= y2)

            flag2=true;

            

        if(x1 == x2 && x == x1 && a != 0 && b != 0)

            flag1=false;

        if(y1 == y2 && y == y2 && c != 0 && d != 0)

            flag2=false;

            

        if(flag1 && flag2)

            cout<<"Yes"<<endl;

        else

            cout<<"No"<<endl;

    }

    

    return 0;

}