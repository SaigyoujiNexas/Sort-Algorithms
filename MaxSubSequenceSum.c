int maxSubArray(int* nums, int numsSize)
{
    int ThisSum, MaxSum, j;

    ThisSum = 0;
    MaxSum = -2147483647;
    for (j = 0; j < numsSize; j++)
    {
        ThisSum += nums[j];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
         if (ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}
