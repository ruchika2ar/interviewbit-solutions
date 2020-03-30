/*

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    int carry = 0;
    while (A || B) {
        int sum = carry;
        if (A) {
            sum += A->val;
            A = A->next;
        }
        if (B) {
            sum += B->val;
            B = B->next;
        }
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        carry = sum / 10;
    }
    if (carry == 1) cur->next = new ListNode(1);
    return head->next;
}
