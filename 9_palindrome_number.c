bool isPalindrome(int x){
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int reversed_number = 0;
    while (x > reversed_number)
    {
        reversed_number = reversed_number * 10 + x % 10;
        x /= 10;
    }
    
    return x == reversed_number || x == reversed_number / 10;
}
