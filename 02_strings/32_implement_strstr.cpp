// problem link https://leetcode.com/problems/implement-strstr/

/*
brute force: O((n-m+1)*m)

using naive pattern seach search the pattern substring in the text substring
*/

// naive pattern searching
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.length();
        int m = needle.length();

        if(m == 0) return 0;

        for(int i=0; i<=n-m; i++){
            int j;
            for(j=0; j<m; j++){
                if(haystack[i+j] != needle[j]){
                    break;
                }
            }

            if(j == m){
                return i;
            }
        }

        return -1;
        
    }
};