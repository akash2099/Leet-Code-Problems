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
class Solution {
public:
    unordered_map<TreeNode*,int>mp;
    int rob(TreeNode* root) {
        // base condition
        if(root==nullptr)
            return 0;
        
        // memorization
        if(mp.find(root)!=mp.end())
            return mp[root];
        
        // Logic
        int total=0;
        if(root->left)
            total+=rob(root->left->left)+rob(root->left->right);
        if(root->right)
            total+=rob(root->right->left)+rob(root->right->right);
        
        return mp[root]=max(root->val+total,rob(root->left)+rob(root->right));
        
    }
};
