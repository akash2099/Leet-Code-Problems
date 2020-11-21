static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int pathSum(TreeNode* root, int sum) { // CASE 1: don't include the current node value
        if(!root) return NULL; // root==NULL
        return sumUp(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum); // traverse the whole tree wth root as the starting node
    }
private:
    int sumUp(TreeNode* root, int sum){ // CASE 2: include the current node's value
        if(!root) return NULL; // root==NULL
        int res=0;
        if(root->val==sum) // su
            ++res;
        res+=sumUp(root->left,sum-root->val);
        res+=sumUp(root->right,sum-root->val);
        
        return res;
    }
};
