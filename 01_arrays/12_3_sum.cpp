// problem link https://leetcode.com/problems/3sum/

class Solution {
public:

    vector<vector<int>> twoSum(vector<int>& nums, int si, int target){

        int i=si;
        int j=nums.size()-1;

        vector<vector<int>> res;

        while(i<j){

            if(i != si && nums[i] == nums[i-1]){
                i++;
                continue;
            }

            if(nums[i] + nums[j] == target){
                vector<int> ans;
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                res.push_back(ans);

                i++;
                j--;
            }

            else if(nums[i] + nums[j] > target){
                j--;
            }

            else{
                i++;
            }
        }

        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;

        int n=nums.size();

        if(n==0 || n==1 || n==2) return ans;

        sort(nums.begin(), nums.end());
        int target=0;

        for(int i=0; i<n-2; i++){

            if(i != 0 and nums[i] == nums[i-1]){
                continue;
            }

            vector<vector<int>> res = twoSum(nums, i+1, target - nums[i]);

            for(vector<int> v : res){
                v.insert(v.begin(), nums[i]);
                ans.push_back(v);
            }
        }

        return ans;
    }
};