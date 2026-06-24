#include <iostream>

#include <map>

#include <vector>

#include <algorithm>

using namespace std;



class dinic{

public:

   struct edge{

      int a,b,c,f,ind;};

   int n,m;

   static const int inf=2000000200;

   vector<edge> list;

   vector<vector<edge*> > adj;

   vector<int> dist;

   vector<int> B;

   int bfs,source,sink;

   void init(int N,int so,int si){

      dist.resize(N+3);

      adj.resize(N+3);

      B.resize(N+3);

      source=so;

      sink=si;

      n=N;

      m=0;}

   void add_edge(int ind,int from,int to, int cap,bool directed){

      edge t;

      list.push_back(t);

      list[m].a=from;

      list[m].b=to;

	  list[m].ind=ind;

      if(directed){   

         list[m].c=cap;

         list[m].f=0;} else {

         list[m].c=2*cap;

         list[m].f=cap;}

      m++;}

   void BFS(){

      B[0]=sink;

      bfs=1;

      for(int i=1;i<=n;i++) dist[i]=inf;

      dist[sink]=0;

      int nd,nd_adj;

      for(int i=0;i<bfs;i++){

         nd=B[i];

         for(int i=0;i<adj[nd].size();i++){

           if(adj[nd][i]->a==nd){

              nd_adj=adj[nd][i]->b;

              if(dist[nd_adj]==inf &&  adj[nd][i]->f>0){

                  B[bfs++]=nd_adj;

                  dist[nd_adj]= dist[nd]+1;}} else {

              nd_adj=adj[nd][i]->a;

              if(dist[nd_adj]==inf && adj[nd][i]->f<adj[nd][i]->c){

                  B[bfs++]=nd_adj;

                  dist[nd_adj]= dist[nd]+1;}}}}}

   long long dfs(int node,long long flow){

      long long ret=0;

      if(node==sink) return flow;

      for(int i=0;i<adj[node].size();i++){

         if(flow==0)break;

         if(adj[node][i]->a==node){

            int nd_adj= adj[node][i]->b;

            if(dist[node]== dist[nd_adj]+1 && adj[node][i]->f<adj[node][i]->c){

               long long f=dfs( nd_adj,min(flow,0ll+adj[node][i]->c-adj[node][i]->f));

               ret+=f;

               adj[node][i]->f+=f;

               flow-=f;}

         } else {

            int nd_adj =adj[node][i]->a;

            if(dist[node]== dist[nd_adj]+1 && adj[node][i]->f>0){

               long long f= dfs(nd_adj,min(flow,0ll+adj[node][i]->f));

               ret+=f;

               adj[node][i]->f-=f;

               flow-=f;}}}

      return ret;}

   long long solve(){

      for(int i=0;i<m;i++){

         adj[list[i].a ].push_back(&list[i]);

         adj[list[i].b ].push_back(&list[i]);}

      long long sol=0;

      while(true){

         BFS();

         if(dist[source] ==inf)break;

		 

         sol+= dfs(source,10000000000000000ll);

		 if(sol>2)break;

	  }

	  return sol;}

};

dinic flow;

int n,m;

int ed[30300];

int ed2[30300];

int we[30300];

int s,t;

bool del[30300];

int smn,sind;

bool vis[1010];

vector<int> adj[1010];

vector<int> cst[1010];

map<pair<int,int>,int> rep;

bool is_way;

void dfs_is(int nd){

	if(nd==t){

		is_way=true;

		return;

	}

	vis[nd]=true;

	for(int i=0;i<adj[nd].size();i++){

		int ch=adj[nd][i];

		int co=cst[nd][i];

		if(vis[ch])continue;

		if(del[co])continue;

		dfs_is(ch);

	}

}

void set_vis(){

	for(int i=1;i<=n;i++)vis[i]=false;

}





int br_ra[500500],br_r=1;

int br_lw[500500];

int br_mn_comp[500500];

int br_comp[500500],br_c=1;

bool br_bri[500500];

bool br_vis[500500];

bool is_non_bri[500500];

bool br_vis2[500500];

void reset(){

    br_r=1;

    br_c=1;

    for(int i=1;i<=n;i++){

        br_mn_comp[i]=100000000;

        br_vis2[i]=false;

        br_ra[i]=0;

        br_lw[i]=0;

        br_comp[i]=0;

        br_vis[i]=false;

    }

    for(int i=0;i<=m;i++){

        br_bri[i]=false;

    }

}



void br_dfs(int nd,int p){

    br_ra[nd]=br_r;

    br_lw[nd]=br_r;

    br_r++;

    for(int i=0;i<adj[nd].size();i++){

        int ch=adj[nd][i];

        int in=cst[nd][i];

        if(ch==p)continue;

		if(del[in])continue;

        if(br_ra[ch]!=0){

            br_lw[nd]=min(br_lw[nd],br_ra[ch]);

        } else {

            br_dfs(ch,nd);

            if(br_lw[ch]>br_ra[nd]){

                br_bri[in]=true;

            }

            br_lw[nd]=min(br_lw[nd],br_lw[ch]);

        }

    }

}

void br_dfs2(int nd){

    br_comp[nd]=br_c;

    br_mn_comp[br_c]=min(br_mn_comp[br_c],nd);

    br_vis[nd]=true;

    for(int i=0;i<adj[nd].size();i++){

        int ch=adj[nd][i];

        int in=cst[nd][i];

        if(br_vis[ch])continue;

        if(br_bri[in])continue;

        br_dfs2(ch);

    }

}



int special1,special2;



bool is_sp(int ind){

	return min(ed[ind],ed2[ind])==special1 &&  max(ed[ind],ed2[ind])==special2; 

}

void dfss(int nd,int mmn,int ind){

	vis[nd]=true;

	if(nd==t){

		smn=mmn;

		sind=ind;

		return;

	}

	for(int i=0;i<adj[nd].size();i++){

		int ch=adj[nd][i];

		int co=cst[nd][i];

		if(del[co])continue;

		if(vis[ch])continue;



		int nxt_mn;

		int nxt_ind;





		if((br_bri[co] &&  !is_non_bri[co]) || (br_bri[co] &&  is_sp(co))){

			if(we[co]<mmn){

				nxt_mn=we[co];

				nxt_ind=co;

			} else {

				nxt_mn=mmn;

				nxt_ind=ind;

			}

		} else {

			nxt_mn=mmn;

			nxt_ind=ind;

		}

		dfss(ch,nxt_mn,nxt_ind);

	}

}



bool test[30300];



int main(){

	scanf("%d %d",&n,&m);

	scanf("%d %d",&s,&t);

	bool is_debug=false;

	for(int i=0;i<m;i++){

		int a,b,c;

		scanf("%d %d %d",&ed[i],&ed2[i],&we[i]);

		if(i==0 && ed2[i]==5){

			is_debug=true;

		}

		rep[make_pair(min(ed[i],ed2[i]),max(ed[i],ed2[i]))]++;

		adj[ed[i]].push_back(ed2[i]);

		cst[ed[i]].push_back(i);



		adj[ed2[i]].push_back(ed[i]);

		cst[ed2[i]].push_back(i);

	}

	for(int i=0;i<m;i++){

		if(rep[make_pair(min(ed[i],ed2[i]),max(ed[i],ed2[i]))]>1){

			is_non_bri[i]=true;

		}

	}

	flow.init(n+3,s,t);

	for(int i=0;i<m;i++){

		if(ed[i]==ed2[i])continue;

		flow.add_edge(i,ed[i],ed2[i],1,false);

	}

	int f=flow.solve();

	if(f>2){

		cout<<-1<<endl;

		return 0;

	}

	if(f==0){

		cout<<0<<endl;

		cout<<0<<endl;

		return 0;

	}

	long long sol=2000000001;

	int ind1=-1,ind2=-1;

	is_debug=false;

	if(f==1){

		if(is_debug){

			cout<<"yes"<<endl;

		}



		int mnn=1<<30;

		int ind=-1;

		

		

		for(int i=0;i<flow.m;i++){

			if(flow.list[i].f!=1){



				if(mnn> we[flow.list[i].ind]){

					is_way=false;



					del[flow.list[i].ind]=true;

					set_vis();

					dfs_is(s);

					del[flow.list[i].ind]=false;

					if(is_way){

						test[flow.list[i].ind]=true;

						continue;



					}

					if(we[flow.list[i].ind]<mnn){

						mnn=we[flow.list[i].ind];

						ind=flow.list[i].ind;

					}

					

				}

			}

		}

		if(ind!=-1){

			sol=mnn;

			ind1=ind;

			ind2=-1;

		}

		if(is_debug){

			cout<<ind<<endl;

		}

	}

	if(is_debug){

		cout<<"end"<<endl;

	}

	for(int i=0;i<flow.m;i++){

		if(flow.list[i].f==1){

			continue;

		}

		if(f==1 && !test[flow.list[i].ind])continue;

		del[flow.list[i].ind]=true;

		int h=flow.list[i].ind;

		special1=-1;

		special2=-2;

		if(rep[make_pair(min(ed[h],ed2[h]),max(ed[h],ed2[h]))]==2){

			special1=min(ed[h],ed2[h]);

			special2=max(ed[h],ed2[h]);

		}

		reset();

		set_vis();

		br_dfs(s,s);

		dfss(s,1<<30,-1);

		del[flow.list[i].ind]=false;

		if(smn+ we[flow.list[i].ind]<sol && sind!=-1){

			sol=smn+ we[flow.list[i].ind];

			ind1=flow.list[i].ind;

			ind2=sind;

		}

	}

	cout<<sol<<endl;

	if(ind2==-1){

		cout<<1<<endl;

		cout<<ind1+1<<endl;

	} else {

		cout<<2<<endl;

		if(ind1>ind2){

			swap(ind1,ind2);

		}

		cout<<ind1+1<<" "<<ind2+1<<endl;

	}

}