class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return head;
        }

        Node* curr = head;

        while (curr != NULL) {
            if (curr->child != NULL) {

                // save next pointer
                Node* next = curr->next;

                // flatten the child list
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                // move to tail of flattened child
                while (curr->next != NULL) {
                    curr = curr->next;
                }

                // connect tail with saved next
                if (next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};