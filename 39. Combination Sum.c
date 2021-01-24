/* https://leetcode.com/problems/combination-sum/ */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void backTrack(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes,
               int index, int pos, int *current, int **ans)
{
    int i = 0;
    
    if (target == 0)
    {
        ans[*returnSize] = (int *)malloc(sizeof(int) * index);
        (*returnColumnSizes)[*returnSize] = index;
        for (i = 0; i < index; i++)
            ans[*returnSize][i] = current[i];
        (*returnSize)++;
        return;
    }

    for (; pos < candidatesSize; pos++)
    {
        if (candidates[pos] > target)
            break;
        
        current[index] = candidates[pos];
        backTrack(candidates, candidatesSize, target - candidates[pos],
                  returnSize, returnColumnSizes,
                  index + 1, pos, current, ans);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    
    int **ans = (int **)malloc(sizeof(int *) * 256);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 256);
    int *current = (int *)malloc(sizeof(int) * 256);
    
    *returnSize = 0;
    
    backTrack(candidates, candidatesSize, target, returnSize, returnColumnSizes, 0, 0, current, ans);
    free(current);
    return ans;
}
