// problem link https://leetcode.com/problems/maximum-product-of-three-numbers/

/*
1. approach
sort the array and multiply the last three numbers or first two numbers and last number

2. optimal
find the 3 maximum numbers
find the 2 min numbers 
max of(2min*1max , 3max)
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int min1=INT_MAX;
        int min2=INT_MAX;

        for(int i=0; i<nums.size(); i++){

            if(nums[i] < min1){
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i] < min2){
                min2 = nums[i];
            }
        }

        int max1=INT_MIN;
        int max2=INT_MIN;
        int max3=INT_MIN;

        for(int i=0; i<nums.size(); i++){

            if(nums[i] > max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2){
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i] > max3){
                max3 = nums[i];
            }
        }

        int p1 = min1*min2*max1;
        int p2 = max1*max2*max3;

        return max(p1, p2);

    }
};