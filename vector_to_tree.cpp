struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to convert a vector into a binary tree
TreeNode* vectorToTree(const vector<int>& vec) {
    if (vec.empty()) return nullptr;

    // Create the root node
    TreeNode* root = new TreeNode(vec[0]);

    // Queue to store tree nodes for level-order linking
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (i < vec.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Assign left child
        if (i < vec.size()) {
            current->left = new TreeNode(vec[i]);
            q.push(current->left);
            i++;
        }

        // Assign right child
        if (i < vec.size()) {
            current->right = new TreeNode(vec[i]);
            q.push(current->right);
            i++;
        }
    }

    return root;
}
