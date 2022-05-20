// problem link:- https://leetcode.com/problems/sort-colors/

/*
0 to j-1 -> 0's
j to i-1 -> 1's
k+1 to n-1 -> 2's

*/

void sortColors(vector<int>& nums){

    int n=nums.size()-1;

    int i=0;
    int j=0;
    int k=n-1;

    while(i<=k){

        if(nums[i]==0){
            swap(nums[i], nums[j]);
            i++;
            j++;
        }
        else if(nums[i] == 1){
            i++;
        }
        else if(nums[i] == 2){
            swap(nums[i], nums[k]);
            k--;
        }
    }
}