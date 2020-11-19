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
    int res=INT_MIN;
    int max_value_path(TreeNode* root){
        if(root==nullptr)
            return 0;
        int left=max_value_path(root->left);
        int right=max_value_path(root->right);
        int temp=max(max(left,right)+root->val,root->val); // replace 1 with root->val, a bit change considering negative numbers
        int answer=max(root->val+left+right,temp); // replace 1 with root->val
        if(res<answer)
            res=answer;
        return temp;// passon the elft,right max only when including the root and passing on the root to above
    }
    int maxPathSum(TreeNode* root) {
        if (root==nullptr)
            return 0;
        max_value_path(root);
        return res;
    }
};
