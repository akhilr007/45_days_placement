// problem link: https://leetcode.com/problems/valid-parentheses/

/*
use stack
*/

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for(int i=0; i<s.length(); i++){

            char ch = s[i];

            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else if(ch == ')' || ch == ']' || ch == '}'){

                if(ch == ')'){
                    if(st.size() == 0 || st.top() != '('){
                        return false;
                    }
                }
                else if(ch == '}'){
                    if(st.size() == 0 || st.top() != '{'){
                        return false;
                    }
                }
                if(ch == ']'){
                    if(st.size() == 0 || st.top() != '['){
                        return false;
                    }
                }
                st.pop();
            }
        }

        if(st.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
};