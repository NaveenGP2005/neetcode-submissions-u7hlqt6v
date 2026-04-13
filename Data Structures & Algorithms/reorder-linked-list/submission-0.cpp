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
    void reorderList(ListNode* head) {
        ListNode *curr=head,*last=head;

        while(last->next){
            last=last->next;
        }
        last->next=head;
        while(curr!=last){
            ListNode *next=curr->next,*temp=last;
            curr->next=last;
            last->next=next;
            curr=curr->next->next;
            while(last->next!=temp) last=last->next;
        }

        curr->next=NULL;

    }
};
