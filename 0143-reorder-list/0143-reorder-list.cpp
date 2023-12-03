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
    ListNode* Reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL,* nnext=NULL;
        while(curr!=NULL){
            nnext=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nnext;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second=Reverse(slow->next);
        ListNode* newHead=new ListNode(-1);
        ListNode* newTail=newHead;
        ListNode* first=head;
        slow->next=NULL;
        while(first && second){
            newTail->next=first;
            newTail=newTail->next;
            first=first->next;
            //second part
            newTail->next=second;
            newTail=newTail->next;
            second=second->next;
        }
        while(first!=NULL){
            newTail->next=first;
            first=first->next;
        }
        head=newHead->next;
        
    }
};