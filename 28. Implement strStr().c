/* https://leetcode.com/problems/implement-strstr/ */
#include <string.h>

int strStr(char * haystack, char * needle){
    
    int i = 0, j = 0, index = 0;
    if (haystack == NULL || needle == NULL)
        return 0;
    if (needle[0] == '\0')
        return 0;
    
    int h_len = strlen(haystack);
    int n_len = strlen(needle);
    
    if (n_len > h_len)
        return -1;
    
    for (i = 0; i < h_len; i++)
    {
        if (haystack[i] == needle[index])
        {
            if (index == n_len - 1)
            {
                return i - index;
            }
            else
            {
                index++;
            }
        }
        else
        {
            i = i - index;
            index = 0;
        }
    }
    return -1;
}
