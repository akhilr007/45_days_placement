// problem link https://leetcode.com/problems/generate-parentheses/

/*
approach:

1. if n=3, then there will be 3 open brackets and 3 close brackets
2. if open != 0 and open == close, then we only have the option to include open bracket (.
3. if open < close then we have two options ( and ).
*/

class Solution{
public:
    void helperUtil(string op, int open, int close, vector<string>& ans){

        if(open ==0 and close == 0){
            ans.push_back(op);
            return;
        }

        if(open != 0){
            helperUtil(op + "(", open-1, close, ans);
        }
        if(close > open){
            helperUtil(op + ")", open, close-1, ans);
        }
        return;
    }

    vector<string> generateParanthesis(int n){

        vector<int> ans;
        int open=n, close=n;
        helperUtil("", open, close, ans);
        return ans;
    }
}