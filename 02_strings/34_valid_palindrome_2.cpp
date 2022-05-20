// problem link https://leetcode.com/problems/valid-palindrome-ii/

class Solution {
public:
    bool isPalindrome(stirng& s, int i, int j){
        
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;

    }

    bool validPalindrome(string s) {
        
        int i=0;
        int j=s.length()-1;

        while(i<j){

            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                if(isPalindrome(s, i, j-1) == true or isPalindrome(s, i+1, j) == true){
                    return true;
                }
                else return false;
            }
        }

        return true;
    }
};