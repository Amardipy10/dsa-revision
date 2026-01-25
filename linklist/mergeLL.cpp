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