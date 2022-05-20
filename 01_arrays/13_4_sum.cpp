// problem link https://leetcode.com/problems/4sum/

class Solution {
public:

    vector<vector<int>> twoSum(vector<int>& nums, int si, int target){

        int i=si;
        int j=nums.size()-1;

        vector<vector<int>> ans;

        while(i<j){

            if(i != si and nums[i] == nums[i-1]){
                i++;
                continue;
            }

            if(nums[i] + nums[j] == target){
                vector<int> res;
                res.push_back(nums[i]);
                res.push_back(nums[j]);
                ans.push_back(res);

                i++;
                j--;
            }

            else if(nums[i] + nums[j] > target){
                j--;
            }

            else i++;
        }

        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int si, int target){

        vector<vector<int>> ans;

        int i=si;

        for(int i=si; i<nums.size()-2; i++){

            if(i != si and nums[i] == nums[i-1]){
                continue;
            }

            vector<vector<int>> res = twoSum(nums, i+1, target-nums[i]);

            for(vector<int> v : res){
                v.insert(v.begin(), nums[i]);
                ans.push_back(v);
            }
        }

        return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();

        vector<vector<int>> ans;

        if(n==0 || n==1 || n==2 || n==3) return ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n-3; i++){

            if(i != 0 and nums[i] == nums[i-1]){
                continue;
            }

            vector<vector<int>> res = threeSum(nums, i+1, target-nums[i]);

            for(vector<int> v : res){
                v.insert(v.begin(), nums[i]);
                ans.push_back(v);
            }
        }

        return ans;
    }
};