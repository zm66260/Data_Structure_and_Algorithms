// 23 merge k sorted lists
// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

// Example:

// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6

#include <vector>
#include<queue>
using namespace std;

struct ListNode {
      int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };


struct comp {
    comp() {}
    ~comp() {}
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> que;
        for(auto l : lists){
            while(l){
                que.push(l);
                l = l->next;
            }
        }

        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while(!que.empty()){
            ListNode* node = que.top();
            que.pop();
            curr->next = node;
            curr = curr->next;
        }
        curr->next = nullptr;
        return head->next;
    }
};


// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if(lists.size() == 0){return NULL;}
//         int interval = 1;
//         while(interval <= lists.size()){
//             for(int i = 0; i < lists.size() - interval; i += 2*interval){
//                 lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
//             }
//             interval *= 2;
//         }
//         return lists[0];
//     }

//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
//         if(l1 == nullptr){return l2;}
//         if(l2 == nullptr){return l1;}
//         ListNode* dummy = new ListNode(0);
//         ListNode* curr = dummy;
//         while(l1 != nullptr && l2 != nullptr){
//             if(l1-> val < l2->val){
//                 curr->next = new ListNode(l1->val);
//                 l1 = l1->next;
//             }
//             else{
//                 curr->next = new ListNode(l2->val);   
//                 l2 = l2->next;
//             } 
//             curr = curr->next;             
//         }

//         if(l1 == nullptr){curr->next = l2;}
//         if(l2 == nullptr){curr->next = l1;}

//         return dummy->next;

//     }
// };


