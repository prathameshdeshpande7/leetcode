/* https://leetcode.com/problems/search-insert-position/submissions/ */


int binary_search(int *nums, int low, int high, int target)
{
    int mid;
    
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int searchInsert(int* nums, int numsSize, int target){
    int index;
    int pos = 0;
    
    index = binary_search(nums, 0, numsSize - 1, target);
    return index;
}
