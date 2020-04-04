// 19 Remove Nth Node From End of List
// Given a linked list, remove the n-th node from the end of list and return its head.

// Example:

// Given linked list: 1->2->3->4->5, and n = 2.

// After removing the second node from the end, the linked list becomes 1->2->3->5.

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = dummy;

        for (int i = 0; i < n+1; i++){
            p = p->next;
        }
        while(p != nullptr){
            p = p->next;
            q = q->next;
        }
        ListNode* pop = q->next;
        q->next = q->next->next;

        ListNode* resethead = dummy->next;

        delete pop;
        delete dummy;

        return resethead;
        
    }
};