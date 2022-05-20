// problem link https://leetcode.com/problems/jump-game/

/*
brute : use recursion and backtracking you can use memoization and dp

optimal: use projectile motion concept

NOTE: if the array doesnt have any zero then the result will be always true

1. from each element how far can we go
2. maintain a reachable counter which tells till how much can we go for(at the max index we can go from a 
particular index).
3. if my reachable pointer get smaller than i then we cant reach the end point
4. we can calculate reachable pointer by using max(reachable, i+nums[i]);

eg:
[2,3,1,1,4]

reachable will always start with 0

r=0
i=0; r is not less than i
calculate r: r=max(r, i+nums[i]) => r=max(0, 0+2) => r=2
thus from 0 we can reach till 2nd index.

now
i=1; r=2 is not less than i
calculate r: r=max(r, i+nums[i]) => r=max(2, 1+3) => r=4
thus from 3 we can reach till 4th index which is our ending point


*/

class Solution{
public:
    bool canJump(vector<int>& nums){

        int reachable=0;

        for(int i=0; i<nums.size(); i++){

            if(reachable < i) return false;

            reachable = max(reachable, i+nums[i]);
        }
        return true;
    }
};