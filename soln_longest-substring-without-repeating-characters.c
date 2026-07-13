/*
question link : http://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=problem-list-v2&envId=we37i0vg
*/


#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s) {
    int visited[256] = {0};
    int stringLength = ( sizeof(s) )/( sizeof(*s) );
    //add print statements to check values stored in variables
    printf( "stringLength : %d \n", stringLength );
    int start = 0, end = start;
    for( int i=0; i<stringLength; i++ ){
        if( visited[ s[i] ] == 0 ){
            end = end + 1;
            visited[ s[i] ] = 1; 
        }
        else{
            start = i;
            end = i;
        }
        //add print statements to track values of start and end
        //problem : if a visited cahharacter is found, start resets again without storing previous values
        printf( " i = %d, start = %d, end = %d \n", i, start, end );
    }
    char* result = calloc( end-start, sizeof(char) );
    result = s+start;
    printf( " %d -> %s -> %d\n", start, result, end ) ;
    return end-start ;
}

int main(){
    char *s = "abcabcbb";
    int len = lengthOfLongestSubstring(s);
    printf( "len : %d ", len );
}
