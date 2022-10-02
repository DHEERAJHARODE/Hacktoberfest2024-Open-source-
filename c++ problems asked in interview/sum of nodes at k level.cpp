#include <bits/stdc++.h>
using namespace std;


struct Node {

    int data ;
    struct Node* left ;
    struct Node* right ;

    Node ( int val )
    {
        data = val ;
        left = NULL ;
        right = NULL ;
    }
};


int search ( int inorder[] , int start , int end , int curr )
{
    for ( int i= start ; i <=end ; i++ )
    {
        if ( inorder[i] == curr )
        {
            return i ;
        }
    }
    return -1 ;
}

Node* buildTree ( int postorder[] , int inorder[] , int start , int end )
{
    static int indx = end ;

    if ( start > end )
    {
        return NULL ;
    }

    int curr = postorder[indx] ;
    indx -- ;

    Node* node = new Node ( curr );

    if ( start == end )
    {
        return node ;
    }

    int temp = search ( inorder , start , end , curr );

    node -> right = buildTree ( postorder , inorder , temp +1 , end );
    node -> left = buildTree ( postorder , inorder , start , temp - 1 );

    return node ;

}

void postorderPrint ( Node* root )
{
    if ( root == NULL )
    return ;

    postorderPrint (root -> left) ;
    postorderPrint ( root -> right ) ;
    cout << root -> data << " " ;
}


int kLevelSum(Node* node , int k)
{
    int level = 0 ;
    int sum = 0 ;

    queue<Node*> q ;
    q.push( node );
    q.push( NULL ) ;


    while ( !q.empty() )
    {
        Node* nod = q.front() ;
        q.pop() ;

        if ( q.empty() && nod == NULL )
            break ;

        if ( nod == NULL )
        {
            q.push( NULL );
            level ++ ;
            continue ;
        }

        if ( nod->left != NULL )
        {
            q.push( nod ->left );
        }

        if ( nod->right != NULL )
        {
            q.push( nod ->right );
        }

        if ( level == k )
        {
            sum += nod->data ;
        }
    }

    return sum ;
}

int main() {
	// your code goes here

	int postorder[] = { 4 , 2 , 5 , 3 , 1 };
	int inorder[] = { 4 , 2 , 1 , 5 , 3 };

	cout << kLevelSum( buildTree( postorder , inorder , 0 , 4 ) , 1 ) ;

	return 0;
}
