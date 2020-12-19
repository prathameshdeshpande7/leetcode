#include <stdlib.h>
typedef struct node
{
    int key;
    int val;
    struct node *next;
} node;

typedef struct table
{
    int size;
    struct node **list;
} table;

struct table *create_table(int size)
{
    int i;
    
    struct table *t = (struct table *)malloc(sizeof(struct table));
    t->list = (struct node **)malloc(size * sizeof(struct node *));
    
    for (i = 0; i < size; i++)
    {
        t->list[i] = NULL;
    }
    t->size = size;
    return t;
}

int hashcode(struct table *t, int key)
{
    if (key < 0)
        return -(key % t->size);
    return (key % t->size);
}

void insert(struct table *t, int key, int val)
{
    int pos = hashcode(t, key);
    struct node *temp = t->list[pos];
    while (temp)
    {
        if (temp->key == key)
        {
            temp->val = val;
            return;
        }
        temp = temp->next;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->key = key;
    newnode->val = val;
    newnode->next = t->list[pos];
    t->list[pos] = newnode;
}

int lookup(struct table *t, int key)
{
    int pos = hashcode(t, key);
    struct node *temp = t->list[pos];
    while (temp)
    {
        if (temp->key == key)
        {
            return temp->val;
        }
        temp = temp->next;
    }
    return -1;
}

void print_hash(struct table *t)
{
    int i;
    struct node *temp;
    printf("Size of table: %d\n", t->size);
    for (i = 0; i < t->size; i++)
    {
        printf("Nodes at pos: %d\n", i);
        temp = t->list[i];
        while (temp)
        {
            printf("Node, key %d, val %d\n", temp->key, temp->val);
            temp = temp->next;
        }
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, index;
    int *result;// = (int *)malloc(2 * sizeof(int));
    
    struct table *t = create_table(numsSize);
    
    for (i = 0; i < numsSize; i++)
    {
        insert(t, nums[i], i);
    }
    print_hash(t);
    for (i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];
        index = lookup(t, complement);
        if (index != -1 && index != i)
        {
            *returnSize = 2;
            result = (int *)malloc(2 * sizeof(int));
            result[0] = index;
            result[1] = i;
            return result;
        }
    }
    return NULL;
}
