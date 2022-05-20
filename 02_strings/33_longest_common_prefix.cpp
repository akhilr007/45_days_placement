// problem link https://leetcode.com/problems/longest-common-prefix/

/*
brute: 
1. sort the string array
2. since the array is sorted we can check for the first and last words
3. if it matches increase a counter otherwise break
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(), strs.end());

        int n = strs.size();
        string first = strs[0];
        string last = strs[n-1];

        int c=0;
        while(c < first.length()){

            if(first[c] == last[c]){
                c++;
            }
            else{
                break;
            }
        }

        return c==0? "" : first.substr(0, c);
    }
};