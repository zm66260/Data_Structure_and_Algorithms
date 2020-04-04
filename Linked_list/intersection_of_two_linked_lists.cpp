// 160 Intersection of Two Linked Lists
// Write a program to find the node at which the intersection of two singly linked lists begins.

struct ListNode {
      int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA;
        ListNode* pb = headB;
        while( pa != pb ){
           pa = pa == nullptr? headB : pa->next;
           pb = pb == nullptr? headA : pb->next;
        }
        return pa;
        
    }
};
