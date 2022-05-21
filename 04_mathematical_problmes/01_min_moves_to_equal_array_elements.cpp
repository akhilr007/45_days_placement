// problem link https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

/*
approach: 
1. to calculate min moves to make all elements equal 
2. we need to increase all the elements except max element in the array
3. so, if we reduce the diff b/w min and max element to 0 then we have solved the question
4. so basically, find the sum of diff b/w all the elements and min element.
*/

class Solution{
public:
    int minMoves(vector<int>& nums){
        
        int mini=nums[0];
        for(int i=0; i<nums.size(); i++){
            mini = min(mini, nums[i]);
        }

        int minMoves=0;
        for(int i=0; i<nums.size(); i++){
            minMoves += nums[i]-mini;
        }

        return minMoves;

    }
}