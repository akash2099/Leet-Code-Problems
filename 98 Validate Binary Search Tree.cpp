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
    vector<int>v;
    void inorder_traverse(TreeNode* root){
        if(!root)return;
        inorder_traverse(root->left);
        v.push_back(root->val);// process root
        inorder_traverse(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder_traverse(root);
        if(!v.size())
            return true;
        int first=v[0];
        for(int i=1;i<v.size();++i){
            if(first<v[i])
                first=v[i];
            else
                return false;
        }
        return true;
    }
};
