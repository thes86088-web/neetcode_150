/*
question link : https://leetcode.com/problems/two-sum/?envType=problem-list-v2&envId=wtvlw4r5
*/
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  int max = nums[0] ;
  for( int i = 0; i < numsSize ; i++ )
    if( max < nums[i] ) max = nums[i] ;

  int *present = ( int* )calloc( max, sizeof(int) );
  for( int j = 0; j < max ; j++ )
    present[j] = -1;
  
  for( int i = 0; i<numsSize; i++ )
    present[ nums[i] ] = i;

  int *result = malloc(2, sizeof(int) );

  for( int i = 0; i<numsSize; i++ ){
    int currentNum = nums[i] ;
    int otherNum = target - currentNum ;
    if( otherNum != currentNum ) 
      if( present[ otherNums ] != 0 )
        //int *nonEmptyResult = { present[ currentNum ], present[ otherNum ]  } ;
        result = ( int* ){ present[ currentNum ], present[ otherNum ]  } ;
  }

  return result;   
}

/*
approach : 
1. find max in nums[]
2. define present[] such that len(present) = max
3. set all elements in present[] to -1 
4. iterate over nums[] and assign present[nums[i]] = i
5. iterate over present[] and check if other number is available
6. "exactly one solution" -> stop at first pair and return it
7. "may not use the same element twice" -> in step4, skip the element being checked
*/
