// problem link https://leetcode.com/problems/happy-number/

class Solution{
public:
    bool isHappy(int n){

        unordered_set<int> s;

        int val;
        int digit;

        while(true){

            val=0;
            while(n != 0){

                digit = n%10;
                val += digit*digit;
                n /= 10;
            }

            if(val == 1) return true;
            if(s.find(val) != s.end()) return false;

            s.insert(val);
            n = val;
        }

        return false;
    }
};