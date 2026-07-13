/*
question link : http://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=problem-list-v2&envId=we37i0vg
*/


#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s) {
    int visited[256] = {0};
    int stringLength = ( sizeof(s) )/( sizeof(char) );
    //add print statements to check values stored in variables
    printf( "stringLength : %d \n", stringLength );
    int maxStart = 0, maxEnd = 0;
    int start = 0, end = start;
    
    for( int i=0; i<stringLength; i++ ){
        if( visited[ s[i] ] == 0 ){
            end = end + 1;
            visited[ s[i] ] = 1; 
        }
        else{
            //end = end - 1;
            if( end - start > maxEnd - maxStart ) {
                maxStart = start;
                maxEnd = end - 1 ;
                //recording "end" disrectly produces differece of one unit
                //record the attributes of current maximum before resetting
            }
            start = i;
            end = i;
            //for( int clear = 0; clear<256; clear ++  ){ visited[clear] = 0; }
        }
        printf( " i = %d, start = %d, end = %d \n", i, start, end );
        //printf( " i = %d, maxStart = %d, maxEnd = %d \n", i, maxStart, maxEnd );
    }
    if( end - start > maxEnd - maxStart ) {
        maxStart = start;
        maxEnd = end ;
    }
    int maxLen = maxEnd-maxStart + 1;
    
    char* result = (char*)calloc( maxLen , sizeof(char) );
    result = s+maxStart;
    
    //slicing using array 
    //enum{ maxLen = maxEnd-maxStart };
    //char result[maxLen] = s + maxStart;
    
    printf( " %d -> %s -> %d\n", maxStart, result, maxEnd ) ;
    //prints whole string instead of required slice 
    return maxLen ;
}

int main(){
    char *s = "pwwkew";
    int len = lengthOfLongestSubstring(s);
    printf( "len : %d ", len );
}
