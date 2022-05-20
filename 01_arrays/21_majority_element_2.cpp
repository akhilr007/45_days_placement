// problem link https://leetcode.com/problems/majority-element-ii/

// the majority element can atmost be 2 if > n/3

class Solution{
public:
    vector<int> majorityElement(vector<int>& nums){

        int c1=0; // count of 1st majority element
        int c2=0; // count of 2nd majority element

        int e1=-1; // first majority element
        int e2=-1; // second majority element

        for(int i=0; i<nums.size(); i++){

            if(nums[i] == e1){
                c1++;
            }

            else if(nums[i] == e2){
                c2++;
            }

            else if(c1 == 0){
                e1=nums[i];
                c1++;
            }

            else if(c2 == 0){
                e2=nums[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }

        c1=0;
        c2=0;
        for(auto val : nums){
            if(val == e1) c1++;
            else if(val == e2) c2++;
        }

        int n=nums.size();
        vector<int> ans;
        if(c1>n/3) ans.push_back(e1);
        if(c2>n/3) ans.push_back(e2);

        return ans;
    }
}