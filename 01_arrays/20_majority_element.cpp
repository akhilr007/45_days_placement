// problem link https://leetcode.com/problems/majority-element/

/*
brute : use hashmap

optimal : moore voting algorithm
1. if count is 0, and you encounter a new element
2. make that as majority element and increase the count to 1
3. if again you encounter the same element increase the count
4. if not then reduce the count
5. at the end, check the majority element if its count is greater then n/2
*/

class Solution{
public:
    int majorityElement(vector<int>& nums){

        int count=0;
        int majorityElement=-1;

        for(int i=0; i<nums.size(); i++){

            if(count == 0){
                majorityElement = nums[i];
                count = 1;
            }
            else if(majorityElement == nums[i]){
                count++;
            }
            else if(majorityElement != nums[i]){
                count--;
            }
        }

        count =0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == majorityElement){
                count++;
            }
        }

        if(count > nums.size()/2) return majorityElement;
        else return -1;
    }
}