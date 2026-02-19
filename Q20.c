/* Note: The returned array must be malloced, assume caller calls free(). */

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) 
{
    int *result=(int*) malloc(nums1Size* sizeof(int));
    int *used=(int*) calloc(nums2Size,  sizeof(int));
    int k=0;

    int i,j;

    for(i=0; i<nums1Size;i++)
    {
        for(j=0;j<nums2Size; j++)
        {
            if (!used[j] && nums1[i]== nums2[j])
            {
                result[k++]= nums1[i];
                used[j]=1;
                break;  
            }
        } 
    }

    *returnSize= k;
    free(used);

    return result;
}
