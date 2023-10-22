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
    void insertAtTail(Node* &head,Node* &tail,int d){
        Node* new_node=new Node(d);
        if(head==NULL){
            head=new_node;
            tail=head;
            return;
        }
        tail->next=new_node;
        tail=new_node;
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL ){
            return head;
        }
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        Node* temp=head;
        while(temp!=NULL){
            insertAtTail(clonehead,clonetail,temp->val);
            temp=temp->next;
        }
        unordered_map<Node*,Node*> mapping;
        Node* originalnode=head;
        Node* clonenode=clonehead;
        while(originalnode!=NULL){
            mapping[originalnode]=clonenode;
            originalnode=originalnode->next;
            clonenode=clonenode->next;
        }
        originalnode=head;
        clonenode=clonehead;
        while(originalnode!=NULL){
            clonenode->random=mapping[originalnode->random];
            originalnode=originalnode->next;
            clonenode=clonenode->next;
        }
        return clonehead;

    }
};