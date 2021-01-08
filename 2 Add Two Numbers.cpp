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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int curr,carry=0;
        ListNode* dummy=new ListNode();
        ListNode* l3=dummy;
        
        while(l1 && l2){
            int x=l1->val+l2->val+carry;
            // cout<<x<<" ";
            if(x>=10){
                carry=1;
                curr=x%10;
            }
            else{
                curr=x;
                carry=0;              
            }
            
            // cout<<carry<<" ";
            
            l1=l1->next;
            l2=l2->next;
            
            ListNode* temp=new ListNode(curr);
            l3->next=temp;
            l3=l3->next;
        }
        
        while(l1){
            int x=l1->val+carry;
            if(x>=10){
                carry=1;
                curr=x%10;
            }
            else{
                curr=x;
                carry=0;              
            }
    
            l1=l1->next;
            
            ListNode* temp=new ListNode(curr);
            l3->next=temp;
            l3=l3->next;
        }
        
        while(l2){
            int x=l2->val+carry;
            if(x>=10){
                carry=1;
                curr=x%10;
            }
            else{
                curr=x;
                carry=0;              
            }
    
            l2=l2->next;
            
            ListNode* temp=new ListNode(curr);
            l3->next=temp;
            l3=l3->next;
        }
        
        if(carry==1){
            ListNode* temp=new ListNode(1);
            l3->next=temp;
            l3=l3->next;
        }
        
        return dummy->next;
    }
};
