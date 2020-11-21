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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)//base condition
            return "X,";
        
        // Postorder
        string left_serialized=serialize(root->left); //left
        string right_serialized=serialize(root->right); //right
        
        //always in postorder
        return to_string(root->val)+","+left_serialized+right_serialized; //value(process)root
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // Queue is used because we need to each node one by one from the beginning of the string
        queue<string>q;
        // split string with respect to ','
        stringstream ss(data.substr(0,data.length()-1));
 
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            q.push(substr);
            // cout<<substr<<" ";
        }
        return deserialize_helper(q);
    }
    TreeNode* deserialize_helper(queue<string>&q) {
        string node_value=q.front();
        q.pop(); // at every step delete the first node from queue by reference
        if(node_value=="X") // base condition
            return NULL;
        
        // Preorder
        // Always in preorder
        TreeNode* newnode=new TreeNode(stoi(node_value)); // root(value)process
        
        newnode->left=deserialize_helper(q); //left
        newnode->right=deserialize_helper(q); //right

        // always in preorder
        return newnode;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
