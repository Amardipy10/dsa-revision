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


//optimal recursive
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(head1==NULL || head2==NULL){
            if(head1==NULL){
            return head2;
        }
            else{
            return head1;
        }
        }
        if(head1->val<=head2->val){
            head1->next=mergeTwoLists(head1->next,head2);
            return head1;
        }
        else{
            head2->next=mergeTwoLists(head1,head2->next);
            return head2;
        }
        
    
    }
};


//brute
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *temp1 = list1;
        ListNode *temp2 = list2;
        ListNode *ans = NULL;
        ListNode *head = NULL;

        while (temp1 != NULL || temp2 != NULL)
        {
            if (temp1->data < temp2->data)
            {
                if (head == NULL)
                {
                    head = ans = temp1;
                }
                else
                {
                    ans->next = temp1;
                    ans = temp1;
                }
            }
            else if (temp1->data > temp2->data)
            {
                if (head == NULL)
                {
                    head = ans = temp2;
                }
                else
                {
                    ans->next = temp2;
                    ans = temp2;
                }
            }
            else if (temp1 != NULL)
            {
                if (head == NULL)
                {
                    head = ans = temp1;
                }
                else
                {
                    ans->next = temp1;
                    ans = temp1;
                }
            }
            else
            {
                if (head == NULL)
                {
                    head = ans = temp2;
                }
                else
                {
                    ans->next = temp2;
                    ans = temp2;
                }
            }
        }
    }
};