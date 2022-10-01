class Solution {
public:
    int n_camera;
    
    pair<bool,bool> count_camera(TreeNode *root)
    {
        if(root == NULL)
        {
            return {false,true};
        }
        
        pair<bool,bool> l = count_camera(root -> left);
        pair<bool,bool> r = count_camera(root -> right);
        
        bool has_cam = false;
        bool is_monitored = false;
        
        if(l.first || r.first)
        {
            is_monitored = true;
        }
        
        if(!l.second || !r.second)
        {
            has_cam = true;
            is_monitored = true;
            
            n_camera++;
            
        }
        
        return {has_cam, is_monitored};
    }
    
    int minCameraCover(TreeNode* root) {
        
        n_camera = 0;
        
        
        // first -> has camera
        // second -> is monitored
        pair<bool,bool> temp = count_camera(root);
        
        if(!temp.second) 
        {
            n_camera++;
        }
        
        return n_camera;
    }
};