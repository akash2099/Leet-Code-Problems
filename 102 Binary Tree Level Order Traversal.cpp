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
    vector<vector<int>>ans;
    // BFS
    void BFS(queue<TreeNode*> q){
        int level_count=0;
        vector<int>temp;
        while(q.size()!=1){
            TreeNode* root=q.front();
            q.pop();
            if(root==nullptr){// assuming we are using nullptr as special symbol
                ++level_count;
                // cout<<endl;
                q.push(root);
                ans.push_back(temp);
                temp.clear();
            }
            else{
                temp.push_back(root->val);
                // cout<<root->val<<" ";
                if(root->left!=nullptr)
                    q.push(root->left);
                if(root->right!=nullptr)
                    q.push(root->right);
            }

        }
        ans.push_back(temp);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr);// using nullptr as special symbol
        BFS(q);
        return ans;
        // BFS two queue approach
    }
};
