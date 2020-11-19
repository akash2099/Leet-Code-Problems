static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
public boolean isSymmetric(TreeNode root) {
    return root==null || isSymmetricHelp(root.left, root.right);
}

private boolean isSymmetricHelp(TreeNode left, TreeNode right){
    if(left==null || right==null)
        return left==right;
    if(left.val!=right.val)
        return false;
    return isSymmetricHelp(left.left, right.right) && isSymmetricHelp(left.right, right.left);
}
*/

class Solution {
public:
    bool isSymmetricHelp(TreeNode* left,TreeNode* right){
        
        if(left==nullptr || right==nullptr)
            return left==right;
        if(left->val!=right->val)
            return false;
        
        return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        return isSymmetricHelp(root->left, root->right);
    }
};
