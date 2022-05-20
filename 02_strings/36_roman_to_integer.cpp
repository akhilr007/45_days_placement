// problem link https://leetcode.com/problems/roman-to-integer/

/*
approach:

1. create map of roman to integer values 
2. check if the current char is lesser than previous char then simply add the map value
3. if not, then app the current map value to it and subtract 2*m[prev] value;
*/

class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int result =0;

        for(int i=0; i<s.length(); i++){

            if(i>0 and m[s[i]] > m[s[i-1]]){
                result += m[s[i]] - 2*m[s[i-1]];
            }
            else{
                result += m[s[i]];
            }
        }

        return result;
    }
};