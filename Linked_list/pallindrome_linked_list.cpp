// 234 Palindrome Linked List
// Given a singly linked list, determine if it is a palindrome.

// Example 1:

// Input: 1->2
// Output: false
// Example 2:

// Input: 1->2->2->1
// Output: true
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
  };

// 反向遍历链表
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        left = head;
        right = head;
        return traverse(head);
    }

    bool traverse(ListNode* right){
        if(right == nullptr){return true;}
        bool res = traverse(right->next);
        res = res && left->val == right->val;
        left = left->next;
        return res;
    }

private:
    ListNode* left;
    ListNode* right;

};



// class Solution {    
// public:
//     bool isPalindrome(ListNode* head) {
//         if(head == nullptr || head->next == nullptr){return true;}
//         ListNode* slow = head;
//         ListNode* fast = head->next;
//         while(fast != nullptr && fast->next != nullptr){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         if(fast != nullptr)
//             slow = slow->next;

//         cut(head, slow);
//         return isequal(head, reverse(slow));

//     }

//     void cut(ListNode* head, ListNode* slow){
//         while(head->next != slow){
//             head = head->next;
//         }
//         head->next = nullptr;
//     }

//     ListNode* reverse(ListNode* head){
//         if(head->next == nullptr){
//             return head;            
//         }
//         ListNode* newhead = reverse(head->next);
//         head->next->next = head;
//         head->next = nullptr;
//         return newhead;
//     }

//     bool isequal(ListNode* l1, ListNode* l2){
//         while(l1 != nullptr && l2 != nullptr){
//             if (l1->val != l2->val)
//                 return false;
//             l1 = l1->next;
//             l2 = l2->next;
//         }
//         return true;
//     }
// };