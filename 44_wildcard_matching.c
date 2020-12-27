

bool isMatch(char * s, char * p){
    int i, j;
    int s_len = strlen(s);
    int p_len = strlen(p);
    
    int T[s_len + 1][p_len + 1];
    
    memset(T, 0, sizeof(T));
    
    T[0][0] = 1;
    
    for (j = 1; j <= p_len ; j++)
    {
        if (p[j - 1] == '*')
            T[0][j] = T[0][j - 1];
    }

    for (i = 1; i <= s_len ; i++)
    {
        for (j = 1; j <= p_len; j++)
        {
            if (p[j - 1] == '*')
                T[i][j] = T[i - 1][j] || T[i][j - 1];
            else if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
                T[i][j] = T[i - 1][j - 1];
            else
                T[i][j] = 0;
        }
    }

    return T[s_len][p_len] == 1 ? true : false;
}
