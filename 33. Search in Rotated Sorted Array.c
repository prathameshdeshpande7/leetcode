/* https://leetcode.com/problems/search-in-rotated-sorted-array/ */

int binary_search(int *nums, int lo, int hi, int x)
{
    int mid;
    
    while (lo <= hi)
    {
        mid = lo + (hi - lo)/2;
        if (nums[mid] == x)
            return mid;            
        else if(nums[mid] < x)
            lo = mid + 1;
        else
            hi = mid - 1;
        
    }
    return -1;
}

int search(int* nums, int numsSize, int target){

    int i = 0, result = -1, lo, hi, mid;
    
    if (nums == NULL || numsSize == 0)
        return result;

    lo = 0;
    hi = numsSize - 1;

    while (lo < hi)
    {
        mid = lo + (hi - lo)/2;
        
        if (nums[mid] > nums[hi])
            lo = mid + 1;
        else
            hi = mid;
    }

    int pivot = lo;
    lo = 0;
    hi = numsSize - 1;
    
    if (target >= nums[pivot] && target <= nums[hi])
        lo = pivot;
    else
        hi = pivot - 1;
    
    result = binary_search(nums, lo, hi, target);
    return result;
}
