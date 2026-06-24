#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
struct da
{
	int val;
	struct da* l;
	struct da* r;
};
struct da* root[1000007];
struct daa
{
	int val;
	struct daa* a[27];
};
struct daa* roott[1000007];
struct da* update(struct da* cur,int l,int r,int index,int val)
{
	struct da* curr;
	curr=(struct da*)malloc(sizeof(struct da));
	if(cur==NULL)
	{
		curr->val=0;
		curr->l=NULL,curr->r=NULL;
	}
	else
	{
		curr->val=cur->val;
		curr->l=cur->l,curr->r=cur->r;
	}
	curr->val=curr->val+val;
	if(l==r&&l==index)
	{
		return curr;
	}
	int mid=(l+r)/2;
	if(index<=mid)
		curr->l=update(curr->l,l,mid,index,val);
	else
		curr->r=update(curr->r,mid+1,r,index,val);
	return curr;
}
int query(struct da* cur,int l,int r,int la,int ra)
{
	if(cur==NULL)
		return 0;
	if(la>ra)
		return 0;
	if(l>ra||r<la)
		return 0;
	if(l>=la&&r<=ra)
		return cur->val;
	int mid=(l+r)/2;
	return query(cur->l,l,mid,la,ra)+query(cur->r,mid+1,r,la,ra);
}
struct daa* insert(struct daa* cur,string &aa,int pos,int val)
{
	struct daa* curr;
	curr=(struct daa*)malloc(sizeof(struct daa));
	if(cur==NULL)
	{
		curr->val=0;
		int i;
		for(i=0;i<26;i++)
			curr->a[i]=NULL;
	}
	else
	{
		curr->val=cur->val;
		int i;
		for(i=0;i<26;i++)
			curr->a[i]=cur->a[i];
	}
	if(pos==aa.size())
	{
		curr->val=val;
		return curr;
	}
	curr->a[aa[pos]-'a']=insert(curr->a[aa[pos]-'a'],aa,pos+1,val);
	return curr;
}
int query(struct daa* cur,string &aa,int pos)
{
	if(cur==NULL)
		return 0;
	if(pos==aa.size())
		return cur->val;
	return query(cur->a[aa[pos]-'a'],aa,pos+1);
}
int main()
{
	//ios_base::sync_with_stdio(0);
	int m;
	scanf("%d",&m);
	int i;
	//cout<<flush;
	//fflush(stdin);
	//fflush(stdout);
	for(i=1;i<=m;i++)
	{
		string aa,bb;
		int aaa;
		cin>>aa;
		if(aa=="set")
		{
			cin>>bb>>aaa;
			int tem=query(roott[i-1],bb,0);
			//printf("%d\n",tem);
			if(!tem)
			{
				root[i]=update(root[i-1],1,(int)1e9,aaa,1);
				roott[i]=insert(roott[i-1],bb,0,aaa);
			}
			else
			{
				root[i]=update(root[i-1],1,(int)1e9,tem,-1);
				root[i]=update(root[i],1,(int)1e9,aaa,1);
				roott[i]=insert(roott[i-1],bb,0,aaa);
			}
		}
		else if(aa=="remove")
		{
			cin>>bb;
			int tem=query(roott[i-1],bb,0);
			if(tem)
			{
				root[i]=update(root[i-1],1,(int)1e9,tem,-1);
				roott[i]=insert(roott[i-1],bb,0,0);
			}
			else
			{
				root[i]=root[i-1];
				roott[i]=roott[i-1];
			}
		}
		else if(aa=="query")
		{
			cin>>bb;
			int tem=query(roott[i-1],bb,0);
			//printf("%d\n",tem);
			if(tem)
			{
				root[i]=root[i-1];
				roott[i]=roott[i-1];
				int ans=query(root[i],1,(int)1e9,1,tem-1);
				printf("%d\n",ans);
				//fflush(stdout);
			}
			else if(!tem)
			{
				printf("-1\n");
				//fflush(stdout);
				root[i]=root[i-1];
				roott[i]=roott[i-1];
			}
		}
		else if(aa=="undo")
		{
			cin>>aaa;
			root[i]=root[i-aaa-1];
			roott[i]=roott[i-aaa-1];
		}
		//cout<<flush;
		//fflush(stdin);
		//fflush(stdout);
	}
	return 0;
}