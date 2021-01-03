/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int count_of_nodes = 0, i;
    if (head == NULL)
        return NULL;
    
    struct ListNode *prev = NULL, *p1 = head, *p2 = head;
    
    /* first move the second pointer to a distance of n nodes from the head */
    for (i = 0; i < n && p2 != NULL; i++)
    {
        p2 = p2->next;
        count_of_nodes++;
    }
    
    while (p2 != NULL)
    {
        prev = p1;
        p1 = p1->next;
        p2 = p2->next;
        count_of_nodes++;
    }
    
    if (n > count_of_nodes)
    {
        /* nth node from the end exceeds number of nodes in the list */
        return head;
    }
    
    if (prev != NULL)
    {
        prev->next = p1->next;
        free(p1);
        p1 = NULL;
    }
    else
    {
        /* nth node from the end is the first node */
        struct ListNode *temp = head;
        if (head != NULL)
            head = head->next;
        free(temp);
        temp = NULL;
    }
    
    return head;
}
