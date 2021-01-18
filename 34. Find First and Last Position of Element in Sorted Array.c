/* 34. Find First and Last Position of Element in Sorted Array
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int binary_search(int *nums, int lo, int hi, int target, bool dir)
{
    int mid;
    int index = -1;
    
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
        {
            index = mid;
            if (dir == true)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        else if (nums[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return index;
}

void fill_result(int *result, int *returnSize, int start_index, int end_index)
{
    *result = start_index;
    *(result + 1) = end_index;
    *returnSize = 2;
}

int rec_binary(int *nums, int lo, int hi, int target)
{
    int mid;
    if (lo <= hi)
    {
        mid = lo + (hi - lo ) / 2;
        
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            return rec_binary(nums, mid + 1, hi, target);
        return rec_binary(nums, lo, mid - 1, target);
    }
    return -1;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int left, right, start_index = 0, end_index = 0, pivot = 0;
    int *result;
 
    result = (int *)malloc(2 * sizeof(int));
    if (result == NULL)
        return NULL;
    
    if (nums == NULL || numsSize == 0)
    {
        fill_result(result, returnSize, -1, -1);
        return result;
    }
    
    left = 0;
    right = numsSize - 1;
    
    /* search left */
    start_index = binary_search(nums, left, right, target, true);
    
    /* search right */
    end_index = binary_search(nums, left, right, target, false);
    
    fill_result(result, returnSize, start_index, end_index);
    return result;
}
