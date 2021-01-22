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
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* test=head;
        while(test){
            Node* temp=test->next;
            test->next=new Node(test->val);
            test->next->next=temp;
            test=temp;
        }
        
        test=head;
        while(test){
            if(test->random)
                test->next->random=test->random->next;
            test=test->next->next;
        }
        
        test=head;
        Node* dummy= new Node(0);
        Node* main=dummy;
        while(test){
            main->next=test->next;
            main=main->next;
            test->next=test->next->next;
            test=test->next;
        }
        
        return dummy->next;
    }
};
