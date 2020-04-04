// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* node = new ListNode(0);
        ListNode* nodehead = node;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                node->next = l1; 
                l1 = l1->next;               
            }
            else{
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        if(l1 == nullptr)            
            node->next = l2;
        
         if(l2 == nullptr)
            node->next = l1;            

        return nodehead->next;     
        }          
    
};