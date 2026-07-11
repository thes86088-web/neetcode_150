/*
question link : https://leetcode.com/problems/two-sum/?envType=problem-list-v2&envId=wtvlw4r5
*/


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

  
    
}

/*
approach : 
1. find max in nums[]
2. define present[] such that len(present) = max
3. iterate over nums[] and assign present[nums[i]] = 1
4. iterate over present[] and check if other number is available
5. "exactly one solution" -> stop at first pair and return it
6. "may not use the same element twice" -> in step4, skip the element being checked
*/
