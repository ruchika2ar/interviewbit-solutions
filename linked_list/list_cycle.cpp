/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Try solving it using constant additional space.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    if (!A || !A->next) return NULL;
    map<ListNode*, int> m;
    ListNode* cur = A;
    m[cur] = 1;
    while (cur) {
        cur = cur->next;
        if (m.find(cur) == m.end()) m[cur] = 1;
        else return cur;
    }
    return NULL;
}
