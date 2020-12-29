#include <stdlib.h> /* malloc */

#define ALPHABET_SIZE   26

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool is_end_of_word;
};

struct TrieNode *get_node()
{
    int i;
    struct TrieNode* t = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    for (i = 0; i < ALPHABET_SIZE; i++)
        t->children[i] = NULL;
    t->is_end_of_word = false;
    return t;
}

void insert(struct TrieNode *root, char *str)
{
    struct TrieNode *temp = root;
    int index;
    
    while (*str != '\0')
    {
        index = *str - 'a';
        if (!temp->children[index])
            temp->children[index] = get_node();
        str++;
        temp = temp->children[index];
    }
    temp->is_end_of_word = true;
}

int have_children(struct TrieNode *curr)
{
    int i = 0;
    for (i = 0; i < ALPHABET_SIZE; i++)
        if (curr->children[i] != NULL)     /* at least one child */
            return 1;
    return 0;
}

int delete(struct TrieNode **curr, char *str)
{
    /* return if Trie is empty */
    if (*curr == NULL)
        return 0;
    
    if (*str != '\0')
    {
        /* recursively call delete on the nodes */
        if (*curr != NULL && (*curr)->children[*str - 'a'] != NULL &&
            delete(&(*curr)->children[*str - 'a'], str + 1) &&
            (*curr)->is_end_of_word == false)
        {
            if (!have_children(*curr))
            {
                free(*curr);
                (*curr) = NULL;
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    
    /* we have reached the end of the string */
    if (*str == '\0' && (*curr)->is_end_of_word)
    {
        if (!have_children(*curr))
        {
            free(*curr);    /* delete curr node */
            (*curr) = NULL;
            return 1;   /* delete non-leaf parent nodes */
        }
        else
        {
            (*curr)->is_end_of_word = false;    /* mark node as non-leaf node */
            return 0;   /* do not delete parent nodes */
        }
    }
    return 0;
}

bool search(struct TrieNode *root, char *str)
{
    int index;
    struct TrieNode *temp = root;
    
    while (*str != '\0')
    {
        index = *str - 'a';
        if (!temp->children[index])
            return false;
        temp = temp->children[index];
        str++;
    }
    return temp->is_end_of_word;
}

int count_children(struct TrieNode *node, int *index)
{
    int i, count = 0;
    
    for (i = 0; i < ALPHABET_SIZE; i++)
    {
        if (node->children[i] != NULL)
        {
            *index = i;
            count++;
        }
    }
    return count;
}

char *walk_trie(struct TrieNode *root)
{
    int i, index;
    struct TrieNode *temp = root;
    char *prefix = NULL;
    int alloc_count = 0;
    
    while (count_children(temp, &index) == 1 && temp->is_end_of_word == false)
    {
        temp = temp->children[index];
        
        
        if (prefix == NULL)
        {
            prefix = (char *)malloc(1);
            memset(prefix, 0, 1);
        }
        else
        {
            prefix = (char *)realloc(prefix, alloc_count + 1);
        }
        prefix[alloc_count++] = 'a' + index;
    }
    
    prefix = (char *)realloc(prefix, alloc_count + 1);
    prefix[alloc_count] = '\0';
    return prefix;
}

void preorder(struct TrieNode *root, struct TrieNode *curr)
{
    int i;
    if (!curr)
        return;
    
    for (i = 0; i < ALPHABET_SIZE; i++)
    {
        if (curr->children[i] != NULL)
            printf("%c", 'a' + i);
        preorder(root, curr->children[i]);
    }
}

char * longestCommonPrefix(char ** strs, int strsSize){
    int i;
    struct TrieNode *root = NULL;
    
    root = get_node();
    
    for (i = 0; i < strsSize; i++)
    {
        /* insert all the character strings in a Trie */
        insert(root, strs[i]);
    }
    
    char *prefix = NULL;
    prefix = walk_trie(root);
    preorder(root, root);
    
    printf("\n\n");
    printf("Searching %d\n", search(root, "sorting"));
    delete(&root, "sorting");
    preorder(root, root);
    printf("\n\n");
    printf("Searching %d\n", search(root, "sorting"));
    
    return prefix;
}
