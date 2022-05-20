// problem link https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

/*
brute force:
1. all the combinations like pick k from start or pick k from end
2. pick k-1 from start and pick n-k-1 from end
time complexity will be O(k*k)

optimal:
1. use sliding window
2. calculate sum from end of k.
3. then add one element from start and remove one element from end and compare the max result we can get
*/

class Solution{
public:
    int maxScore(vector<int>& cardPoints, int k){

        int len = cardPoints.size();

        int l=0;
        int r=len-k;

        int total=0;
        for(int i=r; i<len; i++){
            total += cardPoints[i];
        }

        int res=total;

        while(r<len){
            total += cardPoints[l] - cardPoints[r];
            res = max(res, total);
            l++;
            r++;
        }

        return res;
    }
}