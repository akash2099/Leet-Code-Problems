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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Using Floyd Cycle Detection Algorithm
        ListNode *slow=head;
        ListNode *fast;
        
        if(slow)
            fast=head->next;
        else
            return false;
        
        while(slow||fast){
            if(slow==fast)
                return true;
            if(slow) 
                slow=slow->next; // move 1 step at a time
            
            if(fast){
                if(fast->next)
                    fast=fast->next->next; // move 2 step at a time
                else
                    break;
            }
        }
        
        return false;
        
    }
};
