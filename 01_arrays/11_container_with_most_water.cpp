// problem link https://leetcode.com/problems/container-with-most-water/

/*
brute: use two loops and find out the max area of container
for one element traverse all the heights and keep track of the maximum area

optimal: use two pointers technique
1. keep one pointer at 0th index and another at n-1 index
2. now calculate the width b/w them (j-i) and multiply it with smaller height b/w h[i] and h[j]
3. so that will be the max area b/w them so element with smaller height move one step ahead or backward
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i=0;
        int j=height.size()-1;

        int maximumArea=0;

        while(i<j){

            int width = j-i;
            int h = min(height[i], height[j]);

            int currArea = h * width;

            maximumArea = max(currArea, maximumArea);

            if(height[i] < height[j]) i++;
            else j--;
        }

        return maximumArea;
    }
};