#include <limits.h>

int myAtoi(char * s){
    int i = 0, index = 0;
    int sign = 1, numeric_range;
    int val = 0;
    
    /* check for empty string */
    if (s == NULL || s == "")
        return 0;
    
    /* discard whitespaces in the beginning */
    while(s[i] == ' ')
        i++;
    
    /* Check if optional sign exists */
    if (s[i] == '-' || s[i] == '+')
        sign = (s[i++] == '-') ? - 1 : 1;  
    
    while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
    {
        if ((val > INT_MAX / 10) ||
            ((val == INT_MAX / 10) && (s[i] - '0' > INT_MAX % 10)))
            return (sign == 1) ? INT_MAX : INT_MIN;
        /* valid number */
        val = val * 10 + (s[i++] - '0');
    }
    return val * sign;
}
