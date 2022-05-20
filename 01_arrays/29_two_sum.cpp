// problem link https://leetcode.com/problems/two-sum/

/*
brute using two loops

better sort the array and using two pointer at 0 and n-1 respectively

optimal using hashmap
*/

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){

        unordered_map<int, int> m;

        vector<int> ans;

        for(int i=0; i<nums.size(); i++){

            int val = target - nums[i];
            if(m.find(val) != m.end()){
                ans.push_back(m[val]);
                ans.push_back(i);
                break;
            }

            m[nums[i]] = i;

        }

        return ans;
    }
}