#include<cstdio>

#include<cstring>

#include<cstdlib>

#include<cmath>

#include<algorithm>

#include<vector>

#define kind 27



using namespace std;





typedef pair<int,int> PA;

typedef pair<int,PA> TA;



const int MAXN = 600007;

typedef struct node

{

    unsigned short cnt; //是否为单词最后一个节点

    int nxt[kind];//Trie每个节点的26个子节点

    int fail; //失败指针

    int f2;

    vector<int> v;

    vector<TA> u;

}ND;

int q[MAXN]; //队列，采用bfs 构造失败指针

char keyword[MAXN];//输入单词 模式串

char str[MAXN];// 需要查找的 主串

int head,tail;//队列 头尾指针

int root,tot;

int d[MAXN];



ND e[MAXN];



int KK=0;



int ins(char *word, int id, int root)

{

     int index,len;

     int p = root, newnode;

     len = strlen(word);

     for(int i=0 ;i < len ; i++ )

     {

         index=word[i]-'a';

         if(!e[p].nxt[index])//该字符节点不存在，加入Trie树中

         {

           // 初始化 newnode 并 加入 Trie 树

            newnode=++tot;

            for(int j=0;j<kind;j++) e[newnode].nxt[j]=0;

            e[newnode].cnt=0;

            e[newnode].fail=0;

            e[newnode].f2=0;

            e[newnode].v.clear();

            e[newnode].u.clear();

            e[p].nxt[index]=newnode;

         }

         p=e[p].nxt[index];//指针移动至下一层

     }

     e[p].cnt++;  //单词结尾 节点 cntnt + 1 做标记

     e[p].v.push_back(id);

     return p;

}



void build_ac_automation(int root)

{

     head=0;tail=1;

     q[head]=root;

     int temp, p,ccnt=0;

     while(head<tail)//bfs构造 Trie树的失败指针

     {

       //算法类似 kmp ，这里相当于得到 nxt[]数组

       //重点在于，匹配失败时，由fail指针回溯到正确的位置



        temp=q[head++];

        if (head>100000) {

            int iii=1;

        }

         for(int i=0;i< kind ;i ++)

         {

             if(e[temp].nxt[i])//判断实际存在的节点

             {

                 // root 下的第一层 节点 都 失败指针都 指向root

                 if(temp==root) e[e[temp].nxt[i]].fail=root,e[e[temp].nxt[i]].f2=root;

                 else {

                    //依次回溯 该节点的父节点的失败指针

                   //知道某节点的nxt[i]与该节点相同，则

                   //把该节点的失败指针指向该nxt[i]节点

                   //若回溯到 root 都没有找到，则该节点

                   //的失败指针 指向 root



                    p=e[temp].fail;//temp 为节点的父指针

                    while(p){

                            ++ccnt;

                            if (ccnt>MAXN) {

                                int iii=1;

                            }

                       if(e[p].nxt[i]){

                       e[e[temp].nxt[i]].fail=e[p].nxt[i];

                       break;

                       }

                       p=e[p].fail;

                    }

                    if(!p)e[e[temp].nxt[i]].fail=root;

                    p=e[temp].fail;//temp 为节点的父指针

                    while(p){

                            ++ccnt;

                            if (ccnt>MAXN) {

                                int iii=1;

                            }

                       if(e[p].nxt[i]&&(e[e[p].nxt[i]].cnt>0||e[e[p].nxt[i]].f2>0)){

                        if (e[e[p].nxt[i]].cnt>0) e[e[temp].nxt[i]].f2=e[p].nxt[i];

                        else e[e[temp].nxt[i]].f2=e[e[p].nxt[i]].f2;

                        break;

                       }

                       p=e[p].fail;

                    }

                    if(!p)e[e[temp].nxt[i]].f2=root;

                 }

                 //每处理一个点，就把它的所有儿子加入队列，

                 //直到队列为空

                 q[tail++]=e[temp].nxt[i];

             }

         }

     }

}

int query(int root)//类似于 kmp算法。

{//i为主串指针，p为匹配串指针

    int i,cnt=0,index,len=strlen(str);

    int p=root;

    for(i=0; i < len ;i ++)

    {

       index=str[i]-'a';

      //由失败指针回溯寻找，判断str[i]是否存在于Trie树种

       while(p&&!e[p].nxt[index] && p != root)p=e[p].fail;

       p=e[p].nxt[index];//找到后 p 指向该节点



       //指针回为空，则没有找到与之匹配的字符



       if(!p)p=root;//指针重新回到根节点root，下次从root开始搜索Trie树



       int temp=p;//匹配该节点后，沿其失败指针回溯，判断其他节点是否匹配



       while(temp && temp != root )//匹配 结束控制

       {

           if(e[temp].cnt>=0)//判断 该节点是否被访问

           {

              //统计出现的单词个数cnt，由于节点不是单词结尾时cntnt为0，

             //故 cnt+=temp->cntnt; 只有 cntnt >0时才真正统计了单词个数

             cnt+=e[temp].cnt;

             if (e[temp].u.size()) {

                TA xx=e[temp].u[e[temp].u.size()-1];

                 if (xx.first+xx.second.first==i) ++e[temp].u[e[temp].u.size()-1].second.first;

                 else {

                    e[temp].u.push_back(TA(i,PA(1,xx.second.second+xx.second.first)));

                 }

             } else e[temp].u.push_back(TA(i,PA(1,0)));

              //temp->cntnt=-1; //标记已访问

           }

           else break;//节点已访问，退出循环

           temp=e[temp].f2;//回溯失败指针继续寻找下一个满足条件的节点

       }

    }

    return cnt;

}



int L[MAXN],R[MAXN];



int main()

{

    int i,t,n,m,ans,j;

    //scanf("%d",&t);

    t=1;

//    memset(keyword,'d',66666);

//    keyword[66666]='\0';

    while(t--)

    {

       root=tot=1;

       for(int j=0;j<kind;j++) e[root].nxt[j]=0;

       e[root].fail=0;

       e[root].cnt=0;

       scanf("%d%d",&n,&m);

//        n=3; m=200000;

       j=0;

       for(i=1;i<=n;i++)

       {

           scanf("%s",keyword);

           strcpy(str+j,keyword);

           L[i]=j;

           j+=strlen(keyword);

           str[j++]='a'+kind-1;

           R[i]=j;

           d[i]=ins(keyword,i,root);

       }

       str[j]='\0';

       build_ac_automation(root);

       ans=query(root);

       //printf("%d\n",ans);

       for (int i=0;i<m;++i) {

            int l, r, c;

            scanf("%d%d%d",&l,&r,&c);

//            l=1;

//            r=3;

//            c=1;

            int tm=d[c];

            l=L[l];

            r=R[r];

            vector<TA>::iterator tr=lower_bound(e[tm].u.begin(),e[tm].u.end(),TA(r,PA(0,0)));

            vector<TA>::iterator tl=lower_bound(e[tm].u.begin(),e[tm].u.end(),TA(l,PA(0,0)));

//            for (int ll=0;ll<e[tm].u.size();++ll) {

//                printf("%d %d %d | ",e[tm].u[ll].first,e[tm].u[ll].second.first,e[tm].u[ll].second.second);

//            }

//            printf("\n");

            if (tr!=e[tm].u.begin()&&e[tm].u.size()) {

                if ((tr-1)->first+(tr-1)->second.first>r) r=(tr-1)->second.second+r-(tr-1)->first;

                else r=(tr-1)->second.second+(tr-1)->second.first;

            } else r=0;

            if (tl!=e[tm].u.begin()) {

                if ((tl-1)->first+(tl-1)->second.first>l) l=(tl-1)->second.second+l-(tl-1)->first;

                else if (tl!=e[tm].u.end()) l=tl->second.second; else l=(tl-1)->second.first+(tl-1)->second.second;

            } else l=0;

            int re=r-l;

            printf("%d\n",re);

       }

    }

    return 0;

}