#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX(a, b) ( (a) > (b) ? (a) : (b))

int expandAroundCenter(char *s, int left, int right)
{
    int l = left, r = right;
    while (l >= 0 && r < strlen(s) && s[l] == s[r])
    {
        l--;
        r++;
    }
    return r - l - 1;
}

char * longestPalindrome(char * s){
    int i, j, len1, len2, len;
    if (s == NULL || strlen(s) < 1)
        return "";
    int start = 0, end = 0;
    
    for (i = 0; i < strlen(s); i++)
    {
        len1 = expandAroundCenter(s, i, i);
        len2 = expandAroundCenter(s, i, i + 1);
        len = MAX(len1, len2);
        
        if(len > end - start)
        {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    char *buf = (char *)malloc(end - start + 2);
    for (j = 0, i = start; i < end + 1; j++, i++)
    {
        buf[j] = s[i];
    }
    buf[j] = '\0';
    return buf;
}
