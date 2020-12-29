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
    return true;
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
    return prefix;
}
