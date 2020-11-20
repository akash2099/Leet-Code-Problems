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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lcs(TreeNode* root, TreeNode* n1, TreeNode* n2){
        if(root==nullptr) // nullptr
            return nullptr;
        if(root==n1 || root==n2) // if any one of the element found then return that
            return root;
        
        // Post order approach
        TreeNode* left=lcs(root->left,n1,n2); // left
        TreeNode* right=lcs(root->right,n1,n2); // right
        // process root
        if(left!=nullptr && right!=nullptr) // both not nullptr
            return root;
        if(left==nullptr && right==nullptr) // both nullptr
            return nullptr;
        
        return left!=nullptr?left:right; // atleast one is not nullptr
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lcs(root,p,q);
    }
};
