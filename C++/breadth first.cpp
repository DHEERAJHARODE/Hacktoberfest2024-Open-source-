#include<iostream>
using namespace std;
#include<queue>
class tree{
	public:
		int data;
		tree *left;
		tree *right;
		queue<tree *> q;
		void insert(int data);
		void delet(int data);
		tree * selection(tree *s);
		void deletenode(tree *s);
};
tree *root=NULL;
tree * tree::selection(tree *s)
{
	while(s->right!=NULL)
	{
		s=s->right;
	}
	if(s->left!=NULL)
	{
		return s->left;
	}
	else 
	{
		return s;
	}
}
void tree::insert(int data)
{
	tree *temp=new tree();
	temp->data=data;
	temp->right=temp->left=NULL;
	if(root==NULL)
	{
		root=temp;
		q.push(temp);
		return;
	}
	tree *t=q.front();
	queue<tree *> my;
	while(t->left!=NULL && t->right!=NULL)
	{
		my.push(q.front());
		q.pop();
		t=q.front();
	}
	while(!q.empty())
	{
		my.push(q.front());
		q.pop();
	}
	while(!my.empty())
	{
		q.push(my.front());
		my.pop();
	}
	if(t->left==NULL)
	{
		t->left=temp;
		return;
	}
	if(t->right==NULL)
	{
		t->right=temp;
		return;
	}
}
void tree::delet(int data)
{
	tree *t=new tree();
	t=q.front();
	queue<tree *> he;
	if(t->data==data)
	{
		tree *s=selection(root);
		root->data=s->data;
		deletenode(s);
	}
	while(t->left->data!=data&&t->right->data!=data)
	{
		he.push(q.front());
		q.pop();
		t=q.front();
	}
	while(!q.empty())
	{
		he.push(q.front());
		q.pop();
	}
	while(!he.empty())
	{
		q.push(he.front());
		he.pop();
	}
	if(t->left->data==data)
	{
		if(t->left->left==NULL && t->left->right==NULL) //no child
		{
			t->left=NULL;
			return;
		}
		if(t->left->right==NULL)  //as in level order tree, if right exist then left is sure to exist
		{
			t->left=t->left->left;
			return;
		}
		else
		{
			tree *s=selection(t->left);
			t->left->data=s->data;
			deletenode(s);
			return;
		}
	}
	if(t->right->data==data)
	{
			if(t->right->left==NULL && t->right->right==NULL) //no child
		{
			t->right=NULL;
			return;
		}
		if(t->right->right==NULL)  //as in level order tree, if right exist then left is sure to exist
		{
			t->right=t->right->left;
			return;
		}
		else
		{
			tree *s=selection(t->right);
			t->right->data=s->data;
			deletenode(s);
			return;
	    }   
    }
}    
void tree::deletenode(tree *s)
{
	tree *t=root->right; //as we are deleting leaf node of right subtree
	queue<tree *> yours;
	yours.push(q.front());
	q.pop();                                       // it is all done as traversing will start fron right subtree which is thors in queue
	yours.push(q.front());
	q.pop();
	while(t->left!=s&&t->right!=s)
	{
		yours.push(q.front());
		q.pop();
		t=q.front();
	}
	while(!q.empty()) //as if we do not do it then since it if FIFO , it will give wrong result;
	{
		yours.push(q.front());
		q.pop();
	}
	while(!yours.empty())  //this is to make q again full;
	{
		q.push(yours.front());
		yours.pop();
	}
	if(t->right==s)
	{
		t->right=NULL;
		return;
	}
	if(t->left==s)
	{
		t->left=NULL;
		return;
	}
}
int main()
{
	tree t;
	t.insert(5);
	t.insert(4);
	t.delet(4);
}
