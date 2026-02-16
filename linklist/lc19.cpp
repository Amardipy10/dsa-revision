class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int total = 0;
        ListNode* temp = head;

        while(temp != NULL){
            total++;
            temp = temp->next;
        }
        
        if(n == total){
            ListNode* delNode = head;
            head = head->next;
            delete delNode;
            return head;
        }

        int steps = total - n - 1;
        ListNode* temp2 = head;

        for(int i = 0; i < steps; i++){
            temp2 = temp2->next;
        }

        ListNode* delNode = temp2->next;
        temp2->next = temp2->next->next;
        delete delNode;

        return head;
    }
};