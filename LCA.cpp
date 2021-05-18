

// Binary Search Tree

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* node1, TreeNode* node2) {
    TreeNode *temp = root;
    while(temp){
        if(temp==node1 || temp==node2) return temp;
        else if(temp->val > node1->val && temp->val > node2->val) temp = temp->left;
        else if(temp->val < node1->val && temp->val < node2->val) temp = temp->right;
        else return temp;
    }
    return NULL;
}



// Binary Tree

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root==p || root==q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root;
        return left==NULL ? right : left;
    }
