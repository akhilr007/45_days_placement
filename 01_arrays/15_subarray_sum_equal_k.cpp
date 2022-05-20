// problem link https://leetcode.com/problems/subarray-sum-equals-k/

/*
brute: use two loops and find the ans

optimal: use hashmap
1. always put m[0] = 1 because if k=5 and arr={3, 2} so sum-k=0 will be 0 and 0 should be present in map
2. calculate sum and find (sum-k) in map
3. if found, add ans += m[sum-k];
4. now increment sum to map m[sum]++;
*/

class Solution{
public:
    int subarraySum(vector<int>& nums, int k){

        unordered_map<int, int> m;
        m[0] = 1;

        int sum=0;
        int count=0;

        for(int i=0; i<nums.size(); i++){

            sum += nums[i];

            if(m.find(sum-k) != m.end()){
                count += m[sum-k];
            }

            m[sum]++;
        }

        return count;

    }
};