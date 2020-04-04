// 25 reverse nodes in k-group
// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

// Example:

// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

// Note:

// Only constant extra memory is allowed.
// You may not alter the values in the list's nodes, only nodes itself may be changed.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* a = head; 
        ListNode* b = head;
        for(int i = 0; i < k; i++){
            if (b == nullptr){return head;}
            b = b->next;
        }
        ListNode* newhead = reverse(a, b);
        a->next = reverseKGroup(b, k);
        return newhead;
    }

    ListNode* reverse(ListNode* a, ListNode* b){
        ListNode* pre = nullptr;
        ListNode* curr = a;
        ListNode* nxt = a;
        while(curr != b){
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }
        return pre;
    }

};