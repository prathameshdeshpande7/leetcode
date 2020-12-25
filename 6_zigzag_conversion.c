#include <string.h>
#define MAX 50

char * convert(char * s, int numRows){
    if (numRows == 1) return s;
    int i, j;
    int len = strlen(s);
    int cycle_len = 2*numRows - 2;
    char *result = (char *)malloc(len + 1);
    int index = 0;
    
    for (i = 0; i < numRows; i++)
    {
        for (j = 0; j + i < len; j += cycle_len)
        {
            result[index++] = s[i + j];
            //printf("%d %d %c, result %c\n", i, j, s[i + j], result[index-1]);

            if (i != 0 && i != numRows - 1 && j + cycle_len - i < len)
            {
                result[index++] = s[j + cycle_len - i];
                //printf("%d %d %c, result %c\n", i, j, s[j + cycle_len - i], result[index-1]);
            }

        }
    }
    result[index] = '\0';
    return result;
}
