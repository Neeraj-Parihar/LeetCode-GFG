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
    ListNode* ReverseLinkedList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nnext = NULL;  
        while (curr != NULL) {
            nnext = curr->next;  
            curr->next = prev;
            prev = curr;
            curr = nnext;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* New = ReverseLinkedList(head);
        int cnt = 1;
        ListNode* curr = New;
        ListNode* prev = NULL;
        while (curr != NULL && cnt != n) { 
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (prev == NULL) {
            New = curr->next;
        } else {
            prev->next = curr->next;
        }
        ListNode* ans = ReverseLinkedList(New);
        return ans;
    }
};
