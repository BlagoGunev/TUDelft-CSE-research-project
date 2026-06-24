#include<iostream>
#include<vector>
using namespace std;
typedef long long hui;
int main(){
    hui n,m;
    cin >> n >> m;
    vector<hui>al(n);
    for (int i=0;i<n;++i) {
        cin >> al[i];
    }
    hui atmax=0,atmax_prev=0,atmin=0,pc=0,res=0;
    while (1) {
        ++pc;
        atmax_prev=atmax;
        atmin+=(pc-1)*n+1;
        atmax+=m-pc*n+1;
        hui prev=al[n-1]+pc;
        vector<hui> gc(n);
        for (int i=n-1;i>=0;--i) {
            prev-=pc;
            prev=min(prev,al[i]);
            gc[i]=prev;
        }
        if (gc[0]<atmin) break;
        if (atmin>atmax) break;
        hui tres=0;
        if (atmax<=gc[0]) {
            tres=m*(m+1)/2-(m-n*pc)*(m-n*pc+1)/2;
        } else {
            hui huileft;
            huileft=m-n*pc+min(atmax_prev+1,gc[0]);
            hui t=-pc;
//            cout << "huileft=" << huileft-gc[0] << endl;
            for (int i=0;i<n;++i){
                t+=pc;
                hui sh=min(huileft,gc[i]-t);
                huileft-=sh;
                t+=sh;
                tres+=t;
            }
        }
//        cout << pc << " " << tres << endl;
        res=max(res,tres);
    }        
    cout << res << endl;
    return 0;    
}