#include<bits/stdc++.h>
 
using namespace std;
 
void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct tree_node {
	int data;
	tree_node* left;
	tree_node* right;

	tree_node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

//Method 1
//Level Order Traversal - Store and print
void spiral_traversal_1(tree_node* root) {
	if(root == NULL) cout<<"null";
	queue<tree_node*> q;
	vector<vector<int>> traversal;
	q.push(root);
	while(!q.empty()) {
		vector<int> level;
		int size = q.size();
		while(size--) {
			tree_node* Node = q.front();
			q.pop();
			level.push_back(Node->data);
			if(Node->left != NULL) q.push(Node->left);
			if(Node->right != NULL) q.push(Node->right);
		}
		traversal.push_back(level);
	}
	bool reverse = false;
	for(int i=0; i<traversal.size(); i++) {
		if(reverse) {
			for(int j=traversal[i].size()-1; j>=0; j--) {
				cout<<traversal[i][j]<<" ";
			}
			reverse = false;
		}
		else {
			for(int j=0; j<traversal[i].size(); j++) {
				cout<<traversal[i][j]<<" ";
			}
			reverse = true;
		}
		cout<<endl;
	}
}

//Method 2
//Level Order Traversal - Print directly
void spiral_traversal_2(tree_node* root) {
	if(root == NULL) cout<<"null";
	bool reverse = false;
	queue<tree_node*> q;
	q.push(root);
	while(!q.empty()) {
		stack<int> s;
		int size = q.size();
		while(size--) {
			tree_node* Node = q.front();
			q.pop();
			if(reverse) {
				s.push(Node->data);
			}
			else {
				cout<<Node->data<<" ";
			}
			if(Node->left != NULL) q.push(Node->left);
			if(Node->right != NULL) q.push(Node->right);
		}
		if(reverse) {
			while(!s.empty()) {
				cout<<s.top()<<" ";
				s.pop();
			}
		}
		reverse = !reverse;
		cout<<endl;
	}
}

/*
			1
		   / \
		  2   3
		 / \   \
		4	5   6
*/

int main() {
 
	fastio();

	tree_node* root = new tree_node(1);
	root->left = new tree_node(2);
	root->right = new tree_node(3);
	root->left->left = new tree_node(4);
	root->left->right = new tree_node(5);
 	root->right->right = new tree_node(6);

 	spiral_traversal_1(root);
 	cout<<endl;
 	spiral_traversal_2(root);
	
	return 0;
}