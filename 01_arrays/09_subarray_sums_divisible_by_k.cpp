// problem link:- https://leetcode.com/problems/subarray-sums-divisible-by-k/

/*
brute - generate all subarrays and find sum which is divisible by k

optimal - use hashmap 
1. calculate sum and find rem
2. store rem as key and freq as mapping
3. if rem is -ve then add +k to it
4. if again rem is found in map then add the freq to our answer
5. why?
6. suppose kn + x is divisble by k and km + x is divisible by k
7. s1 = kn + x and s2 = km + x
8. s2-s1 = km-kn = k(m-n);
9. so s2-s1 is also divisible by k
*/

class Solution{
public:
    int subarraysDivByK(vector<int>& nums, int k){

        unordered_map<int, int> m;
        m[0] = 1;

        int sum=0;
        int ans=0;

        for(int i=0; i<nums.size(); i++){

            sum += nums[i];
            int rem = sum % k;

            if(rem < 0){
                rem += k;
            }

            if(m.find(rem) != m.end()){
                ans += m[rem];
                m[rem]++;
            }
            else{
                m[rem]=1;
            }
        }

        return ans;
    }
};