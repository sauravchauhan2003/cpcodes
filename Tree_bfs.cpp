void bfs(vector<vector<int>>& ans, queue<TreeNode*> q){
        if(q.empty()){
            return;
        }
        vector<int> v;
        queue<TreeNode*> z;
        while(q.empty()==false){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                continue;
            }
            v.push_back(temp->val);
            z.push(temp->left);
            z.push(temp->right);
        }
        if(v.size()!=0){ans.push_back(v);}
        bfs(ans,z);
    }
