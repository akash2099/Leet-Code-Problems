// #define ppi pair<int,int>
static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Time: O(n)
        if(l1 == nullptr) return l2;
        else if(l2 == nullptr) return l1;
        
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        
        while(l1 != nullptr && l2!= nullptr){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        curr->next = l1 == nullptr? l2:l1;
        return dummy->next;
    }
};
