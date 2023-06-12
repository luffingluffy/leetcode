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
    ListNode* reverseList(ListNode* head) {
        // Iterative:
        if (head == NULL) return NULL;

        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != NULL) {
            ListNode* next = curr->next;  // store the next node
            curr->next = prev;            // reverse curr node pointer
            prev = curr, curr = next;     // update prev & curr node
        }

        return prev;
    }
};