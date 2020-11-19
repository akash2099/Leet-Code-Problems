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
    vector<TreeNode *>v;
    void preorder_traverse(TreeNode* root){
        if(!root)return;
		v.push_back(root);// process root
        preorder_traverse(root->left);
        preorder_traverse(root->right);
    }
    void flatten(TreeNode* root) {
        preorder_traverse(root);
        for(int i=1;i<v.size();++i){
            TreeNode* t=v[i];
            // cout<<t->val<<" ";
            root->left=nullptr;
            root->right=t;
            root=root->right;
        }
    }
};
