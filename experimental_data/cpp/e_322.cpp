#include<stdio.h>

int n, ecn, endp[222222], prv[222222], top[111111], chk[222222], deg[111111]; // 2i <-> 2i+1
int lea[111111][27], dp[111111], ma[111111][2], mx; // 0 : ����, 1 : �Ұ���
int pq[111111], fr, rr;

void edge(int s, int e){
	endp[ecn]=e, prv[ecn]=top[s], top[s]=ecn++;
}

int main(){
	int i, a, j, t, b;
	scanf("%d", &n);
	for(i=0; i<n; i++)top[i]=-1, lea[i][0]=2;
	for(i=0; i<n-1; i++){
		scanf("%d%d", &a, &b), a--, b--;
		deg[a]++, deg[b]++;
		edge(a,b), edge(b,a);
	}
	for(i=0; i<n; i++){
		if(deg[i]==1)pq[rr++]=i;
	}
	while(fr<rr){
		i=pq[fr++];
		if(lea[i][0]>=2)lea[i][0]-=2;
		for(a=0; a<26; a++){
			if(lea[i][a]==0)break;
		}
		if(ma[i][1]>=2)a=1+ma[i][0];
		if(a>=26){
			puts("Impossible!");
			return 0;
		}
		dp[i]=a, lea[i][a]=1;
		if(mx<a)mx=a;
		if(a>ma[i][0])ma[i][0]=a, ma[i][1]=1;
		else if(a==ma[i][0])ma[i][1]++;
		for(t=top[i]; t>=0; t=prv[t]){
			if(!chk[t])break;
		}
		if(t>=0){
			b=endp[t];
			chk[t]=chk[t^1]=1, deg[i]--, deg[b]--;
			if(deg[b]==1)pq[rr++]=b;
			for(j=a; j<26; j++){
				if(lea[i][j])lea[b][j]|=1;
			}
			if(ma[b][0]<ma[i][0])ma[b][0]=ma[i][0], ma[b][1]=1;
			else if(ma[b][0]==ma[i][0])ma[b][1]++;
		}
	}
	for(i=0; i<n; i++)printf("%c ", 'A'+mx-dp[i]);
	return 0;
}