TreeNode* lca(TreeNode* node, TreeNode* p, TreeNode* q) {
           if(node==NULL){
            return NULL;
           }
           TreeNode* l=lca(node->left,p,q);
           TreeNode* r=lca(node->right,p,q);
           if(node==p || node==q){
            return node;
           }
           if(l==NULL){
            if(r==NULL){
                return NULL;
            }
            return r;
           }
           if(r==NULL){
            return l;
           }
           return node;
    }
