/*
question link : https://leetcode.com/problems/two-sum/?envType=problem-list-v2&envId=wtvlw4r5
*/
#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

  int *present = ( int* )calloc( target+1, sizeof(int) );
  //max -> max+1 to account for max itself since index starts from 0
  for( int j = 0; j < max ; j++ )
    present[j] = -1;
  
  for( int i = 0; i<numsSize; i++ )
    present[ nums[i] ] = i;

  int *result = calloc(*returnSize, sizeof(int) );
  for ( int k=0; k<*returnSize; k++ ) result[k] = -1 ;
  //0->-1 to not confuse the initial value with actual index

  for( int i = 0; i<numsSize; i++ ){
    int currentNum = nums[i] ;
    int otherNum = target - currentNum ;
    if( /*this_line*/otherNum != currentNum && otherNum>=0 ) { 
        //this_line : (-1,-1) if kept, (1,1) if removed
      if( present[ otherNum ] != -1 ) {
        int nonEmptyResult[] = { present[ currentNum ], present[ otherNum ]  } ;
        result = ( int* )nonEmptyResult ;
      }
    }
  }

  return result;   
}

int main(){
    
   int nums[] = {3,3}; int numsSize = ( sizeof(nums) )/( sizeof(*nums) ) ;
   int target = 6;
   int returnSize = 2;
   
   int *resultArr = twoSum( nums, numsSize, target, &returnSize) ;
   printf( "the pair of indices is : (%d, %d)", resultArr[0], resultArr[1] );
    
}
/*
tests :
nums = [2,7,11,15], target = 9 -> [0,1] : pass
nums = [3,2,4], target = 6 -> [1,2] : pass
nums = [3,3], target = 6 -> [0,1] : fail
*/

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
