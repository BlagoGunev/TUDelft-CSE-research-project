#include<bits/stdc++.h>



using namespace std;



int storage[40][50010];

int sz[40];

int a[50010];

const int inf = 0x3FFFFFFF;

queue<int> empty_array;



struct node

{

	node *left,*right;

	int cur;

	int array_no;

	bool occupied;



	node()

	{

		left = right = NULL;

		cur = 0;

		array_no = -1;

		occupied = false;

	}

}root;



node* insert(int x, int a)

{

	if(a==1)

	{

		if(x == 1)

			root.occupied = true;

		return &root;

	}

	node* prev = insert(x,a >> 1);

	if(a % 2)

	{

		if(prev->right == NULL)

			prev->right = new node;

		prev = prev->right;

	}

	else

	{

		if(prev->left == NULL)

			prev->left = new node;

		prev = prev->left;

	}

	prev->cur = a;

	if(x == a)

		prev->occupied = true;

	return prev;

}



void dfs(node* a)

{

	if(a->left == NULL && a->right == NULL)

	{

		a->array_no = empty_array.front();

		empty_array.pop();

		sz[a->array_no] = 1;

		storage[a->array_no][0] = a->cur;

		storage[a->array_no][1] = inf;

		return ;

	}

	if(a->left == NULL)

	{

		dfs(a->right);

		a->array_no = empty_array.front();

		empty_array.pop();

		sz[a->array_no] = sz[a->right->array_no];

		storage[a->array_no][0] = a->cur;

		if(a->occupied)

			sz[a->array_no] ++;

		for(int i=1;i<sz[a->array_no];i++)

			storage[a->array_no][i] = storage[a->right->array_no][i-1];

		storage[a->array_no][sz[a->array_no]] = inf;

		empty_array.push(a->right->array_no);

	}

	else if(a->right == NULL)

	{

		dfs(a->left);

		a->array_no = empty_array.front();

		empty_array.pop();

		sz[a->array_no] = sz[a->left->array_no];

		storage[a->array_no][0] = a->cur;

		if(a->occupied)

			sz[a->array_no] ++;

		for(int i=1;i<sz[a->array_no];i++)

			storage[a->array_no][i] = storage[a->left->array_no][i-1];

		storage[a->array_no][sz[a->array_no]] = inf;

		empty_array.push(a->left->array_no);

	}

	else

	{

		dfs(a->left);

		dfs(a->right);

		a->array_no = empty_array.front();

		empty_array.pop();

		sz[a->array_no] = sz[a->left->array_no] + sz[a->right->array_no];

		if(a->occupied)

			sz[a->array_no]++;

		storage[a->array_no][0] = a->cur;

		for(int i=1,l=0,r=0; i<sz[a->array_no]; i++)

		{

			if(storage[a->left->array_no][l] > storage[a->right->array_no][r])

			{

				storage[a->array_no][i] = storage[a->right->array_no][r];

				r++;

			}

			else

			{

				storage[a->array_no][i] = storage[a->left->array_no][l];

				l++;

			}

		}

		storage[a->array_no][sz[a->array_no]] = inf;

		empty_array.push(a->left->array_no);

		empty_array.push(a->right->array_no);

	}

	return ;

}



int n;



int main()

{

	cin >> n;

	root.cur = 1;

	for(int i=0;i<=39;i++)

	{

		empty_array.push(i);

	}

	for(int i=1;i<=n;i++)

	{

		scanf("%d",&a[i]);

		insert(a[i],a[i]);

	}

	dfs(&root);

	for(int i=0;i<sz[root.array_no];i++)

	{

		printf("%d ",storage[root.array_no][i]);

	}

	return 0;

}