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
    ListNode* reverse_linklist(ListNode* head){
        // reverse a link list
          ListNode* prevNode = nullptr;

          while (head != nullptr) {
            ListNode* nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
          }

          return prevNode;
        
    }
    
    bool isPalindrome(ListNode* head) {
          ListNode* fast = head;
          ListNode* slow = head;

          while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
          }

          fast = head;
          slow = reverse_linklist(slow);

          while (slow != nullptr) {
            if (slow->val != fast->val) {
              return false;
            }
            slow = slow->next;
            fast = fast->next;
          }

          return true;
    }
};
