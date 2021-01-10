/* https://leetcode.com/problems/divide-two-integers/ */

int divide(int dividend, int divisor){
    int i, sign = 1;
    long long m = dividend, n = divisor;
    long long t = 0, q = 0;
    
    sign = (m < 0 ^ n < 0) ? -1 : 1;
    
    if (dividend > INT_MAX || dividend < INT_MIN)
        return INT_MAX;
    
    n = llabs(divisor);
    m = llabs(dividend);

    if (divisor == 0)
        return INT_MAX;
    
    for (i = 31; i >= 0; i--)
    {
        if (t + (n << i) <= m)
        {
            t += (n << i);
            q += (1ll << i);
        }
    }
    
    if (sign == -1)
        q = -q;
    
    return q > INT_MAX || q < INT_MIN ? INT_MAX : q;
}
