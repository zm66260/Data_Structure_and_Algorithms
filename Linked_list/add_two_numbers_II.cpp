
// 445 Add two Numbers II
// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Follow up:
// What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

// Example:

// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7


#include <vector>
#include <cmath>
using namespace std;

struct ListNode {
      int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

// class Solution {
// public:

//     ListNode* addTwoNumberslist(ListNode* l1, ListNode* l2, ListNode* p){
//         if(l1->next == NULL && l2->next == NULL){
//             ListNode* temp = new ListNode(l1->val + l2->val);
//             return temp;
//         }
//         if(l1->next)
//             l1 = l1->next;
//         if(l2->next)
//             l2 = l2->next;
//         p->next = new ListNode(0);        
//         ListNode* value = addTwoNumberslist(l1, l2, p);
//         int unit = value->val % 10;
//         int decade = floor(value->val / 10);
//         p->next->val += unit;
//         p->val += decade;
//         p = p->next;
//         return p;
//     }

//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* p = new ListNode(0);
//         p = addTwoNumberslist(l1, l2, p);  
//         return p;
        
//     }
// };

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        vector<int> s1 = Stack(l1);
        vector<int> s2 = Stack(l2);
        int decade = 0;
        int unit1;
        int unit2;

        while(!s1.empty() || !s2.empty() || decade){
            if(s1.size()!=0){
                unit1=s1.back();
                s1.pop_back();}
            else{
                unit1 = 0;}

            if(s2.size()!=0){
                unit2=s2.back();
                s2.pop_back();}
            else{
                unit2 = 0;}                
            
            // int s1.size()==0? 0 : s1.back();
            // int s2.size()==0? 0 : s2.back();
            int value = (unit1 + unit2 + decade) % 10;
            ListNode* node = new ListNode(value);
            node->next = head->next;
            head->next = node;
            decade = floor((unit1 + unit2 + decade) / 10); 
        }
        ListNode* reshead = head->next;
        delete head;
        return reshead;


    }


private:
    vector<int> Stack(ListNode* l){
        vector<int> s;
        while(l){
            s.emplace_back(l->val);
            l = l->next;
        }
        return s;
        
    }


};