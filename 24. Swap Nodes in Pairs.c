/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *ptr;
    
    if (head == NULL)
        return NULL;
    
    ptr = head;
    
    while (ptr != NULL && ptr->next != NULL)
    {
        ptr->val ^= ptr->next->val;
        ptr->next->val ^= ptr->val;
        ptr->val ^= ptr->next->val;
        
        if (ptr->next->next)
            ptr = ptr->next->next;
        else
            break;
    }
    
    return head;
}
