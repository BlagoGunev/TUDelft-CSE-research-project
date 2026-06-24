#include <iostream>



using namespace std;

int main(){

    int n;

    cin>>n;

    int maxx=-1e9-1,minx=1e9+1,maxy=-1e9-1,miny=1e9+1;

    for(int i=0;i<n;i++){

        int x,y;

        cin>>x>>y;

        maxx=max(maxx,x),minx=min(minx,x);

        maxy=max(maxy,y),miny=min(miny,y);

    }

    long long a=maxx-minx,b=maxy-miny;

    long long z=max(a,b);

    cout<<z*z;

}