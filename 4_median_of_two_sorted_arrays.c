#include <limits.h>
#define MAX(a, b)   ((a) > (b) ? (a) : (b))
#define MIN(a, b)   ((a) < (b) ? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    /* Idea is to divide the two arrays into two halves such that
     * all elements in the left half of both arrays would be
     * less than or equal to all elements in the right half of both arrays.
     * If we find such a partition we can then compute the median based on the
     * values around the partition.
     *
     * < -2- >   < --4-- >
     * x1 x2  | x3 x4 x5 x6
     * < -----5------> < --3-->
     * y1 y2 y3 y4 y5 | y6 y7 y8
     *
     * x2 <= y6 && y5 <= x3 found our partition such that all left elements
     *                      are smaller than all right elements
     *
     */
    if (nums1Size > nums2Size)
    {
        /* call findMedianSortedArrays function on array having lesser number of elements */
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int start, end;
    int partition_nums1 = 0;
    int partition_nums2 = 0;
    int maxleft1, maxleft2, minright1, minright2;
    double median = 0.0;
    
    start = 0;
    end = nums1Size;
    
    /* do a binary search for finding the partition 
     * our formula is partition_nums1 + partition_nums2 = (nums1Size + nums2Size +1)/2
     */
    while (start <= end)
    {
        partition_nums1 = (start + end)/2;
        partition_nums2 = (nums1Size + nums2Size + 1)/2 - partition_nums1;
        
        maxleft1 = (partition_nums1 == 0) ? INT_MIN : nums1[partition_nums1 - 1];
        maxleft2 = (partition_nums2 == 0) ? INT_MIN : nums2[partition_nums2 - 1];
        
        minright1 = (partition_nums1 == nums1Size) ? INT_MAX : nums1[partition_nums1];
        minright2 = (partition_nums2 == nums2Size) ? INT_MAX : nums2[partition_nums2];
        //printf("Partition nums1 %d, nums2 %d\n", partition_nums1, partition_nums2);
        //printf("%d, %d, %d, %d\n", maxleft1, maxleft2, minright1, minright2);
        if (maxleft1 <= minright2 && maxleft2 <= minright1)
        {
            /* compute median */
            if ((nums1Size + nums2Size) % 2 == 0)
            {
                /* even number of total elements */
                median = (MAX(maxleft1, maxleft2) + MIN(minright1, minright2)) / 2.0; 
            }
            else
            {
                /* odd number of total elements */
                median = MAX(maxleft1, maxleft2);
            }
            break;
        }
        else if (maxleft1 <= minright2 && maxleft2 > minright1)
        {
            /* we are far too left, slide right */
            start = partition_nums1 + 1;
        }
        else
        {
            /* we are far too right, slide left */
            end = partition_nums1 - 1;
        }
    }
    //printf("Median %f", median);
    return median;
}
