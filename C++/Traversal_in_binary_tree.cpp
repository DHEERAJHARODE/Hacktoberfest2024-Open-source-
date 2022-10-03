//Full BT either 0 or 2 child 
//complete BT (1)all level are completely filled except last
 //(2) the last level has all nodes in left
//perfect BT all leaf nodes are at same level
//Balance BT height of tree at max is log(N) N=num of nodes
//deque BT all node is  left only 

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void preOrder(struct Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node* root){
    if(root==NULL)return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(struct Node* root){
    if(root==NULL)return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void printLevelOrder(Node* root){
    if(root==NULL)return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node =q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

int sumAtK(Node *root , int K){
    if(root==NULL)return -1;
    queue <Node*> q;
    q.push(root);
    q.push(NULL);
    int sum=0;
    int level=0;
    while(!q.empty()){
        Node* node =q.front();
        q.pop();
        if(node!=NULL){
        if(level==K){
            sum+= node->data;
        }
        if(node->left)
        q.push(node->left);
        if(node->right)
        q.push(node->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }

    }
    return sum;
}

int countNodes(Node* root){
    if(root==NULL)return 0;
    return countNodes(root->left)+countNodes(root->right)+1;
}

int SumNodes(Node* root){
    if(root==NULL)return 0;
    return SumNodes(root->left)+SumNodes(root->right)+root->data;
}

int calHeight(Node* root){
    if(root==NULL)return 0;
    return max(calHeight(root->left),calHeight(root->right))+1;
}

int BTdiameter(Node* root,int &res){
    if(root==NULL)return 0;
    int left=BTdiameter(root->left,res);
    int right=BTdiameter(root->right,res);
    int temp=max(left,right)+1;
    int ans = max(temp,left+right+1);
    res=max(res,ans);
    return temp;
     
}

void SumReplace(Node* root){
    if(root==NULL)return;
    SumReplace(root->left);
    SumReplace(root->right);

    if(root->left!=NULL){
        root->data+=root->left->data;
    }
    if(root->right!=NULL){
        root->data+=root->right->data;
    }
    //O(n) time comp.
}

bool isBalanced(Node* root, int* height){
    if(root==NULL)return true;
    int lh=0; int rh=0;
    if(isBalanced(root->left,&lh)==false) return false;
    if(isBalanced(root->right,&rh)==false) return false;

    *height= max(lh,rh)+1;
    if(abs(lh-rh)<=1)
    return true;
    else
    return false;
}

void rightView(Node* root){
    if(root==NULL)return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();

        for(int i=0;i<n;i++){ 
        Node* curr = q.front();
        q.pop();

        if(i==n-1)
        cout<<curr->data<<" ";

        if(curr->left!=NULL){
            q.push(curr->left);
        }

        if(curr->right!=NULL){
            q.push(curr->right);
        }
        }
    }
}

void leftView(Node* root){
    if(root==NULL)return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();

        for(int i=0;i<n;i++){ 
        Node* curr = q.front();
        q.pop();

        if(i==0)
        cout<<curr->data<<" ";

        if(curr->left!=NULL){
            q.push(curr->left);
        }

        if(curr->right!=NULL){
            q.push(curr->right);
        }
        }
    }
}


int main(){
    struct Node* root= new Node(1);
    root->left= new Node(2);
    root->right =new Node(3);
    root->left->left =new Node(4);
    root->left->right = new Node (5);
    root->right->left = new Node (6) ;
    root->right->right = new Node (7) ;

//preOrder(root);
//cout<<endl;

//inOrder(root);
//cout<<endl;

//postOrder(root);

//printLevelOrder(root);

//cout<<sumAtK(root,2);

//cout<<countNodes(root)<<endl;

//cout<<SumNodes(root)<<endl;

//cout<<calHeight(root)<<endl;

/*int res =INT_MIN;
BTdiameter(root,res);
cout<<res;
*/

/*SumReplace(root);
cout<<endl;
preOrder(root);*/

/* int height=0;
if(isBalanced(root,&height)){
    cout<<"true"<<endl;
}
else
cout<<"false";
*/

//rightView(root);
leftView(root);

}