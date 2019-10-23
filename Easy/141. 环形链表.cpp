/*
给定一个链表，判断链表中是否有环。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
*/

//解法一：使用双指针，一快一慢，慢指针一次走一步，快指针一次走两步，若存在环则两指针必相遇
//解法二：使用map来记录走过的节点，若遇到重复节点则说明有环，同时找到了环的入口

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //解法一
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto fast = head;
        auto slow = head;
        if(head == NULL) return false;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
};
