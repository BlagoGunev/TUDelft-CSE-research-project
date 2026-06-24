#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <math.h>
#include <cmath>
#include <vector>
#include <iomanip>
#include <stack>
#include <map>
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
using namespace std;
typedef long long ll;
struct Node{
    int x,y,id;
};
bool cmp(Node a,Node b){
    return a.y<b.y;
}
int main(){
    ios::sync_with_stdio(false);
    int n;
    Node p[3005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].x;
        p[i].id=i;
    }
    for(int i=0;i<n;i++){
        cin>>p[i].y;
    }
    sort(p,p+n,cmp);
    ll mi=INF;
    int poo=0;
    for(int i=0;i<n;i++){
        int t1=0;
        int t2=0;
        ll sum=p[i].y;
        //cout<<p[i].id<<' '<<p[i].x<<' '<<p[i].y<<endl;
        for(int j=0;j<n;j++){
            if(t1==1 && t2==1) break;
            //cout<<p[j].id<<' '<<p[j].x<<' '<<p[j].y<<endl;
            if(p[j].id<p[i].id && p[j].x<p[i].x && t1==0){
                sum+=p[j].y;
                t1=1;
            }
            else if(p[j].id>p[i].id && p[j].x>p[i].x && t2==0){
                sum+=p[j].y;
                t2=1;
            }
        }
        //cout<<t1<<' '<<t2<<endl<<endl;
        if(t1==1 && t2==1 && sum<mi){
            mi=sum;
            poo=1;
        }
    }
    if(poo)
        cout<<mi<<endl;
    else
        cout<<-1<<endl;
    return 0;
}