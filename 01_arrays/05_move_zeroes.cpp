// problem link https://leetcode.com/problems/move-zeroes/

class Solution{
public:
    int moveZeroes(vector<int>& nums){

        int n=nums.size();
        int j=0;

        for(int i=0; i<n-1; i++){
            if(nums[i] != nums[i+1]){
                nums[j++] = nums[i];
            }
        }

        nums[j++] = nums[n-1];
        return j;
    }
}