#include <stdio.h>
int cnt[1001][1001],que[1000001][2],head=-1,tail;
char map[1001][1001];
int n,m;
int main(){
    int i,j,a,go[4][2]={1,0,0,1,-1,0,0,-1},print;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",map[i]);
        for(j=0;j<m;j++){
            if(map[i][j]=='E'){
                que[++head][0]=i;
                que[head][1]=j;
                cnt[i][j]=1;
            }
        }
    }
    while(head>=tail){
        i=que[tail][0];
        j=que[tail++][1];
        for(a=0;a<4;a++){
            if(i+go[a][0]>=0 && j+go[a][1]>=0 && i+go[a][0]<n && j+go[a][1]<m && map[i+go[a][0]][j+go[a][1]]!='T' && cnt[i+go[a][0]][j+go[a][1]]==0){
                que[++head][0]=i+go[a][0];
                que[head][1]=j+go[a][1];
                cnt[i+go[a][0]][j+go[a][1]]=cnt[i][j]+1;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(map[i][j]=='S')
                print=cnt[i][j];
        }
    }
    int sum=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(print>=cnt[i][j] && map[i][j]>='0' && map[i][j]<='9' && cnt[i][j]!=0)
                sum+=map[i][j]-'0';
        }
    }
    printf("%d\n",sum);
    return 0;
}