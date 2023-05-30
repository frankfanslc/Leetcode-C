#include <stdio.h>
#include <string.h>

#define MAX_SIZE 16

int pathSum(int* nums, int numsSize) {
    int dp[MAX_SIZE];
    memset(dp, 0, sizeof(dp));
    int result = 0;
    
    for (int i = numsSize - 1; i >= 0; i--) {
        int depth = nums[i] / 100 - 1;
        int pos = (nums[i] % 100) / 10 - 1;
        int value = nums[i] % 10;
        
        int index = (1 << depth) - 1 + pos;
        dp[index] = dp[2 * index + 1] + dp[2 * index + 2] + value;
        
        if (depth == 0 || (dp[2 * index + 1] == 0 && dp[2 * index + 2] == 0)) {
            result += dp[index];
        }
    }
    
    return result;
}

void testPathSum() {
    // Test Case 1
    int nums1[] = {113, 215, 221};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int result1 = pathSum(nums1, numsSize1);
    printf("Test Case 1: %d\n", result1);
    
    // Test Case 2
    int nums2[] = {113, 221};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int result2 = pathSum(nums2, numsSize2);
    printf("Test Case 2: %d\n", result2);
}

int main() {
    testPathSum();
    return 0;
}

