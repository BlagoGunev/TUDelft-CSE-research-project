#include <bits/stdc++.h>

#define ll long long int



using namespace std;



bool ok(vector<int> tmpV){

    if (tmpV[0]>=tmpV[1]+tmpV[2])

        return false;

    return true;

}

 int x,y;

int steps=0;

void call(vector<int>& v){

    sort(v.begin(),v.end());

    //cout<<"called = "<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;

    if (v[0]==x)

        return;

    steps++;



    vector<int> tmpV=v;

    tmpV[0]=x;

    if (ok(tmpV)){

        v=tmpV;

        call(v);

    }

    else {

        int tmp=v[2]+v[1]-1;

        v[0]=tmp;

        call(v);

    }



}



int main(){



    scanf("%d %d",&x,&y);

    vector<int> v(3,y);

    call(v);

    printf("%d",steps);







}