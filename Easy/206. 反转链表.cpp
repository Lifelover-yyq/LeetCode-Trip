/*
反转一个单链表。
首先备份当前节点的下一节点；将当前节点指向前一节点，然后前节点和当前节点分别往后移动。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        auto L = head;//当前节点
        ListNode* P = NULL;//前一节点
        while(L != NULL) {
            ListNode* N = L->next;//备份下一节点
            L->next = P;
            P = L;
            L = N;
        }
        return P;
    }
};
