#define MAX(a, b)   ((a) > (b) ? (a) : (b))
int length_of_str(const char *s)
{
    int len = 0;
    while (*s++ != '\0')
        len++;
    return len;
}

int lengthOfLongestSubstring(char * s){
    int map[256] = {-1};
    int max = 0, len = 0;
    int i, j;
    
    len = length_of_str(s);
    
    /* map stores the (current index) + 1 of a character */
    for (i = 0, j = 0; j < len; j++)
    {
        if (map[*s] != -1)
            i = MAX(map[*(s + j)], i);
        
        max = MAX(max, j - i + 1);
        map[*(s + j)] = j + 1;
    }
    return max;
}
