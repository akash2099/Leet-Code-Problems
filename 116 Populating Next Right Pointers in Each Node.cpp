static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// Type of level order Binary tree traversal

class Solution {
public:
    vector<vector<int>>ans;
    // BFS
    void BFS(queue<Node*> q){
        // int level_count=0;
        vector<int>temp;
        while(q.size()!=1){
            Node* root=q.front();
            q.pop();
            if(root==nullptr){// assuming we are using nullptr as special symbol
                // ++level_count;
                // cout<<endl;
                q.push(root);
                // ans.push_back(temp);
                // temp.clear();
            }
            else{
                root->next=q.front(); // addition only ...............
                // temp.push_back(root->val);
                // cout<<root->val<<" ";
                if(root->left!=nullptr)
                    q.push(root->left);
                if(root->right!=nullptr)
                    q.push(root->right);
            }

        }
        // ans.push_back(temp);
    }
    
    Node* connect(Node* root) {
        if(root==nullptr)
            return root;
        queue<Node*>q;
        q.push(root);
        q.push(nullptr);// using nullptr as special symbol
        BFS(q);
        return root;
    }
};
