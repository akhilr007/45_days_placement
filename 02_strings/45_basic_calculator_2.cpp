// problem link https://leetcode.com/problems/basic-calculator-ii/

/*
approach:

1. if the char is digit then push it to stack
2. if the operator sign is +ve then push +ve val and if not then push -ve val
3. if the operator is * or / then calculate the val and push to stack
*/

class Solution{
public:
    int calculate(string s){

        int val=0;
        stack<int> st;
        char sign = '+';

        for(int i=0; i<s.length(); i++){

            if(isdigit(s[i])){
                val = val*10 + (s[i]-'0');
            }

            if(!isdigit(s[i]) && !isspace(s[i]) || i == s.length()-1){

                if(sign == '+'){
                    st.push(val);
                }

                else if(sign == '-'){
                    st.push(-val);
                }

                else{

                    int num;

                    if(sign == '*'){
                        num = st.top() * val;
                    }
                    else{
                        num = st.top() / val;
                    }

                    st.pop();
                    st.push(num);
                }

                sign = s[i];
                val = 0;
            }

            int res=0;
            while(st.size()>0){
                res += st.top();
                st.pop();
            }

            return res;

        }
    }
};