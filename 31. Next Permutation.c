
void merge(int *nums, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;
    
    int left[n1];
    int right[n2];
    
    for (i = 0; i < n1; i++)
        left[i] = nums[l + i];
    for (j = 0; j < n2; j++)
        right[j] = nums[m + 1 + j];
    
    i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            nums[k] = left[i];
            i++;
        }
        else
        {
            nums[k] = right[j];
            j++;
        }
        k++;
    }
    
    while (i < n1)
    {
        nums[k++] = left[i++];
    }
    while (j < n2)
    {
        nums[k++] = right[j++];
    }
}

void merge_sort(int *nums, int l, int r)
{
    int mid = l + (r - l)/2;
    if (l < r)
    {
        merge_sort(nums, l, mid);
        merge_sort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
}

void nextPermutation(int* nums, int numsSize){
    int i, j, k;
    
    i = numsSize - 1;
    
    /* find longest non-increasing suffix */
    while (i > 0 && nums[i - 1] >= nums[i])
        i--;
    /* now i is at the head of the suffix */
    
    /* we are at the last permutation already */
    if (i == 0)
    {
        /* sort in ascending order */
        merge_sort(nums, 0, numsSize - 1);
        return;
    }
    
    j = numsSize - 1;
    /* let pivot be nums[i - 1] */
    /* find rightmost element that exceeds the pivot */
    while (nums[j] <= nums[i - 1])
        j--;
    
    /* swap elements at pivot(i - 1) and j */
    nums[i - 1] = nums[i - 1] ^ nums[j];
    nums[j] = nums[i - 1] ^ nums[j];
    nums[i - 1] = nums[i - 1] ^ nums[j];
    
    /* reverse elements from the suffix */
    j = numsSize - 1;
    while (i < j)
    {
        nums[i] = nums[i] ^ nums[j];
        nums[j] = nums[i] ^ nums[j];
        nums[i] = nums[i] ^ nums[j];
        i++;
        j--;
    }
}
