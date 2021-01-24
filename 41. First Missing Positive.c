/* https://leetcode.com/problems/first-missing-positive/ */

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int firstMissingPositive(int* nums, int numsSize){
    int i;
    if (numsSize == 0)
        return 1;
    if (numsSize == 1)
    {
        if (nums[0] > 1 || nums[0] < 0)
            return 1;
        return nums[i] + 1;
    }
    for (i = 0; i < numsSize; i++)
    {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i])
        {
            swap(&nums[i], &(nums[nums[i] - 1]));
        }
    }
    
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return numsSize + 1;
}
