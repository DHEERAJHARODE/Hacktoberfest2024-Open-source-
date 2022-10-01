Skip to content
Search or jump to…
Pull requests
Issues
Marketplace
Explore
 
@AkashMarkad 
AkashMarkad
/
Striver-SDE-Sheet
Public
Code
Issues
Pull requests
Actions
Projects
Wiki
Security
Insights
Settings
Striver-SDE-Sheet/Day 21 : Binary Search Tree Part-II/BST Iterator.java /
@AkashMarkad
AkashMarkad Create BST Iterator.java
Latest commit 2b5d7f5 5 hours ago
 History
 1 contributor
51 lines (42 sloc)  1.13 KB

// BST Iterator 

// BST Iterator Returns data in incresing order
// It has following functions: 1) hsNext(), 2) next(), 3) pushAll(), 4) Constructor

// Code:

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class BSTIterator {

    private Stack<TreeNode> st = new Stack<>();

    public BSTIterator(TreeNode root) {
        pushAll(root);
    }
    
    public int next() {
        TreeNode temp = st.pop();
        pushAll(temp.right);
        return temp.val;
    }
    
    public boolean hasNext() {
        return !st.isEmpty();
    }

    private void pushAll(TreeNode node){
        for(; node != null ; st.push(node) , node = node.left);
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
Footer
© 2022 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
Striver-SDE-Sheet/BST Iterator.java at main · AkashMarkad/Striver-SDE-Sheet
