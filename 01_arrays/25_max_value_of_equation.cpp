// problem link https://leetcode.com/problems/max-value-of-equation/

/*
approach:

1. we have to find the eqn (yi + yj) + |xi - xj|
2. since the x-points are sorted therefore |xi - xj| can be written as xj - xi since i<j.
3. therefore eqn can be written as (yi + yj) + (xj - xi).
4. which can be again written as (yj + xj) + (yi - xi).
5. thus we can calculate the max value of (yi-xi) using priority queue.
6. and we can match the condition using xi - xi-1 <= k
*/

class Solution{
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k){

        priority_queue<pair<int, int>> pq; // yi-xi, xi
        int ans=INT_MIN;

        for(int i=0; i<points.size(); i++){

            // checking the condition using xj - xi <= k
            while(pq.size()>0 and (points[i][0] - pq.top().second > k)){
                pq.pop();
            }

            if(pq.size()>0){

                int yj = points[i][1];
                int xj = points[i][0];
                int yi_xi = pq.top().first;

                ans = max(ans, (yj + xj + yi_xi));
            }

            int yi = points[i][1];
            int xi = points[i][0];

            pq.push({yi-xi, xi});
        }

        return ans;
    }
};