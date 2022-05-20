// problem link https://leetcode.com/problems/reverse-words-in-a-string/

/*
brute: use stack and store the words and then pop that words

optimal:
1. maintain two pointers i and j
2. i will be at the starting of word and j will be at the ending of the string
3. remove the whitespaces
*/

class Solution{
public:
    string reverseWords(string s){

        int i=s.length()-1;

        string ans="";

        while(i>=0){

            while(i>=0 and s[i] == ' ') i--;

            if(i<0) break;

            int j=i;

            while(i>=0 and s[i] != ' ') i--;

            if(ans == ""){
                ans += s.substr(i+1, j-i);
            }
            else{
                ans += " " + s.substr(i+1, j-i);
            }
        }

        return ans;
    }
};