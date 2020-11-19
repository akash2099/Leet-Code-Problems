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
    int res=0;
    int dia(TreeNode* root){
        if(root==nullptr)
            return 0;
        int left=dia(root->left);
        int right=dia(root->right);
        int temp=max(left,right)+1;
        int answer=max(1+left+right,temp);
        if(res<answer)
            res=answer;
        return temp;// passon the elft,right max only when including the root and passing on the root to above
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root==nullptr)
            return 0;
        dia(root);
        return res-1;
    }
};
