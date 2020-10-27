static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
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
class Solution {
    
    // check left->root->right (inorder traversal)
    int find(TreeNode* root, int& k) {
        if (root) {
            int x = find(root->left, k);
            
            if(!k)
                return x;
            else{
                if(!--k)
                    return root->val;
                else
                    return find(root->right,k);
            }    
        }
        
        // return !k ? x : !--k ? root->val : find(root->right, k);
        return -1;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return find(root, k);
    }    
};
