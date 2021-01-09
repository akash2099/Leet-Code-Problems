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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp1=head;
        ListNode* temp2;
        
        int total=0;
        while(temp1){
            temp1=temp1->next;
            ++total;    
        }
        
        n=total-n-1; //(total-n+1) -1 -1 = 5-2+1-1-1
        cout<<n;
        temp1=head;
        
        if(n!=-1){

            while(n--){
                temp1=temp1->next;
            }

            if(temp1->next && temp1->next->next)
                temp2=temp1->next->next;
            else
                temp2=nullptr;

            temp1->next=temp2;
        }
        else{
            head=head->next; // for the start node
        }
        
        return head;
    }
};
