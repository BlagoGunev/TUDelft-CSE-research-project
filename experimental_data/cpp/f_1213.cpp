#include<bits/stdc++.h>
using namespace std;
bool check[3][200005];
int hello[3][200001];
vector<int> section;
char ans[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    int N,K;cin >> N >> K;
    int hold=0,mem=0;
    for(int i=1;i <= 2;i++) for(int l=1;l <= N;l++) cin >> hello[i][l];
    for(int i=1;i <= N;i++){
        for(int l=1;l <= 2;l++){
            check[l][hello[l][i]]=true;
            if(check[l][hello[l][i]] != check[(l%2)+1][hello[l][i]]) hold++;
            else hold--;
        }
        if(hold == 0){
            mem++;
            section.push_back(i);
        }
    }
    if(mem < K) {
        cout <<"NO";
        return 0;
    }
    cout << "YES\n";
    char Q='a';
    int index=0;
    for(int i=1;i <= N;i++){
        ans[hello[1][i]]=Q;
        if(i == section[index]){
            if(Q != 'z') Q++;
            index++;
        }
    }
    for(int i=1;i <= N;i++) cout << ans[i];
    return 0;
}