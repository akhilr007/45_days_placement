// problem link https://practice.geeksforgeeks.org/problems/word-wrap1646/1#

/*
using recursion:
suppose k = 11, and nums[i] = 7
then we can place 7 into it and 1 place for putting spaces b/w two words


suppose nums[i] = 7 and remaining = 4
1. if my nums[i] < remaining places to fill
->  then we cant place 7 into the remaining blanks so we need to go to the next line
so my cost will be (rem+1)*(rem+1) + f(i+1, k-nums[i]-1, nums, k);

2. if my nums[i] == remaining places to fill
-> then we can put the word on the same line or we can go to the next line
min(f(i+1, k, nums, k), f(i+1, k-nums[i]-1, nums, k));

3. if my nums[i] < remaining places to fill
-> then we can put the word on the same line or we can go to the next line
min(f(i+1, rem - nums[i]- 1, nums, k), (num+1)*(num+1) + f(i+1, k-nums[i]-1, nums, k))
*/

class Solution{
public:
    int f(int i, int rem, vector<int>& nums, int& k, vector<vector<int>>& dp){

        if(i == nums.size()) return 0;

        if(dp[i][rem] != -1){
            return dp[i][rem];
        }

        int cost;

        if(nums[i] > rem){
            // then my cost will be calculate by the spaces we have left before coming onto the next line
            // so rem was space available and 1 will be considered for the space we left after filling the
            // word

            // and the remaining will be the spaces left after putting nums[i] onto the line and add 1 for spacebar
            // and if k-nums[i]-1<0 then put 0 
            // suppose for eg : k = 5 and nums[i] = 5 and rem = 3 so k-nums[i]-1 will be -ve so put 0
            // because k-nums[i] will be 0

            cost = (rem+1)*(rem+1) + f(i+1, k-nums[i]-1 < 0 ? 0 : k-nums[i]-1, nums, k, dp);
        }

        else if(nums[i] == rem){

            // if we have exact remaining place left for nums[i]
            // then we can place that num[i] onto the same line or can go to the next line
            // but no cost will be taken 
            // since if we put put the nums[i] on to the same line then my remaining space will be 0 so 
            // my next available space will be k

            int choice1 = f(i+1, k, nums, k, dp);
            int choice2 = (rem+1)*(rem+1) + f(i+1, k-nums[i]-1, nums, k, dp);
            cost = min(choice1, choice2);
        }

        else{
            // if my nums[i] < remaining spaces then we have two choices
            // 1. put that word on the same line -> then my remaining will be reduced from rem
            // 2. put that word on the next line -> then my remaining will be reduced from k
            int choice1 = f(i+1, rem-nums[i]-1, nums, k, dp);
            int choice2 = (rem+1)*(rem+1) + f(i+1, k-nums[i]-1, nums, k, dp);
            cost = min(choice1, choice2);
        }

        return dp[i][rem] = cost;
    }

    int solveWordWrap(vector<int>& nums, int k){

        int rem=k;
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return f(0, rem, nums, k, dp);

    }
};