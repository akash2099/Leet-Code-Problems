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
    void mergeTreeHelp(TreeNode* t1,TreeNode* t2,TreeNode* &t3){
        if(t1!=nullptr && t2!=nullptr){
            // t3->val=t1->val+t2->val;
            t1->val=t1->val+t2->val;
            t3=t1;
            mergeTreeHelp(t1->left,t2->left,t3->left);
            mergeTreeHelp(t1->right,t2->right,t3->right);
        }
        else if(t1!=nullptr){
            // t3->val=t1->val;
            t3=t1;
            mergeTreeHelp(t1->left,nullptr,t3->left);
            mergeTreeHelp(t1->right,nullptr,t3->right);
        }
        else if(t2!=nullptr){
            // t3->val=t2->val;
            t3=t2;
            mergeTreeHelp(nullptr,t2->left,t3->left);
            mergeTreeHelp(nullptr,t2->right,t3->right);
        }
        else{
            return;
        }
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* t3 = new TreeNode(0);
        if(t1==nullptr && t2==nullptr)
            return nullptr;
        mergeTreeHelp(t1,t2,t3);
        return t3;
    }
};
