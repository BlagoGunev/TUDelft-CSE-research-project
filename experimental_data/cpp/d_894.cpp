#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN=1000005, MAXM=100005;

int N, M, L[MAXN], D[MAXN];
long long K;

struct tree{
    vector<int> a;
    vector<long long> s;
} T[MAXN*3];

void makeTree(int idx, int t){
    if(t>N){
        return;
    }
    int lidx=idx<<1, ridx=lidx+1;
    makeTree(lidx, t*2);
    makeTree(ridx, t*2+1);
    int i, j;
    T[idx].a.push_back(D[t]);
    for(i=j=0; i<T[lidx].a.size() && j<T[ridx].a.size(); ){
        if(T[lidx].a[i]<T[ridx].a[j]){
            T[idx].a.push_back(T[lidx].a[i]);
            i++;
        }
        else{
            T[idx].a.push_back(T[ridx].a[j]);
            j++;
        }
    }
    for(; i<T[lidx].a.size(); i++){
        T[idx].a.push_back(T[lidx].a[i]);
    }
    for(; j<T[ridx].a.size(); j++){
        T[idx].a.push_back(T[ridx].a[j]);
    }
    T[idx].s.push_back(T[idx].a[0]);
    for(i=1; i<T[idx].a.size(); i++) T[idx].s.push_back(T[idx].a[i]+T[idx].s[i-1]);
}

int main(){
    int i, A, H, t, P, O;
    scanf("%d %d", &N, &M);
    for(i=1; i<N; i++)
        scanf("%d", L+i);
    for(i=2; i<=N; i++)
        D[i]=D[i/2]+L[i-1];
    makeTree(1, 1);
    for(i=1; i<=M; i++){
        scanf("%d %d", &A, &H);
        K=0;
        t=lower_bound(T[A].a.begin(), T[A].a.end(), D[A]+H)-T[A].a.begin();
        t=min(t, (int)T[A].a.size()-1);
        if(T[A].a[t]>=D[A]+H) t--;
        if(t>=0){
            K+=(long long)(t+1)*(D[A]+H)-T[A].s[t];
        }
        P=O=A;
        A/=2;
        for(; A>=1; P=A, A/=2){
            if(D[O]-D[A]>=H) break;
            K+=(H-D[O]+D[A]);
            if(A*2==P && T[A*2+1].a.size()){     //A*2+1
                t=lower_bound(T[A*2+1].a.begin(), T[A*2+1].a.end(), D[A]+H-(D[O]-D[A]))-T[A*2+1].a.begin();
                t=min(t, (int)T[A*2+1].a.size()-1);
                if(t<T[A*2+1].a.size() && T[A*2+1].a[t]>=D[A]+H-(D[O]-D[A])) t--;
                if(t>=0){
                    K+=(long long)(t+1)*(D[A]+H-(D[O]-D[A]))-T[A*2+1].s[t];
                }
            }
            else if(A*2+1==P && T[A*2].a.size()){           //A*2
                t=lower_bound(T[A*2].a.begin(), T[A*2].a.end(), D[A]+H-(D[O]-D[A]))-T[A*2].a.begin();
                t=min(t, (int)T[A*2].a.size()-1);
                if(t<T[A*2].a.size() && T[A*2].a[t]>=D[A]+H-(D[O]-D[A])) t--;
                if(t>=0){
                    K+=(long long)(t+1)*(D[A]+H-(D[O]-D[A]))-T[A*2].s[t];
                }
            }
        }
        printf("%I64d\n", K);
    }
    return 0;
}