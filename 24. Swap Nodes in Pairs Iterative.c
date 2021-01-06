/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *first = NULL, *second = NULL, *prev;
    
    if (head == NULL)
        return NULL;
    
    first = head;
    if (first->next != NULL)
    {
        second = first->next;
        head = second;
    }

    while (first->next != NULL)
    {
        first->next = second->next;
        second->next = first;
        prev = first;
        if (first->next)
        {
            first = first->next;
            if (first->next)
            {
                second = first->next;
        
                prev->next = second;
            }
        }
    }
    
    return head;
}
