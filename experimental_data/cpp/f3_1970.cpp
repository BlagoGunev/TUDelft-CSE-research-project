#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
map<string,int>Name;
struct stu{
    pair<int,int>pos;
    int v;
    string name;
    bool mv(int dx,int dy){
        pos.first+=dx;pos.second+=dy;
        if(v==1){
            return 1;
        }
        return 0;
    }
}pt[100050];
int n,m;
vector<pair<int,int> >GT[3];
int inv(pair<int,int>pos){
    for(auto it:GT[0])if(it==pos)return 0;
    for(auto it:GT[1])if(it==pos)return 1;
    return -1;
}
int main(){
    int n,m,px=0,py=0;
    cin>>n>>m;
    pt[1000].pos=make_pair(-1,-1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            string s;cin>>s;
            if(s[0]=='R'){
                if(s[1]=='G')GT[0].push_back(make_pair(i,j));
                else{
                    pt[s[1]-'0'+1].pos=make_pair(i,j);
                    Name[s]=s[1]-'0'+1;
                    pt[s[1]-'0'+1].name=s;
                }
            }
            if(s[0]=='B'){
                if(s[1]=='G')GT[1].push_back(make_pair(i,j));
                else {
                    pt[s[1]-'0'+20].pos=make_pair(i,j);
                    Name[s]=s[1]-'0'+20;
                    pt[s[1]-'0'+20].name=s;
                }
            }
            if(s==".Q"){
                pt[100].pos=make_pair(i,j);
                Name[s]=100;
            }
            if(s==".B"){
                pt[1000].pos=make_pair(i,j);
                Name[s]=1000;
            }
            if(s==".S"){
                pt[10000].pos=make_pair(i,j);
                Name[s]=10000;
            }
        }
    }
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        string s;cin>>s;int r=Name[s];
        string mv;
        cin>>mv;
        if(mv=="U"||mv=="D"||mv=="L"||mv=="R"){
            bool op=0;
            if(mv=="U"){
                op=pt[r].mv(-1,0);
            }
            if(mv=="D"){
                op=pt[r].mv(1,0);
            }
            if(mv=="L"){
                op=pt[r].mv(0,-1);
            }
            if(mv=="R"){
                op=pt[r].mv(0,1);
            }
            if(op){
                r=100;
                // cout<<"!";
                if(mv=="U"){
                    op=pt[r].mv(-1,0);
                }
                if(mv=="D"){
                    op=pt[r].mv(1,0);
                }
                if(mv=="L"){
                    op=pt[r].mv(0,-1);
                }
                if(mv=="R"){
                    op=pt[r].mv(0,1);
                }
            }
        }
        if(mv=="C"){
            string kd;cin>>kd;
            if(kd==".Q"){
                pt[r].v=1;
            }
            if(kd==".S"){
                if(s[0]=='B'){
                    cout<<i-1<<" BLUE CATCH GOLDEN SNITCH\n";
                    py+=10;
                }else{
                    cout<<i-1<<" RED CATCH GOLDEN SNITCH\n";
                    px+=10;
                }
                cout<<"FINAL SCORE: "<<px<<" "<<py<<endl;
                return 0;
            }
        }
        if(mv=="T"){
            pt[r].v=0;
            int kk=inv(pt[r].pos);
            if(kk==0){
                cout<<i-1<<" BLUE GOAL\n";
                py++;
            }
            if(kk==1){
                cout<<i-1<<" RED GOAL\n";
                px++;
            }
            if(kk!=-1){
                pt[100].pos=make_pair((n+1)/2,(m+1)/2);
            }
        }
        for(int ip=19;ip<=30;ip++){
            if(pt[ip].v==-1)continue;
            if(pt[ip].pos==pt[1000].pos){
                cout<<i-1<<" "<<pt[ip].name<<" ELIMINATED\n";
                pt[ip].v=-1;
            }
        }
        for(int ip=0;ip<=18;ip++){
            if(pt[ip].v==-1)continue;
            if(pt[ip].pos==pt[1000].pos){
                cout<<i-1<<" "<<pt[ip].name<<" ELIMINATED\n";
                pt[ip].v=-1;
            }
        }
        // cout<<pt[100].pos.first<<","<<pt[100].pos.second<<endl;
    }
    cout<<"FINAL SCORE: "<<px<<" "<<py<<endl;
}