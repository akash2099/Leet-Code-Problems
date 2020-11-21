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
/*
// Optimized Solution

Hi guys, this is my Java solution. I read this post, which is very helpful.

The basic idea is here:
Say we have 2 arrays, PRE and IN.
Preorder traversing implies that PRE[0] is the root node.
Then we can find this PRE[0] in IN, say it's IN[5].
Now we know that IN[5] is root, so we know that IN[0] - IN[4] is on the left side, IN[6] to the end is on the right side.
Recursively doing this on subarrays, we can build a tree out of it :)

Hope this helps.


I hope this helps those folks who can't figure out how to get the index of the right child:

- Our aim is to find out the index of right child for current node in the preorder array
- We know the index of current node in the preorder array - preStart (or whatever your call it), it's the root of a subtree
- Remember pre order traversal always visit all the node on left branch before going to the right ( root -> left -> ... -> right), therefore, we can get the immediate right child index by skipping all the node on the left branches/subtrees of current node
- The inorder array has this information exactly. Remember when we found the root in "inorder" array we immediately know how many nodes are on the left subtree and how many are on the right subtree
- Therefore the immediate right child index is preStart + numsOnLeft + 1 (remember in preorder traversal array root is always ahead of children nodes but you don't know which one is the left child which one is the right, and this is why we need inorder array)
- numsOnLeft = root - inStart.

public TreeNode buildTree(int[] preorder, int[] inorder) {
    Map<Integer, Integer> inMap = new HashMap<Integer, Integer>();

    for(int i = 0; i < inorder.length; i++) {
        inMap.put(inorder[i], i);
    }

    TreeNode root = buildTree(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1, inMap);
    return root;
}

public TreeNode buildTree(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd, Map<Integer, Integer> inMap) {
    if(preStart > preEnd || inStart > inEnd) return null;

    TreeNode root = new TreeNode(preorder[preStart]);
    int inRoot = inMap.get(root.val);
    int numsLeft = inRoot - inStart;

    root.left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root.right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;
}
*/
class Solution {
public:
    // unordered_map<int,int>mp;
    // int preIndex=0;
    /*
    TreeNode* build_help(vector<int>preorder, vector<int>inorder,int start,int end){
        if(start>end)// important
            return nullptr;
        
        TreeNode* root=new TreeNode(preorder[preIndex++]);
        
        if(root==nullptr)// important
            return nullptr;
        
        if(start==end)// when there is only one element in [start,end] : start==end
            return root;
        
        int index=mp[root->val];
        
        // partitioning left and right according to inorder ranges
        root->left=build_help(preorder,inorder,start,index-1);
        root->right=build_help(preorder,inorder,index+1,end);
        
        return root;
    }
    */
    
//     Last solution TLE
//     TreeNode* buildTree(vector<int> preorder, int preStart, int preEnd,vector<int> inorder, int inStart, int inEnd, unordered_map<int, int> inMap){

//         if(preStart > preEnd || inStart > inEnd) return nullptr;
        
//         TreeNode* root = new TreeNode(preorder[preStart]);
//         if(root==nullptr)// important
//             return nullptr;
        
//         int inRoot = inMap[root->val];
//         // Beautiful implementation
//         int numsLeft = inRoot - inStart;

//         root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
//         root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

//         return root;
//     }
    
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         unordered_map<int,int>mp;
//         for(int i=0;i<inorder.size();++i){
//             mp[inorder[i]]=i;
//         }
//         // return build_help(preorder,inorder,0,inorder.size()-1);// preorder,inorder,start index in inorder,end index in inorder 
//         return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
//     }
// };

    // Try to understand later
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inPos = 0;
        int prePos = 0;
        return build(preorder, inorder, INT_MIN, inPos, prePos);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int stop, int& inPos, int& prePos){
        if(prePos >= preorder.size()) return NULL;
        if(inorder[inPos] == stop) {inPos++; return NULL;}
        TreeNode* node = new TreeNode(preorder[prePos++]);
        node->left = build(preorder, inorder, node->val, inPos, prePos);
        node->right = build(preorder, inorder, stop , inPos, prePos);
        return node;
    }
};
