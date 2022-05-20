// problem link https://leetcode.com/problems/find-all-duplicates-in-an-array/

/*
brute force: sort the array and traverse and find out

optimal: take out the index from the given element in array 
for eg: 4 3 4 1
for 4 : index will be abs(nums[0])-1 ,i.e, 4-1 = 3
so at index 3 mark the element to be negative 

for 3 mark the element at index 2 to be negative

for 4 mark the element at index 3 to be negative but the element at index 3 is already marked as -ve so the
given number i.e, index + 1 is duplicate.
*/

class Solution{
public:
    vector<int> findDuplicates(vector<int>& nums){

        vector<int> res;

        for(int i=0; i<nums.size(); i++){

            int idx = abs(nums[i])-1;
            int val = nums[idx];

            if(val < 0){
                res.push_back(idx+1);
            }
            else{
                nums[idx] = -nums[idx];
            }
        }

        return res;
    }
}