
// 142 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
struct ListNode {
      int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        bool hascycle = false;

        while (slow != nullptr && fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;            
            if (slow == fast){
                hascycle = true;
                break;
            }
        }

        if(hascycle){
            fast = head;
            while(fast != slow){
                fast = fast->next;
                slow = slow->next;            
            }
            return fast;
        }
        else{
            return nullptr;
        }

      
    }
};