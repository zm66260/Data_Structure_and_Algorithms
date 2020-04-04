
// 92  Reverse a linked list from position m to n. Do it in one-pass.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution {
public:
    ListNode* sucessor = nullptr;
    ListNode* reverseN(ListNode* head, int n){
        if (n==1) {
            sucessor = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = sucessor;
        return last;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m==1){
            return reverseN(head, n);}

        head->next = reverseBetween(head->next, m-1, n-1);
        return head;
    }
};