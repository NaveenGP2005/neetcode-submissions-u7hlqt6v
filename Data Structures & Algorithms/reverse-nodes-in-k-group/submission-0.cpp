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
        ListNode *curr=head,*prev=NULL;
        while(curr){
              ListNode *next=curr->next;
              curr->next=prev;
              prev=curr;
              curr=next;
        }
        head=prev;
        return head;
    }

        ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // your counting flow
        int cnt = 0;
        ListNode *curr = head;
        while (curr) {
            curr = curr->next;
            cnt++;
        }
        if (cnt < k) return head;

        curr = head;
        ListNode* prevGroup = NULL;  // last node of previous group

        // your while(curr) flow kept
        while (curr) {
            if (cnt >= k) {
                // move temp k-1 steps ahead from curr
                int n = k - 1;
                ListNode *temp = curr;
                while (n-- && temp) temp = temp->next;

                ListNode* nextGroup = temp->next; // first node of next group
                temp->next = NULL;                // cut current k-group

                // reverse current group using YOUR reverseList
                ListNode* newHead = reverseList(curr);

                // connect previous group to this reversed group
                if (prevGroup)
                    prevGroup->next = newHead;
                else
                    head = newHead;               // first group fixes head

                // curr is now tail of reversed group
                curr->next = nextGroup;

                // move pointers for next iteration
                prevGroup = curr;
                curr = nextGroup;
                cnt -= k;                         // k nodes processed
            } else {
                break;
            }
        }
        return head;
    }
};
