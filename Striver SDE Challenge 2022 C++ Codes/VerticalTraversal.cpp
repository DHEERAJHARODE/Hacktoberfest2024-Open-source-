vector<vector<int>> verticalTraversal(TreeNode* root) {
        //(node,col,level)
          map < int, map < int, multiset < int >>> nodes;
          queue < pair < TreeNode * , pair < int, int >>> todo;
          todo.push({root,{0,0}}); //initial vertical and level
          while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode * temp = p.first;

            //x -> vertical , y->level
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(temp -> val); //inserting to multiset

            if (temp -> left) todo.push({temp -> left,{x - 1,y + 1}});
            if (temp -> right) todo.push({temp -> right,{x + 1,y + 1}});
          }
        
          vector < vector < int >> ans;
          for (auto p: nodes) {
            vector < int > col;
            for (auto q: p.second) {
              col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
          }
          return ans;
    }