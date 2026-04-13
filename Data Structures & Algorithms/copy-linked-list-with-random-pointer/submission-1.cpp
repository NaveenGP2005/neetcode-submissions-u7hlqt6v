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
        if(!head) return NULL;
        Node *curr=head;
        while(curr){
            Node *temp=new Node(0);
            temp->val=curr->val;
            temp->next=curr->next;
            curr->next=temp;
            curr=curr->next->next;
        } 
        curr=head;
        while(curr){
            Node *copy=curr->next;
            copy->random=curr->random?curr->random->next:NULL;
            curr=curr->next->next;
        }
        curr=head;
        Node *nhead=curr->next;
        while(curr){
            Node *temp=curr->next;
            curr->next=curr->next->next;
            if(temp->next)
            temp->next=temp->next->next;
            curr=curr->next;
            temp=temp->next;
        }
        return nhead;
    }
};
