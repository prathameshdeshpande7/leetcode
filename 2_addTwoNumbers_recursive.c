/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *_addTwoNumbers(struct ListNode* l1, struct ListNode* l2, int carry)
{
    struct ListNode *l3;
    
    if (l1 == NULL && l2 == NULL && carry == 0)
        return NULL;
    
    int val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
    l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l3->val = val % 10;
    l3->next = _addTwoNumbers(l1 != NULL ? l1->next : NULL, l2 != NULL ? l2->next : NULL, val / 10); 
    return l3;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0;
    return _addTwoNumbers(l1, l2, carry);
}
